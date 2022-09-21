/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Carlos Aguirre
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include "permutations.h"

/***************************************************/
/* Function: random_num Date:                      */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/
int random_num(int inf, int sup)
{

  if (inf >= sup)
    return -1;
  return inf + (int)((sup - inf + 1.0) * rand() / (RAND_MAX + 1.0));
  ;
  /* your code */
}
void swap(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}
/***************************************************/
/* Function: generate_perm Date:                   */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permitation                   */
/* or NULL in case of error                        */
/***************************************************/
int *generate_perm(int N)
{
  int i;
  int *perm;

  if (N < 1)
    return NULL;

  perm = (int *)malloc((N) * sizeof(int));
  if (!perm)
    return NULL;

  for (i = 0; i < N; i++)
  {
    perm[i] = i + 1;
  }
  for (i = 0; i < N; i++)
  {
    swap(&perm[i], &perm[random_num(i, N - 1)]);
  }

  return perm;
  /* your code */
}

/***************************************************/
/* Function: generate_permutations Date:           */
/* Authors:                                        */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/
int **generate_permutations(int n_perms, int N)
{
  int **tabla = NULL;
  int i;

  if (n_perms < 1 || N < 1)
    return NULL;
  /*Reservamos la memoria*/
  tabla = (int **)malloc(n_perms * sizeof(int *));
  if (!tabla)
    return NULL;

  for (i = 0; i < n_perms; i++)
  {
    tabla[i] = generate_perm(N);
    if (!tabla[i])
    {
      for (i = i - 1; i >= 0; i--)
      {
        free(tabla[i]);
      }
      free(tabla);
      return NULL;
    }
  }

  return tabla;
  /* your code */
}
