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

/***************************************************/
/* Function: SelectSort    Date:                   */
/* Your comment                                    */
/***************************************************/
/*void swap(int *x, int *y){
  int aux=*x;
  *x=*y;
  *y=aux;

}*/
int SelectSort(int* array, int ip, int iu)
{
  if(!array || ip<1 || iu<1) return -1;
  int i,j, min, aux,cont=0;
  for(i=ip;i<iu;i++){
    min=i;
    for(j=i+1;j<=iu;j++){
      if(array[j]<array[min]){
        cont++;
        min=j;
      }
    }
    swap(&array[min],&array[i]);
  }
  return cont;
  /* Your code */
}
/*
int i,j,cont, aux;

for(i=iu,i>ip;i++*{
  for(j=ip,j<i;j++){
    if(array[j]>array[j+1]){
       aux=array[j];
    array[j]=array[j+1];
    array[j+1]=aux;
    }
*/
int SelectSortInv(int* array, int ip, int iu)
{
  /* your code */
}

int min(int* array, int ip, int iu)
{
  /* your code */
}

