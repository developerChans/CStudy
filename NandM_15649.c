#include<stdio.h>
void n_m1(int arr[], int n, int m, int depth){
    for(int i = 1; i < n+1; i++) {
        if (depth == 0) {
            arr[depth] = i;
        } else {
            int j = 0;
            for(j = 0; j < depth; j++) {
                if(arr[j] == i) break;
            }
            if (j == depth) {
                arr[depth] = i;
            } 
            else continue;

        }

        if(m-1 == depth) {
            for(int k = 0; k < m; k++) {
                printf("%d ",arr[k]);
            }
            printf("\n");
        }
        else n_m1(arr,n,m,depth+1);
    }
}

int main() {
    int n,m;
    int arr[8] = {0,};
    scanf("%d %d", &n, &m);
    n_m1(arr,n,m,0);
    return 0;
}