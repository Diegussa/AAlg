#include <stdio.h>
#include "sorting.h"



int Find_Median(int* List, int ip,int iu, int *pos);
int Find_index(int *List,int ip,int iu,int *pos, int value);
void swap2(int *x, int *y) 
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

int partition2(int *tabla, int ip,int iu, int k, int *pos)
{
    int cont=0, m, i;
    if (!tabla|| !pos)
    {
        return -1;
    }
    Find_index(tabla,ip,iu,&m,k);
    k = tabla[m];

    swap2(&tabla[ip], &tabla[m]);
    m = ip;
    for (i = ip + 1; i <= iu; i++)
    {
        cont++;
        if (tabla[i] < k)
        {
            m++;
            swap2(&tabla[i], &tabla[m]);
        }
    }

    swap2(&tabla[ip], &tabla[m]);
    *pos = m;
    return cont;
}

int Median_of_Median(int * List, int ip,int iu, int k, int *median){
    int value=ip,count=0, index=-2;
    if(ip==iu){
      *median=List[ip];
      return 1;
    }
    /*printf("\nArgumentos: ip:%d iu:%d k:%d\n", ip, iu, k);*/
    if(ip+1==iu){
      count+=QuickSort(List,ip,iu);
      if(iu>=k){
        *median=List[iu];
      }else{
         *median=List[ip];
      }
      return count+1;
    }
    if(ip>iu){
      printf("Se nos ha liado un poco %d %d", ip,iu);
      *median=List[ip];
      return 0;
    }
    count+=Find_Median(List,ip,iu,&value);
    /*printf("Median = %d \n", value);
    for(int i=ip;i<=iu;i++){
      printf("M_M: %d ", List[i]);
    }
     printf(" \n");
    */
    count+=partition2(List,ip,iu,value,&index);
    /*printf("\nIndex= %d K: %d count:%d\n", index,k,count);

    for(int i=ip;i<=iu;i++){
      printf("M_M: %d ", List[i]);
    }
       printf(" \n");
    */
    if(index==k){
      /*printf(" \nRecursion No: %d %d",index,List[index]);*/
      *median=List[index];
      return count;
    }

    if(index>k){
      count+=Median_of_Median(List,ip,index-1,k,median);
    }else if(index<k){
      count+=Median_of_Median(List,index+1,iu,k,median);
    }
    /*printf("count: %d ",count);*/
    return count;

}
int Find_index(int *List,int ip,int iu,int *pos, int value){
    int i;
    for(i=ip;i<=iu;i++){
        if(List[i]==value){
          *pos=i;
          return i+1;
        }
    }
    return -1;
}
int Find_Median(int* List, int ip,int iu, int *pos){
    int count=0,i=ip,j,aux=0;
    int Median[(iu-ip+1)/5+1];
    if(ip==iu){
        *pos=List[ip];
        return 1;
    }
    if(iu-ip==1){
        count+=QuickSort(List,ip,ip+1);
        *pos=List[ip];
        return count;
    }/*
    printf("ip-iu: %d-%d\n",ip,iu);
    for(int t=ip;t<=iu;t++){
      printf("R: %d ", List[t]);
    }
    printf("\n");*/
    for(i=ip,j=0;i<=iu-4;i+=5,j++){
      /*for(int o=i;o<i+5;o++){
        printf("T%d: %d ",j, List[o]);
      }
          printf("\n");
*/
        count+=QuickSort(List,i,i+4);
        Median[j]=List[i+2];

    }
    if((iu-ip+1)%5){
        count+=QuickSort(List,i,iu);
         /*for(int k=i;k<=iu;k++){
          printf("Q: %d ", List[k]);
        }
        printf("Medio: %d \n", i+(iu-i+1)/2);*/
        Median[j]=List[ i+(iu-i+1)/2];
        aux=1;
    }
    /* for(int l=0;l<(iu-ip+1)/5+aux;l++){
        printf("M: %d ", Median[l]);
        }
    printf("count: %d \n",count);*/
    count+=Find_Median(Median,0,(iu-ip+1)/5+aux-1,pos);
    /*printf("count: %d \n",count);*/

    return count;
}
