#include <stdio.h>

int n,m;
int arr[8];

void n_m3(int depth) {
    for(int i = 1; i <= n; i++) {
        if(depth == 0)
            arr[0] = i;
        else {
            arr[depth] = i;
        }              
        if(m-1 == depth) {
            for(int l = 0; l < m; l++) printf("%d ", arr[l]);
            printf("\n");
        } else {
            n_m3(depth+1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    n_m3(0);
    return 0;    
}