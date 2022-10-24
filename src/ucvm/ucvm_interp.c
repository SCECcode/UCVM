#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ucvm_utils.h"
#include "ucvm_interp.h"

/* Ely interp coefficients */
double ucvm_interp_ely_a = 0.5;
double ucvm_interp_ely_b = 0.66666666666;
double ucvm_interp_ely_c = 1.5;

double taper_zmax=700.0;

/* Ely interpolation method */
int ucvm_interp_ely(double zmin, double zmax, ucvm_ctype_t cmode,
		    ucvm_point_t *pnt, ucvm_data_t *data)
{
  double z, f, g;

  switch (cmode) {
  case UCVM_COORD_GEO_DEPTH:
  case UCVM_COORD_GEO_ELEV:
    break;
  default:
    fprintf(stderr, "Unsupported coord type\n");
    return(UCVM_CODE_ERROR);
    break;
  }

  if (data->depth < 0.0) {
    return(UCVM_CODE_NODATA);
  }

  if (data->depth < zmin) {
    /* Point lies fully in GTL */
    /* Check that gtl vs is defined */
    if (data->gtl.vs <= 0.0) {
      return(UCVM_CODE_NODATA);
    }
    /* Apply a coefficient to convert vs30 to vs */
    data->cmb.vs = ucvm_interp_ely_a * data->gtl.vs;
    data->cmb.vp = ucvm_interp_ely_a * ucvm_brocher_vp(data->gtl.vs);
    data->cmb.rho = ucvm_nafe_drake_rho(data->cmb.vp);
    data->cmb.source = UCVM_SOURCE_GTL;
  } else if (data->depth >= zmax) {
    /* Point lies fully in crustal */
    data->cmb.vp = data->crust.vp;
    data->cmb.vs = data->crust.vs;
    data->cmb.rho = data->crust.rho;
    data->cmb.source = UCVM_SOURCE_CRUST;
  } else {
    /* Point lies in gtl/crustal interpolation zone */
    data->cmb.source = data->gtl.source;

    /* Check that all crust properties and gtl vs are defined */
    if ((data->crust.vp <= 0.0) || (data->crust.vs <= 0.0) || 
	(data->crust.rho <= 0.0) || (data->gtl.vs <= 0.0)) {
      return(UCVM_CODE_NODATA);
    }

    z = (data->depth - zmin) / (zmax - zmin);
    f = z - pow(z, 2.0);
    g = pow(z, 2.0) + 2*pow(z, 0.5) - 3*z;
    data->cmb.vs = (z + ucvm_interp_ely_b*f)*(data->crust.vs) + 
      (ucvm_interp_ely_a - ucvm_interp_ely_a*z + 
       ucvm_interp_ely_c*g)*data->gtl.vs;
    data->cmb.vp = (z + ucvm_interp_ely_b*f)*(data->crust.vp) + 
      (ucvm_interp_ely_a - ucvm_interp_ely_a*z + 
       ucvm_interp_ely_c*g)*ucvm_brocher_vp(data->gtl.vs);
    data->cmb.rho = ucvm_nafe_drake_rho(data->cmb.vp);
  }

  return(UCVM_CODE_SUCCESS);
}


/* Taper interpolation method, intended for zmin-zmax tapered interp 
 * on crustal */
