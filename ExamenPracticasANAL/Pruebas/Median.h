
#ifndef MEDIAN_H
#define MEDIAN_H

/* constants */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

int Median_of_Median(int * List, int ip,int iu, int k, int *median);
#endif