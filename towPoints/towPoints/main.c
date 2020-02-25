#include <stdio.h>
#include <math.h>

int main() {
    int n,i;
    int x[10000],y[10000];
    int distance[10000];
    int index1 = 0, index2= 0, min;
    scanf( "%d" ,&n);
    
    for (i=0; i<n; i++){
        scanf("%d %d",&x[i], &y[i]);
    }
    
    for (i=0; i<n; i++) {
        distance[i] = pow(x[i]-x[0],2.0) + pow(y[i]-y[0],2.0);
        printf("%d ",distance[i]);
    }
    
    min = 10000000;
    for (i=1; i<n; i++){
        if(min > distance[i]){
            min = distance[i];
            index1 = i;
        }
    }
    
    distance[0] = distance[index1];
    
    min = 10000000;
    for (i=1; i<n; i++){
        if(index1 != i && min > distance[i]){
            min = distance[i];
            index2 = i;
        }
    }

    printf("\n %d %d %d", index1,index2,(int)(pow(x[index1]-x[index2],2.0) + pow(y[index1]-y[index2],2.0)));
    
    return 0;
}
