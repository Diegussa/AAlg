/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "sorting.h"
#include <stdio.h>

/***************************************************/
/* Function: SelectSort    Date:                   */
/* Your comment                                    */
/***************************************************/

void swap1(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}


int SelectSort(int *array, int ip, int iu)
{
  int i, m, cont = 0;

  if (!array || ip < 0 || iu < 0 || iu < ip)
    return ERR;

  for (i = ip; i < iu; i++)
  {
    m = min(array, i , iu);
    cont += iu - i+1;
    if (m == -1)
      return ERR;

    swap1(&array[m], &array[i]);
  }
  return cont;
}


int SelectSortInv(int *array, int ip, int iu)
{  
  int i, m, cont = 0;
  
   if (!array || ip < 1 || iu < 1 || iu > ip)
    return ERR;



  for (i = iu; i > ip; i--)
  {
    m = min(array, i , iu);
    cont += iu - i+1;
    if (m == -1)
      return ERR;

    swap1(&array[m], &array[i]);
  }
  return cont;
}

int min(int *array, int ip, int iu)
{
  int i, min;
  if (!array || ip >= iu || ip < 0)
    return ERR;

  min = ip;
  for (i = ip; i <= iu; i++)
  {
    if (array[min] > array[i])
    {
      min = i;
    }
  }
  return min;
}
