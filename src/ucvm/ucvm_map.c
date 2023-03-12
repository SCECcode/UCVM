/**
 * @file ucvm_map.c
 * @brief ucvm_map interface
 * @version 1.0
 *
 * @section DESCRIPTION
 * load map on demand, by default California Statewide is loaded 
 *
 */

#
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "ucvm_dtypes.h"
#include "ucvm_map.h"

int ucvm_map_is_setup = 0;
ucvm_map_t map[UCVM_MAX_MAPS];
ucvm_map_t *MAPPTR = NULL;

void _ucvm_map_setup() {
   int i;
   for(i=0; i<UCVM_MAX_MAPS; i++) {
     map[i].map_is_initialized = 0;
     map[i].map_label_str[0]= '\0';
   }
}

void _ucvm_map_teardown() {
   int i;
   for(i=0; i<UCVM_MAX_MAPS; i++) {
     map[i].map_is_initialized = 0;
     if(strlen(map[i].map_label_str)!=0) {
       etree_close(MAPPTR->map_ep);
       ucvm_proj_ucvm_finalize(&MAPPTR->map_proj);
     }
   }
}

/* iterate through all the entries, ignoring map_is_initialized */
ucvm_map_t *get_map_by_label(const char *label)
{
   int i;
   for(i=0; i<UCVM_MAX_MAPS; i++) {
     if(strcmp(label,map[i].map_label_str)== 0)
       return &map[i];
   }
   return NULL;
}

/* get first empty map space */
ucvm_map_t *_get_map_next()
{
   int i;
   for(i=0; i<UCVM_MAX_MAPS; i++) {
     if(strlen(map[i].map_label_str) == 0)
       return &map[i];
   }
   return NULL;
}

/* Init Map */
int ucvm_map_init(const char *label, const char *conf)
{
  char *appmeta;

  if ((label == NULL) || (strlen(label) == 0)) {
    fprintf(stderr, "Invalid map label\n");
    return(UCVM_CODE_ERROR);
  }

  if ((conf == NULL) || (strlen(conf) == 0)) {
    fprintf(stderr, "No map path defined for map\n");
    return(UCVM_CODE_ERROR);
  }

  if (!ucvm_is_file(conf)) {
    fprintf(stderr, "Etree map %s is not a valid file\n", conf);
    return(UCVM_CODE_ERROR);
  }

  if(ucvm_map_is_setup == 0) {
    _ucvm_map_setup();
    ucvm_map_is_setup = 1;
  }

  MAPPTR= get_map_by_label(label);
  if (MAPPTR!=NULL && MAPPTR->map_is_initialized) {
    fprintf(stderr, "UCVM map interface is already initialized\n");
    return(UCVM_CODE_ERROR);
  }

  if(MAPPTR != NULL) {
//    fprintf(stderr,">>>reuse MAPPTR\n");
    MAPPTR->map_is_initialized = 1;
    return(UCVM_CODE_SUCCESS);
    } else {
//      fprintf(stderr,">>>getting fresh MAPPTR\n");
      MAPPTR= _get_map_next();
  }

  /* Save label */
  ucvm_strcpy(MAPPTR->map_label_str, label, UCVM_MAX_LABEL_LEN);
//  fprintf(stderr,"   map label ..%s\n",MAPPTR->map_label_str);

  /* Open Etree map */
  MAPPTR->map_ep = etree_open(conf, O_RDONLY, UCVM_MAP_BUF_SIZE, 0, 3);
  if (MAPPTR->map_ep == NULL) {
    fprintf(stderr, "Failed to open the etree %s\n", conf);
    return(UCVM_CODE_ERROR);
  }

  /* Read meta data and check it */
  appmeta = etree_getappmeta(MAPPTR->map_ep);
  if (appmeta == NULL) {
    fprintf(stderr, "Failed to read metadata from etree %s\n", conf);
    return(UCVM_CODE_ERROR);
  }
  if (ucvm_meta_etree_map_unpack(appmeta, &(MAPPTR->map_meta)) != 
      UCVM_CODE_SUCCESS) {
    fprintf(stderr, "Failed to unpack metadata from etree %s\n", conf);
    return(UCVM_CODE_ERROR);
  }
  free(appmeta);

  /* Setup projection */
  if (ucvm_proj_ucvm_init(MAPPTR->map_meta.projstr, 
			  &(MAPPTR->map_meta.origin), 
			  MAPPTR->map_meta.rot,
			  &(MAPPTR->map_meta.dims_xyz),
			  &(MAPPTR->map_proj)) != UCVM_CODE_SUCCESS) {
    fprintf(stderr, "Failed to setup proj %s.\n", 
	    MAPPTR->map_meta.projstr);
    return(UCVM_CODE_ERROR);
  }

  /* Determine length of longest side */
  if (MAPPTR->map_meta.dims_xyz.coord[0] > MAPPTR->map_meta.dims_xyz.coord[1]) {
    MAPPTR->map_max_len = MAPPTR->map_meta.dims_xyz.coord[0];
  } else {
    MAPPTR->map_max_len = MAPPTR->map_meta.dims_xyz.coord[1];
  }

  /* Compute level based on grid spacing */
  MAPPTR->map_level = ceil(log(MAPPTR->map_max_len/
			    MAPPTR->map_meta.spacing) /log(2.0));

  /* Compute edge size in tics */
  MAPPTR->map_edgetics = (etree_tick_t)1 << (ETREE_MAXLEVEL - MAPPTR->map_level);

  /* Compute edge size in meters */
  MAPPTR->map_edgesize = MAPPTR->map_max_len/
    (double)((etree_tick_t)1<<MAPPTR->map_level);

  MAPPTR->map_is_initialized = 1;

  return(UCVM_CODE_SUCCESS);
}


