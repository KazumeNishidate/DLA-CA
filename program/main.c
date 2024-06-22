#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "rw.h"
#include "prototypes.h"

/* RWCA-2d uder cyclic boundary condition */
int main(void){

  open_files();
  get_control_param();
  init_mem();

  set_init_conf();
  set_infect();

  mk_copy(sys.mat0, sys.mat1);
  /*----------- RWCA moving step -----------*/
  for(sys.time_step=0;sys.time_step<ctl.max_time_step;sys.time_step++){
    move_walkers();       /* sys.mat0 => RWCA  => sys.mat1 */
    mk_copy(sys.mat1, sys.mat0);  /* sys.mat1  => sys.mat0 */
    egg_disp();
  }
  /*-------- end of RWCA moving step -------*/
  return 0;
}

