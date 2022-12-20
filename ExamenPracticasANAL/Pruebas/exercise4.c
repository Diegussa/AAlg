/**************************************************/
/* Programa: ejercise4       Date:                */
/* Authors:                                       */
/*                                                */
/* Program that checks InsertSort                 */
/*                                                */
/* Input: Command Line                            */
/* -size: number of elements of each permutation  */
/* Output: 0: OK, -1: ERR                         */
/**************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "permutations.h"
#include "sorting.h"
#include "Median.h"

int main(int argc, char** argv)
{
  int tamano, i, j, ret,k,key;
  int* perm = NULL;
  srand(time(NULL));

  if (argc != 5) {
	fprintf(stderr, "Error in input parameters:\n\n");
    fprintf(stderr, "%s -size <int>\n", argv[0]);
    fprintf(stderr, "Where:\n");
    fprintf(stderr, " -size : number of elements in the permutation.\n");
    return 0;
  }
  printf("Practice number 1, section 4\n");
  printf("Done by: your names\n");
  printf("Group: Your group\n");

  /* check command line */
  for(i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-size") == 0) {
      tamano = atoi(argv[++i]);
    } else if((strcmp(argv[i], "-key") == 0)) {
      key=atoi(argv[++i]);
    }else{
      fprintf(stderr, "Wrong paramenter %s\n", argv[i]);
    }
  }

  perm = generate_perm(tamano);

  if (perm == NULL) { /* error */
    printf("Error: Out of memory\n");
    exit(-1);
  }
  for(j = 0; j < tamano; j++) {
    printf("%d \t", perm[j]);
  }
  printf("K: %d \n", key);

  ret =Median_of_Median(perm, 0, tamano-1,key-1,&k);
  printf("K: %d \t", k);

  if (ret == ERR) {
    printf("Error: Error in Median\n");
    free(perm);
    exit(-1);
  }
  printf("\nMedian: %d \n ", ret);
  

  printf("\n");
  printf("K: %d Key: %d\t", k,key);

  ret =MergeSort(perm, 0, tamano-1);

  if (ret == ERR) {
    printf("Error: Error in Median\n");
    free(perm);
    exit(-1);
  }
  for(j = 0; j < tamano; j++) {
    printf("%d:%d  ",j+1, perm[j]);
  }

  free(perm);
  return 0;
}

