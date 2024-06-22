/*------------------ global definitions ----------------------------------*/

/* input and output files */
FILE *fpin, *fpout;

/*------------------ global variables -------------------------------------*/
typedef	struct {

  int max_time_step;    /* max time step */
  int mat_size;         /* system size   */
  int mat_size2;        /* mat_size/2: will be used at "msd_calc()"  */
  int shift;            /* column shift = mat_size + 4               */
  double concentration; /* initial concentration probability         */

  double inf_init_rate;   /* initial rate of infected walkers */
  int    inf_illness;     /* illness state */
  
} calc_control;

typedef	struct {

  long tdumy;   /* dummy variable for time() function     */ 
  long seed;    /* seed for random number genelater       */

  int time_step;    /* current number of time step */
  int average_step; /* current average step        */

  int *mat0; 
  int *mat1; 
  int *mat2;  /* not used */

  double *accumulation;
  double *distinct_sites;
  int number_of_walkers;

  long *random_seed;
  float random;

} system_property;

/*------------------- declaration for the structures ----------------------*/

calc_control ctl;
system_property sys;


