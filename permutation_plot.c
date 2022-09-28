#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#define N_perms 400000
#define N_elem 5


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
    if (inf > sup){
        
        return -1;
    }
        
    return inf + (int)((sup - inf + 1.0) * rand() / (RAND_MAX + 1.0));
}

void swap(int *x, int *y)
{    
    int aux;

    if(!x||!y) return;

    aux = *x;
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
    int *perm=NULL;

    if (N < 1)
        return NULL;

    perm = (int *)malloc(N * sizeof(int));
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
}
int fact( int n){
    if(n==0) return 1;

    return n*fact(n-1);
}
int elev(int b, int e){
    int i,k=1;
    for(i=1; i<=e;i++)
        k*=b;
    
    return k;
}

int desc(int n, int b){
    int i, suma=0, pot;
    for(i=b-1; i>=0; i--){
        pot=elev(b, i);
        while((n-pot)>=0){
            n-=pot;
            suma+=elev(10, i);
        }
    }

    return suma;
}

int main(){
    int i,j,**tabla,suma, M=elev(N_elem,N_elem+2), cont=0;
    int t[M];
    FILE*f;

    srand(time(NULL));
    f=fopen("permutation_plot.txt","w");
    if(!f){printf("1");return 1;}

    for(i=0;i<M;i++){
        t[i]=0;
    }

    tabla=generate_permutations(N_perms,N_elem);
    
    if(!tabla) return 1;
    for(i=0;i<N_perms;i++){
        for(j=N_elem-1,suma=0;j>=0; j--){
            suma+=tabla[i][j]*elev(N_elem+1,j);

        }
        t[suma]++;
    }
    
    for(i=0;i<M;i++){
        if(t[i]){//Imprimimos y contamos todas las permutaciones que aparezcan al menos una vez
            cont++;
            fprintf(f,"%d %d\n", desc(i,N_elem+1),t[i]);
        }
        
    }

    if(cont!=fact(N_elem)){//Controlamos que todas las permutaciones se obtengan al menos una vez
        fclose(f);
        f=fopen("permutation_plot.txt","w");
        if(!f){
            printf("1");
            return 1;
        }
        fprintf(f, "Error");
    }
    printf(" %d %d", fact(N_elem), cont);
    
    free(tabla);
    fclose(f);
    return 1;
}