/* Finalize Map */
int ucvm_map_finalize()
{
//  fprintf(stderr,"calling ucvm_map_finalize..\n");
  if (MAPPTR->map_is_initialized) {
/* disable the freeing of the structures so it may be reused again */
/* need to figure out where to call the _ucvm_map_teardown()       */
//    etree_close(MAPPTR->map_ep);
//    ucvm_proj_ucvm_finalize(&MAPPTR->map_proj);
  }
  
  MAPPTR->map_is_initialized = 0;
  MAPPTR = NULL;

  return(UCVM_CODE_SUCCESS);
}


/* Get Version Map */
int ucvm_map_version(char *ver, int len)
{
  int verlen;

  if (MAPPTR == NULL || MAPPTR->map_is_initialized == 0) {
    fprintf(stderr, "UCVM map interface not initialized\n");
    return(UCVM_CODE_ERROR);
  }

  verlen = strlen(MAPPTR->map_meta.date);
  if (verlen > len - 1) {
    verlen = len - 1;
  }
  memset(ver, 0, len);
  strncpy(ver, MAPPTR->map_meta.date, verlen);

  return(UCVM_CODE_SUCCESS);
}


/* Get Label Map */
int ucvm_map_label(char *label, int len)
{
  int labellen;

  if (MAPPTR == NULL || MAPPTR->map_is_initialized == 0) {
    fprintf(stderr, "UCVM map interface not initialized\n");
    return(UCVM_CODE_ERROR);
  }

  labellen = strlen(MAPPTR->map_label_str);
  if (labellen > len - 1) {
    labellen = len - 1;
  }
  memset(label, 0, len);
  strncpy(label, MAPPTR->map_label_str, labellen+1);

  return(UCVM_CODE_SUCCESS);
}


