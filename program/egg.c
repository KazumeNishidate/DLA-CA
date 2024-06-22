#include <eggx.h>
#include <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include  <string.h>
#include  <X11/Xlib.h>
#include  <X11/Xutil.h>
#include "rw.h"
#include "prototypes.h"
#define MYCOLOR IDL2_HARDCANDY
#define X_MAX 450
#define Y_MAX 450

void egg_disp(void){
  static int cnt=0, win;
  int i, j;
  int c_r, c_g, c_b;  
  
  if(cnt==0){
    win=gopen(X_MAX,Y_MAX);
    gsetbgcolor(win,"Gray");
    layer(win,0,1);
  }

  gclr(win) ;

    for (i = 2; i < ctl.mat_size+2; i++){
      for (j = 2; j < ctl.mat_size+2; j++){

	if(sys.mat0[ctl.shift*i+j]>0){
	  newcolor(win, "Green");
	  fillrect(win, i*3, j*3, 2, 2);
	}
	if(sys.mat0[ctl.shift*i+j]<0){
	  makecolor(MYCOLOR,(double)ctl.max_time_step, 0.0,-sys.mat0[ctl.shift*i+j], &c_r,&c_g,&c_b);                                                
	  newrgbcolor(win,c_r,c_g,c_b);    
	  fillrect(win, i*3, j*3, 2, 2);
	}
      }
    }
    copylayer(win,1,0);
  cnt++;  


}
