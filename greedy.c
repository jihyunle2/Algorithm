#include <stdio.h>
#include <stdlib.h>

int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    int n, i=0;
    int p[1000];
    int prefix_sum[1000];
    int sum=0;
    
    scanf("%d",&n);
    
    do{
        scanf("%d", &p[i]);
        i++;
    }while (getc(stdin) == ' ');
    
    qsort(p, n, sizeof(int), compare);
    
    prefix_sum[0] = p[0];
    
    for(i=1; i<n; i++){
        prefix_sum[i] = prefix_sum[i-1] + p[i];
    }
    
    for(i=0; i<n; i++){
        sum += prefix_sum[i];
    }
    printf("%d",sum);
    
    return 0;
}
