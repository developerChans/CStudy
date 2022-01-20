#include <stdio.h>

int n,m;
int arr[8];

void n_m4(int depth) {
    for(int i = 1; i <= n; i++) {
        if(depth == 0)
            arr[0] = i;
        else {
            int j;
            for(j = 0; j < depth; j++) {
                if (arr[j] > i) break;
            } 
            if(j == depth) {
                arr[depth] = i;
            }
            else continue;
        }
              
        if(m-1 == depth) {
            for(int l = 0; l < m; l++) printf("%d ", arr[l]);
            printf("\n");
        } else {
            n_m4(depth+1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    n_m4(0);
    return 0;    
}