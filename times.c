/**
 *
 * Descripcion: Implementation of time measurement functions
 *
 * Fichero: times.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "times.h"
#include <time.h>
#include "sorting.h"
#include "permutations.h"
#include <stdio.h>
#include <stdlib.h>

/***************************************************/
/* Function: average_sorting_time Date:            */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short average_sorting_time(pfunc_sort metodo, int n_perms, int N, PTIME_AA ptime)
{
int i, **p=NULL,suma_ob=0,n_ob=0,min_ob, max_ob=0;
clock_t t1, t2;

if(n_perms<1||N<1||!ptime||!metodo) return ERR;/*Control de errores*/

p=generate_permutations(n_perms, N);/*Generacion de permutaciones y control de errores*/
if(!p) return ERR;


t1=clock();
if((n_ob=metodo(p[0], 0, N-1)<0)){
    for (i = N - 1; i >= 0; i--)
        {
          free(p[i]);
        }
       free(p);
            return ERR;
  
}
min_ob=n_ob;
max_ob=n_ob;
suma_ob+=n_ob;
for(i=1; i<n_perms; i++){
  if((n_ob=metodo(p[i], 0, N-1)<0)){
    for (i = N - 1; i >= 0; i--)
        {
          free(p[i]);
        }
       free(p);
            return ERR;
  }
  if(n_ob<min_ob){
    min_ob=n_ob;
  }else if(n_ob>max_ob){
    max_ob=n_ob;
  }
  suma_ob+=n_ob;
}
t2=clock();

ptime->time=(double)(t2-t1)/n_perms;
ptime->N=N;
ptime->n_elems=n_perms;
ptime->average_ob=(double)suma_ob/n_perms;
ptime->min_ob=min_ob;
ptime->max_ob=max_ob;


return OK;
}

/***************************************************/
/* Function: generate_sorting_times Date:          */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max, int incr, int n_perms)
{
  TIME_AA *ptime=NULL;
  int i;

  if(!file||num_min<0||num_max<0) return ERR;

  i=(num_max-num_min)/incr;/*Reserva dinamica de la tabla de datos*/
  ptime=(TIME_AA*)calloc(i, sizeof(TIME_AA));

  for(i=num_min; i<=num_max; i+=incr){/*Ordenacion y almacenamiento de datos*/
    average_sorting_time(method, 100, i, &ptime[(i-num_min)/incr]);
  }
  
  if(save_time_table(file, ptime, (num_max-num_min)/incr)<0){/*Guardar en fichero*/
      free(ptime);
      return ERR;
    }

  free(ptime);
  return OK;
}

/***************************************************/
/* Function: save_time_table Date:                 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{
  FILE *f=NULL;
  int i;
  if(!file||!ptime||n_times) return ERR;

  f=fopen(file, "w"); /*Apertura de archivo*/
  if(!f) return ERR;

  for(i=0; i<n_times; i++){
    if(5>fprintf(f, "%d    %lf    %lf    %d   %d", ptime[i].N, ptime[i].time, ptime[i].average_ob, ptime[i].max_ob, ptime[i].min_ob)){
      fclose(f);
      return ERR;
    }
  }
  fclose(f);
  
  return OK;
}