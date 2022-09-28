#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAX 1000000
#define SUP 20
#define INF 1

int random_num(int inf, int sup)
{
    if (inf > sup){
        
        return -1;
    }
        
    return inf + (int)((sup - inf + 1.0) * rand() / (RAND_MAX + 1.0));
}
int main(){
    int t[SUP-INF+1],i;
    FILE*f;
    f=fopen("random_plot.txt","w");
    if(!f) return 0;
    for(i=0;i<SUP-INF+1;i++){
        t[i]=0;
    }
    
    for(i=0;i<MAX;i++){
        t[random_num((int)0,(int)SUP-INF)]++;
    }
    
    for(i=0;i<SUP-INF+1;i++){
        fprintf(f,"%d %d\n", INF +i, t[i]);
    }
    fclose(f);
    return 1;
}