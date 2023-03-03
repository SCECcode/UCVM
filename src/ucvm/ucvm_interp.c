#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ucvm_utils.h"
#include "ucvm_interp.h"

/* Ely interp coefficients */
double ucvm_interp_ely_a = 0.5;
double ucvm_interp_ely_b = 0.66666666666;
double ucvm_interp_ely_c = 1.5;

extern double ucvm_interp_vs_floor;
extern double ucvm_interp_vp_floor;
extern double ucvm_interp_density_floor;

int JUST_TAPER=0;
int taper1_cnt=0;
int taper2_cnt=0;
int taper3_cnt=0;
int taper4_cnt=0;

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

/* Taper interpolation method */
int ucvm_interp_taper(double zmin, double zmax, ucvm_ctype_t cmode,
		    ucvm_point_t *pnt, ucvm_data_t *data)
{
  double z, f, g;
//  fprintf(stderr,"XXX callin interp for data depth %lf\n", data->depth);

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
  } else if (data->depth > zmax) {
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
    double taper_data_cmb_vs = (z + ucvm_interp_ely_b*f)*(data->crust.vs) + 
      (ucvm_interp_ely_a - ucvm_interp_ely_a*z + 
       ucvm_interp_ely_c*g)*data->gtl.vs;
    double taper_data_cmb_vp = (z + ucvm_interp_ely_b*f)*(data->crust.vp) + 
      (ucvm_interp_ely_a - ucvm_interp_ely_a*z + 
       ucvm_interp_ely_c*g)*ucvm_brocher_vp(data->gtl.vs);
    double taper_data_cmb_rho = ucvm_nafe_drake_rho(taper_data_cmb_vp);


//fprintf(stderr,"XXX crust/taper %lf > %lf \n", data->interp_crust.vs , taper_data_cmb_vs);

    if(data->interp_crust.vs < taper_data_cmb_vs) {
      data->cmb.vs = data->interp_crust.vs;
      data->cmb.vp = data->interp_crust.vp;
      data->cmb.rho = data->interp_crust.rho;
      } else {
        data->cmb.vs = taper_data_cmb_vs;
        data->cmb.vp = taper_data_cmb_vp;
        data->cmb.rho = taper_data_cmb_rho;
    }

    if(JUST_TAPER) {
        data->cmb.vs = taper_data_cmb_vs;
        data->cmb.vp = taper_data_cmb_vp;
        data->cmb.rho = taper_data_cmb_rho;
    }

  }

  double ratio = data->cmb.vp / data->cmb.vs;
  if(ucvm_interp_vs_floor != UCVM_DEFAULT_NULL_FLOOR && 
		  data->cmb.vs < ucvm_interp_vs_floor) 
    {  data->cmb.vs= ucvm_interp_vs_floor ; }
  if(ucvm_interp_vp_floor != UCVM_DEFAULT_NULL_FLOOR && 
		  data->cmb.vp < ucvm_interp_vp_floor)
    { data->cmb.vp= ucvm_interp_vp_floor ; }
  if(ucvm_interp_density_floor != UCVM_DEFAULT_NULL_FLOOR && 
		  data->cmb.rho < ucvm_interp_density_floor) 
    { data->cmb.rho= ucvm_interp_density_floor ; }

  if( ratio < 1.45 )
    { taper1_cnt=taper1_cnt+1; } 

  if( (data->cmb.vp / data->cmb.vs) < 1.45)
    { data->cmb.vs= data->cmb.vp/1.45;
      taper2_cnt=taper2_cnt+1; 
    }

  if( data->cmb.vs < 500.0)
    {
      ratio = data->cmb.vp / data->cmb.vs;
      taper3_cnt=taper3_cnt+1; 
      data->cmb.vs=500;
      data->cmb.vp= data->cmb.vs * ( ratio );
    }
  if(ucvm_interp_vp_floor != UCVM_DEFAULT_NULL_FLOOR && 
		  data->cmb.vp < ucvm_interp_vp_floor)
    { 
       taper4_cnt=taper4_cnt+1;
       data->cmb.vp= ucvm_interp_vp_floor ; 
    }

fprintf(stderr,"XXX 1(%d) 2(%d) 3(%d) 4(%d) \n", taper1_cnt, taper2_cnt, taper3_cnt, taper4_cnt);


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
