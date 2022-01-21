#include <stdio.h>

int check(int(*board)[9], int a, int b) {
    for(int i = 0; i < 9; i++) { // 세로 줄 중복 찾기
        if(board[i][b] == board[a][b]) {
            return 0;
        }
    }
    for(int i = 0; i < 9; i++) { // 가로 줄 중복 찾기
        if(board[a][i] == board[a][b]) {
            return 0;
        }
    }
    if(a / 3 == 0) { // 왼쪽 3박스
        if(b / 3 ==0) { // 1번 구역
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
        else if(b / 3 == 1) { // 4번 구역
            for(int i = 0; i < 3; i++) {
                for(int j = 3; j < 6; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
        else if(b / 3 == 2) {
            for(int i = 0; i < 3; i++) { // 7번 구역
                for(int j = 6; j < 9; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
    }
    else if (a / 3 == 1) { // 중간 박스
        if(b / 3 ==0) { // 2번 구역
            for(int i = 3; i < 6; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
        else if(b / 3 == 1) { // 5번 구역
            for(int i = 3; i < 6; i++) {
                for(int j = 3; j < 6; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
        else if(b / 3 == 2) {
            for(int i = 3; i < 6; i++) { // 8번 구역
                for(int j = 6; j < 9; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
    }
    else if(a / 3 == 2) {
        if(b / 3 ==0) { // 우측 박스
            for(int i = 6; i < 9; i++) { // 3번 구역
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
        else if(b / 3 == 1) {
            for(int i = 6; i < 6; i++) { // 6번 구역
                for(int j = 3; j < 6; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
        else if(b / 3 == 2) {
            for(int i = 6; i < 9; i++) { // 9번 구역
                for(int j = 6; j < 9; j++) {
                    if(board[i][j] == board[a][b]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
void sudoku(int (*board)[9], int n) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == 0) {
                board[i][j] = n;
                if(check(board,i,j)) {
                    sudoku(board,n);
                }    
            }
        }    
    }
}
int main() {
    int arr[9][9];
    for(int i = 0; i < 9; i++){
        scanf("%d %d %d %d %d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4], &arr[i][5], &arr[i][6], &arr[i][7], &arr[i][8]);
    }

    for(int number = 0; number < 9; number++) {
        sudoku(arr,number);
    }  
    for(int j = 0; j < 9; j++) {
        for(int k = 0; k < 9; k++) {
            printf("%d ",arr[j][k]);
        }
      printf("\n");
    }
    
}