#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rw.h"
#include "prototypes.h"

void get_control_param(void){ 
  long time_dumy;

  /* set up the system control parameters */
  ctl.max_time_step = 10000;   /* max time step */
  ctl.mat_size = 150;         /* system size = n X n squared lattice */
  ctl.concentration = 0.2;  /* initial concentration probability */

  ctl.inf_init_rate = 0.5;  /* initial rate of infected walkers */
  ctl.inf_illness   = -1;  /* illness state */
  
  /* "ctl.mat_size2" will be used at "msd_calc()" to consider the */
  /* effect of cyclic boundaly condition in MSD calculation.      */
  ctl.mat_size2 = ctl.mat_size/2; 
  ctl.shift = ctl.mat_size+4;

  /* set a "seed" for random number generator */
  sys.random_seed = (long *)calloc(1, sizeof(long)); 
  *sys.random_seed=-time(&time_dumy); /* set seed for random numbers */

}
