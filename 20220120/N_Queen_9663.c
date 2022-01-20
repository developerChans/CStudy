#include <stdio.h>

int n, count;

int abs(int k) {
    if(k < 0) {
        return (-1) * k;
    } else {
        return k;
    }
}
int check(int* board, int rowNum) {
    for (int i = 0; i < rowNum; i++) {
        if(( board[rowNum] == board[i] ) || ( rowNum-i == abs(board[rowNum] - board[i]) )){
            /*
                1. 같은 세로 줄에 이미 존재 하는 경우 (board[x]의 값이 세로 인덱스 값이므로 같으면 같은 세로줄에 존재)
                2. 대각선에 존재하는 경우 가로 인덱스와 세로 인덱스의 차가 같게 된다. 따라서 절대값 함수를 사용한다.
                둘 중 하나라도 만족 못 할 시에는 퀸을 둘 수 없음
            */
            return 0;
        }
    }
    return 1;
}
// 각 queens 함수 마다 가로 줄 인덱스를 넣어서 가로에 대한 중복을 배제
void nqueens(int* board, int rowNum) {
    if(rowNum == n) {
        count++;
        return;
    }
    for (int i = 0; i < n; i++) {
        board[rowNum] = i; // rowNum 번째 가로 줄에 어느 한 곳
        if(check(board,rowNum)) {
            nqueens(board, rowNum+1); // 해당 줄 배치 
        }
    }
}
int main() {
    scanf("%d", &n);
    int board[n];
    nqueens(board, 0);
    printf("%d", count);
}