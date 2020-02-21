#include <stdio.h>
#include <math.h>

int main() {
    int n,i,j;
    int x[10000],y[10000];
    int distance[10000][10000];
    int index1_x = 0, index1_y = 0, index2_x = 0, index2_y= 0, min;
    scanf( "%d" ,&n);
    
    for (i=0; i<n; i++){
        scanf("%d %d",&x[i], &y[i]);
        if(i >= 1){
            for(j=0; j<i; i++){
                distance[i-1][j] = pow(x[i]-x[j],2.0) + pow(y[i]-y[j],2.0);
            }
        }
    }
    
    min = 10000000;
    for (i=0; i<n; i++){
        for(j=0; j<i; j++){
            if(min > distance[i][j]){
                min = distance[i][j];
                index1_x = i+1;
                index1_y = j;
            }
        }
    }
    int tmp = distance[index1_x][index1_y];
    distance[index1_x][index1_y] = distance[0][0];
    distance[0][0] = tmp;
    
    min = 10000000;
    for (i=0; i<n; i++){
        for(j=1; j<i; j++){
            if(min > distance[i][j]){
                min = distance[i][j];
                index2_x = i+1;
                index2_y = j;
            }
        }
    }

    
    printf("%d", (int)(pow(x[index1_x]-x[index2_x],2.0) + pow(y[index1_y]-y[index2_y],2.0)));
    
    return 0;
}
