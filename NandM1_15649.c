#include <stdio.h>
int n,m;
int arr[8];
void n_m1 (int depth) {
    for(int i = 1; i <= n; i++ ) { // i가 1부터 n까지 첫 시작점
        if(depth == 0) { // 초기 단계에 i를 시작점으로 설정
            arr[0] = i;
        }
        else {
            int j;
            for(j = 0; j < depth; j++) {
                if(arr[j] == i)  // 0부터 깊이만큼 탐색시 초기 값인 i가 존재하면 이미 탐색했던 것 따라서 멈춰 선언
                    break;
            }
            if(j == depth) { // 위의 경우를 다 지낫을 경우 현재 배열에는 i가 존재하지 않는 것 따라서 추가해줘야함
                arr[depth] = i;
            }
            else continue;
        }

        if(m-1 == depth) { // 뽑는 개수 만큼 깊이가 돌았을 경우 m개의 수를 뽑은 것이다. (depth는 0부터 시작하기에 m-1과 비교)
            for(int k = 0; k < m; k++)
                printf("%d ", arr[k]);
            printf("\n");
        } else { // 아닐 경우 더 뽑아야하기 때문에 다음 단계로 전진
            n_m1(depth + 1); 
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    n_m1(0);
    return 0;
}