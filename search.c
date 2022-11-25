/**
 *
 * Description: Implementation of functions for search
 *
 * File: search.c
 * Author: Carlos Aguirre and Javier Sanz-Cruzado
 * Version: 1.0
 * Date: 14-11-2016
 *
 */

#include "search.h"

#include <stdlib.h>
#include <math.h>

/**
 *  Key generation functions
 *
 *  Description: Receives the number of keys to generate in the n_keys
 *               parameter. The generated keys go from 1 to max. The
 * 				 keys are returned in the keys parameter which must be 
 *				 allocated externally to the function.
 */
  
/**
 *  Function: uniform_key_generator
 *               This function generates all keys from 1 to max in a sequential
 *               manner. If n_keys == max, each key will just be generated once.
 */
void uniform_key_generator(int *keys, int n_keys, int max)
{
  int i;

  for(i = 0; i < n_keys; i++) keys[i] = 1 + (i % max);

  return;
}

/**
 *  Function: potential_key_generator
 *               This function generates keys following an approximately
 *               potential distribution. The smaller values are much more 
 *               likely than the bigger ones. Value 1 has a 50%
 *               probability, value 2 a 17%, value 3 the 9%, etc.
 */
void potential_key_generator(int *keys, int n_keys, int max)
{
  int i;

  for(i = 0; i < n_keys; i++) 
  {
    keys[i] = .5+max/(1 + max*((double)rand()/(RAND_MAX)));
  }

  return;
}

PDICT init_dictionary (int size, char order)
{
   PDICT DICT;

  if(size<0||(order!=1 && order!=0))
    return NULL;
  
  DICT=(PDICT)calloc(1,sizeof(DICT));
  if(DICT==NULL){
    return NULL;
  }
  DICT->size=size;
  DICT->n_data=0;
  DICT->order=order;
  DICT->table=(int*)calloc(size,sizeof(int));
  if(DICT->table==NULL){
    free(DICT);
    return NULL;
  }
  return DICT;
	/* your code */
}

void free_dictionary(PDICT pdict)
{
	if(!pdict) return;

  free(pdict->table);
  free(pdict);
}

int insert_dictionary(PDICT pdict, int key)
{
  int i;
	if(!pdict) return ERR;
  if(pdict->size==pdict->n_data) return ERR;

  if(pdict->n_data==0){ /*Si el diccionario está vacío*/
    pdict->table[0]=key;
    pdict->n_data++;
    return 0;
  }

  if(pdict->order==NOT_SORTED){
    pdict->table[pdict->n_data]=key;
    pdict->n_data++;

    return 0;
  }
  else{
    i=pdict->n_data-1;
    while(i>=0 && pdict->table[i]>key){
      pdict->table[i+1]=pdict->table[i];
      i--;
    }
    pdict->table[i+1]=key;
  }

  pdict->n_data++;

  return pdict->n_data-i;
}

int massive_insertion_dictionary (PDICT pdict,int *keys, int n_keys)
{
  int i,count=0,nob;
  if(!pdict||!keys||n_keys<0){
    return ERR;
  }
  for(i=0;i<n_keys;i++){
    nob=insert_dictionary(pdict,keys[i]);
    if(nob<0){
      return ERR;
    }
    count+=nob;
  }
  return count;
}

int search_dictionary(PDICT pdict, int key, int *ppos, pfunc_search method)
{
  if(!pdict||!ppos||!method) return ERR;
  return method(pdict->table, 0, pdict->n_data-1, key, ppos);
}


/* Search functions of the Dictionary ADT */
int bin_search(int *table,int F,int L,int key, int *ppos)
{
  int med;
	if(!table||F>L||!ppos) return ERR;

  if(F==L){ /*Cuando solo queda una clave*/
    if(table[F]==key){
      *ppos=F;
      return 1;
    }
    else return NOT_FOUND;
  }

  med=(F+L)/2;
  if(table[med]==key){
    *ppos=F;
    return 1;
  }
  else if(key>table[med]){
    return 1+bin_search(table, med+1, L, key, ppos);
  }
  else{
    return 1+bin_search(table, F, med-1, key, ppos);
  }
}

int lin_search(int *table,int F,int L,int key, int *ppos)
{
  int i;
  if(!table|| F>L || !ppos)  return ERR;
  
  for ( i=F;i<=L;i++)
  {
    if(table[i]==key){
      *ppos=i;
      return i-F+1;
    }
  }
  return NOT_FOUND;
}

int lin_auto_search(int *table,int F,int L,int key, int *ppos)
{
	int i;
  if(!table||F>L||!ppos) return ERR;

  if(table[F]==key){
      *ppos=F;
      return 1;
    }
  
  for(i=F; i<=L; i++){
    if(table[i]==key){
      table[i]=table[i-1];
      table[i-1]=key;
      *ppos=i-1;
      return i-F+1;
    }
  }
  
  return NOT_FOUND;
}