int ucvm_interp_taper(double zmin, double zmax, ucvm_ctype_t cmode,
		    ucvm_point_t *pnt, ucvm_data_t *data)
{
  double z, f, g;

  switch (cmode) {
  case UCVM_COORD_GEO_DEPTH:
  case UCVM_COORD_GEO_ELEV:
    break;
  default:
    fprintf(stderr, "Unsupported coord type\n");
    return(UCVM_CODE_ERROR);
    break;
  }

  if (data->depth < 0.0) {
    return(UCVM_CODE_NODATA);
  }

  /* preset all to be in crustal */
  data->cmb.vs = data->crust.vs;
  data->cmb.vp = data->crust.vp;
  data->cmb.rho = data->crust.rho;
  data->cmb.source = UCVM_SOURCE_CRUST;

  if (data->depth >= zmin && data->depth <=taper_zmax) {
    /* Point lies in gtl/crustal interpolation zone */
    data->cmb.source = data->gtl.source;

    /* Check that all crust properties and gtl vs are defined */
    if ((data->crust.vp <= 0.0) || (data->crust.vs <= 0.0) || 
                (data->crust.rho <= 0.0) || (data->gtl.vs <= 0.0)) {
      return(UCVM_CODE_NODATA);
    }

    z = (data->depth - zmin) / (taper_zmax - zmin);
    f = z - pow(z, 2.0);
    g = pow(z, 2.0) + 2*pow(z, 0.5) - 3*z;
    double taper_data_cmb_vs = (z + ucvm_interp_ely_b*f)*(data->crust.vs) + 
        (ucvm_interp_ely_a - ucvm_interp_ely_a*z + 
         ucvm_interp_ely_c*g)*data->gtl.vs;
    double taper_data_cmb_vp = (z + ucvm_interp_ely_b*f)*(data->crust.vp) + 
        (ucvm_interp_ely_a - ucvm_interp_ely_a*z + 
         ucvm_interp_ely_c*g)*ucvm_brocher_vp(data->gtl.vs);
    double taper_data_cmb_rho = ucvm_nafe_drake_rho(taper_data_cmb_vp);
  
    if( taper_data_cmb_vs < data->crust.vs ) { data->cmb.vs = taper_data_cmb_vs;}
    if( taper_data_cmb_vp < data->crust.vp ) {
	     data->cmb.vp = taper_data_cmb_vp;
	     data->cmb.rho = taper_data_cmb_rho;
    }
  }

  if(data->cmb.vs < 500) {data->cmb.vs=500; } 
  if(data->cmb.vp < 1700) {data->cmb.vp=1700; } 
  if(data->cmb.rho < 1700) {data->cmb.rho=1700; } 

  return(UCVM_CODE_SUCCESS);
}


/* ely+Taper interpolation method, intended for 
 * zmin-350 ely+taper,
 * 350-700+ ely 
 * on crustal */
int ucvm_interp_elytaper(double zmin, double zmax, ucvm_ctype_t cmode,
		    ucvm_point_t *pnt, ucvm_data_t *data)
{
  double z, f, g;

  switch (cmode) {
  case UCVM_COORD_GEO_DEPTH:
  case UCVM_COORD_GEO_ELEV:
    break;
  default:
    fprintf(stderr, "Unsupported coord type\n");
    return(UCVM_CODE_ERROR);
    break;
  }

  if (data->depth < 0.0) {
    return(UCVM_CODE_NODATA);
  }

  if (data->depth <= zmin) {
    /* Point lies fully in GTL */
    /* Check that gtl vs is defined */
    if (data->gtl.vs <= 0.0) {
      return(UCVM_CODE_NODATA);
    }
    /* Apply a coefficient to convert vs30 to vs */
    data->cmb.vs = ucvm_interp_ely_a * data->gtl.vs;
    data->cmb.vp = ucvm_interp_ely_a * ucvm_brocher_vp(data->gtl.vs);
    data->cmb.rho = ucvm_nafe_drake_rho(data->cmb.vp);
    data->cmb.source = UCVM_SOURCE_GTL;
  } else { 
    // 3 ranges:  zmin:zmax, zmax:taper_zmax, taper_zmax:all 
    if (data->depth > taper_zmax) {

    /* Point lies fully in crustal */
    data->cmb.vs = data->crust.vs;
    data->cmb.vp = data->crust.vp;
    data->cmb.rho = data->crust.rho;
    data->cmb.source = UCVM_SOURCE_CRUST;

    } else { /* Point lies in gtl/crustal interpolation zone */
	     /* 2 regions */
      data->cmb.source = data->gtl.source;

      /* Check that all crust properties and gtl vs are defined */
      if ((data->crust.vp <= 0.0) || (data->crust.vs <= 0.0) || 
	  (data->crust.rho <= 0.0) || (data->gtl.vs <= 0.0)) {
        return(UCVM_CODE_NODATA);
      }

      z = (data->depth - zmin) / (taper_zmax - zmin);
      f = z - pow(z, 2.0);
      g = pow(z, 2.0) + 2*pow(z, 0.5) - 3*z;
      double taper_data_cmb_vs = (z + ucvm_interp_ely_b*f)*(data->crust.vs) +
        (ucvm_interp_ely_a - ucvm_interp_ely_a*z +
         ucvm_interp_ely_c*g)*data->gtl.vs;
      double taper_data_cmb_vp = (z + ucvm_interp_ely_b*f)*(data->crust.vp) +
        (ucvm_interp_ely_a - ucvm_interp_ely_a*z +
         ucvm_interp_ely_c*g)*ucvm_brocher_vp(data->gtl.vs);
      double taper_data_cmb_rho = ucvm_nafe_drake_rho(taper_data_cmb_vp);

      if(data->depth <= zmax) {

        z = (data->depth - zmin) / (zmax - zmin);
        f = z - pow(z, 2.0);
        g = pow(z, 2.0) + 2*pow(z, 0.5) - 3*z;
        data->cmb.vs = (z + ucvm_interp_ely_b*f)*(data->crust.vs) + 
          (ucvm_interp_ely_a - ucvm_interp_ely_a*z + 
           ucvm_interp_ely_c*g)*data->gtl.vs;
        data->cmb.vp = (z + ucvm_interp_ely_b*f)*(data->crust.vp) + 
          (ucvm_interp_ely_a - ucvm_interp_ely_a*z + 
           ucvm_interp_ely_c*g)*ucvm_brocher_vp(data->gtl.vs);
        data->cmb.rho = ucvm_nafe_drake_rho(data->cmb.vp);

        if(taper_data_cmb_vs < data->cmb.vs) {
          data->cmb.vs = taper_data_cmb_vs;
          data->cmb.vp = taper_data_cmb_vp;
          data->cmb.rho = taper_data_cmb_rho;
        }
        } else {
          data->cmb.vs = taper_data_cmb_vs;
          data->cmb.vp = taper_data_cmb_vp;
          data->cmb.rho = taper_data_cmb_rho;
      }

      if(data->cmb.vs < 500) { data->cmb.vs = 500;}
      if(data->cmb.vp < 1700) { data->cmb.vp = 1700;}
      if(data->cmb.rho < 1700) { data->cmb.rho = 1700;}
    }
  }
  return(UCVM_CODE_SUCCESS);
}



