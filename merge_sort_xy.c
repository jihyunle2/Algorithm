#include <stdio.h>

void merge(int data[], int y[], int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int tmp[r+1]; // 새 배열
        int tmp_y[r+1];
    while(i<=q && j<=r) {
        if(data[i] < data[j]) {
                    tmp[k] = data[i];
                    tmp_y[k++] = y[i++];
                }
        else if(data[i] > data[j]) {
                    tmp[k] = data[j];
                    tmp_y[k++] = y[j++];
                }
        else{ //같을 때
            if(y[i] < y[j]) {
                        tmp[k] = data[i];
                        tmp_y[k++] = y[i++];
                        }
                        else {
                        tmp[k] = data[j];
                        tmp_y[k++] = y[j++];
                        }
        }
    }
    while(i<=q) {
                    tmp[k] = data[i];
                    tmp_y[k++] = y[i++];
                    }
    while(j<=r) {
                    tmp[k] = data[j];
                    tmp_y[k++] = y[j++];
                    }
    for(int a = p; a<=r; a++){
            data[a] = tmp[a];
            y[a] = tmp_y[a];
        }
}

void mergeSort(int data[], int y[], int p, int r) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(data, y, p , q);
        mergeSort(data, y, q+1, r);
        merge(data, y, p, q, r);
    }
}
 
//메인함수
int main()
{
    int num;
    int i;
    
    scanf("%d",&num);
    
    int x[100000],y[100000];
    
    for(i=0; i<num; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    
    mergeSort(x, y, 0, num-1);

    for (i=0; i<num; i++){
        printf("%d %d\n", x[i],y[i]);
    }
    return 0;
}