/* Query Map */
int ucvm_map_query(ucvm_ctype_t cmode,
		   int n, ucvm_point_t *pnt, ucvm_data_t *data)
{
  int i, x, y;
  int x0, y0;
  ucvm_point_t xy;
  etree_addr_t addr;
  double p[2][2];
  ucvm_mpayload_t q[2][2];
  
  if (MAPPTR == NULL || MAPPTR->map_is_initialized == 0) {
    fprintf(stderr, "UCVM map interface is not initialized");
    return(UCVM_CODE_ERROR);
  }

  /* Check query mode */
  switch (cmode) {
  case UCVM_COORD_GEO_DEPTH:
  case UCVM_COORD_GEO_ELEV:
    break;
  default:
    fprintf(stderr, "Unsupported coord type\n");
    return(UCVM_CODE_ERROR);
    break;
  }

  /* Corners of interpolation plane */
  p[0][0] = 0.0;
  p[0][1] = 0.0;
  p[1][0] = 1.0;
  p[1][1] = 1.0;

  for (i = 0; i < n; i++) {
    /* Convert point from geo to xy offset in meters */
    if (ucvm_proj_ucvm_geo2xy(&(MAPPTR->map_proj), 
			      &(pnt[i]),
			      &xy) == UCVM_CODE_SUCCESS) {
      if ((xy.coord[0] >= 0.0) && 
	  (xy.coord[0] < MAPPTR->map_meta.dims_xyz.coord[0]) &&
	  (xy.coord[1] >= 0.0) &&
	  (xy.coord[1] < MAPPTR->map_meta.dims_xyz.coord[1])) {

	/* Calculate grid location in fp and integer octants */
	xy.coord[0] = xy.coord[0]/MAPPTR->map_edgesize;
	xy.coord[1] = xy.coord[1]/MAPPTR->map_edgesize;

	x0 = (int)(xy.coord[0]);
	y0 = (int)(xy.coord[1]);

	/* Determine q values for interpolation */
	for (y = 0; y < 2; y++) {
	  for (x = 0; x < 2; x++) {
	    addr.x = (x0 + x)*MAPPTR->map_edgetics;
	    addr.y = (y0 + y)*MAPPTR->map_edgetics;
	    addr.z = 0;
	    addr.level = ETREE_MAXLEVEL;
	    
	    /* Adjust addresses for edges of grid */
	    if (addr.x >= MAPPTR->map_meta.ticks_xyz.dim[0]) {
	      addr.x = MAPPTR->map_meta.ticks_xyz.dim[0] - MAPPTR->map_edgetics; 
	    }
	    if (addr.y >= MAPPTR->map_meta.ticks_xyz.dim[1]) {
	      addr.y = MAPPTR->map_meta.ticks_xyz.dim[1] - MAPPTR->map_edgetics; 
	    }
	    
	    /* Query etree */
	    if (etree_search(MAPPTR->map_ep, addr, NULL, "*", &(q[y][x])) == 0) {
	      //printf("vals: %lf, %lf\n", q[y][x].surf, q[y][x].vs30);
	    } else {
	      fprintf(stderr, "%s (%d %d %d)\n", 
		      etree_strerror(etree_errno(MAPPTR->map_ep)),
		      addr.x, addr.y, addr.z);
	      return(UCVM_CODE_ERROR);
	    }
	  }
	}

	/* Bilinear interpolation of values */
	data[i].surf = interpolate_bilinear(xy.coord[0]-x0, 
					    xy.coord[1]-y0, 
					    p[0][0], p[0][1],
					    p[1][0], p[1][1], 
					    q[0][0].surf, 
					    q[0][1].surf, 
					    q[1][0].surf, 
					    q[1][1].surf);
	
	data[i].vs30 = interpolate_bilinear(xy.coord[0]-x0, 
					    xy.coord[1]-y0, 
					    p[0][0], p[0][1],
					    p[1][0], p[1][1], 
					    q[0][0].vs30, 
					    q[0][1].vs30, 
					    q[1][0].vs30, 
					    q[1][1].vs30);

      }
    }
  }

  return(UCVM_CODE_SUCCESS);
}