/* Linear interpolation method */
int ucvm_interp_linear(double zmin, double zmax, ucvm_ctype_t cmode,
		       ucvm_point_t *pnt, ucvm_data_t *data)
{
  double zratio;

  switch (cmode) {
  case UCVM_COORD_GEO_DEPTH:
  case UCVM_COORD_GEO_ELEV:
    break;
  default:
    fprintf(stderr, "Unsupported coord type\n");
    return(UCVM_CODE_ERROR);
    break;
  }

  if (data->depth < 0.0) {
    return(UCVM_CODE_NODATA);
  }

  if (data->depth < zmin) {
    data->cmb.vs = data->gtl.vs;
    data->cmb.vp = data->gtl.vp;
    data->cmb.rho = data->gtl.rho;
    data->cmb.source = UCVM_SOURCE_GTL;
  } else if ((data->depth >= zmin) && (data->depth < zmax)) {
    /* Point lies in gtl/crustal interpolation zone */
    data->cmb.source = data->gtl.source;

    /** MEI
    if ((data->crust.vp <= 0.0) || (data->crust.vs <= 0.0) || 
	(data->crust.rho <= 0.0) || (data->gtl.vp <= 0.0) || 
	(data->gtl.vs <= 0.0) || (data->gtl.rho <= 0.0)) {
      return(UCVM_CODE_NODATA);
    }
    **/

    zratio = (data->depth - zmin) / (zmax - zmin);
    if(data->gtl.vp > 0.0 && data->crust.vp > 0.0) {
      data->cmb.vp = interpolate_linear(data->gtl.vp, 
				      data->crust.vp, zratio);
    }
    if(data->gtl.vs > 0.0 && data->crust.vs > 0.0) {
      data->cmb.vs = interpolate_linear(data->gtl.vs, 
				      data->crust.vs, zratio);
    }
    if(data->gtl.rho > 0.0 && data->crust.rho > 0.0) {
      data->cmb.rho = interpolate_linear(data->gtl.rho, 
				       data->crust.rho, zratio);
    } 
  } else {
    data->cmb.vp = data->crust.vp;
    data->cmb.vs = data->crust.vs;
    data->cmb.rho = data->crust.rho;
    data->cmb.source = UCVM_SOURCE_CRUST;
  }

  return(UCVM_CODE_SUCCESS);
}


/* Crustal pass-through method */
int ucvm_interp_crustal(double zmin, double zmax, ucvm_ctype_t cmode,
			ucvm_point_t *pnt, ucvm_data_t *data)
{
  data->cmb.vp = data->crust.vp;
  data->cmb.vs = data->crust.vs;
  data->cmb.rho = data->crust.rho;
  data->cmb.source = UCVM_SOURCE_CRUST;

  return(UCVM_CODE_SUCCESS);
}
