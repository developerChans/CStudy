#include <stdio.h>
#include <stdlib.h>

int check(int** board, int rowNum, int columnNum, int inputNum) {
    for(int i = 0; i < 9; i++) { // 세로 줄 중복 찾기
        if(board[i][columnNum] == inputNum) {
            return 0;
        }
    }
    
    for(int j = 0; j < 9; j++) { // 가로 줄 중복 찾기
        if(board[rowNum][j] == inputNum) {
            return 0;
        }
    }

    if(rowNum / 3 == 0) { // 왼쪽 3박스
        if(columnNum / 3 == 0) { // 1번 구역
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    } 
                }
            }
        }
        else if(columnNum / 3 == 1) { // 4번 구역
            for(int i = 0; i < 3; i++) {
                for(int j = 3; j < 6; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    }
                }
            }
        }
        else {
            for(int i = 0; i < 3; i++) { // 7번 구역
                for(int j = 6; j < 9; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    }
                }
            }
        }
    }
    else if (rowNum / 3 == 1) { // 중간 박스
        if(columnNum / 3 == 0) { // 2번 구역
            for(int i = 3; i < 6; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    }
                }
            }
        }
        else if(columnNum / 3 == 1) { // 5번 구역
            for(int i = 3; i < 6; i++) {
                for(int j = 3; j < 6; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    }
                }
            }
        }
        else {
            for(int i = 3; i < 6; i++) { // 8번 구역
                for(int j = 6; j < 9; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    }
                }
            }
        }
    }
    else if(rowNum / 3 == 2) { // 우측 박스
        if(columnNum / 3 == 0) {
            for(int i = 6; i < 9; i++) { // 3번 구역
                for(int j = 0; j < 3; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    }
                }
            }
        }
        else if(columnNum / 3 == 1) {
            for(int i = 6; i < 9; i++) { // 6번 구역
                for(int j = 3; j < 6; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    }
                }
            }
        }
        else {
            for(int i = 6; i < 9; i++) { // 9번 구역
                for(int j = 6; j < 9; j++) {
                    if(board[i][j] == inputNum) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int checknoInput(int** board, int rowNum, int inputNum) {
    int m;
    for(int m = 0; m < 9; m ++) {
        if(board[rowNum][m] == inputNum) {
            return 1;
        }
    }
    return 0;
}

void sudoku(int** board, int columnNum, int inputNum) {
    if(columnNum == 9) {
        return;
    }

    for(int rowNum = 0; rowNum < 9; rowNum++) {
        if(checknoInput(board,rowNum,inputNum)) {
            sudoku(board, columnNum+1, inputNum);
        }
        else{
            if(board[rowNum][columnNum] == 0) {
                board[rowNum][columnNum] = inputNum;
                if(check(board,rowNum,columnNum,inputNum)) {
                    sudoku(board, columnNum+1, inputNum);
                    board[rowNum][columnNum] = 0;
                }
            }
        }
    }
}

int main() {
    int** arr = (int**)malloc(sizeof(int*)*9);
    for(int k = 0; k < 9; k++) {
        arr[k] = (int*)malloc(sizeof(int)*9);
    }
    for(int i = 0; i < 9; i++){
        scanf("%d %d %d %d %d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4], &arr[i][5], &arr[i][6], &arr[i][7], &arr[i][8]);
    }
    printf("\n");
    printf("\n");
    for(int n = 1; n < 10; n++) {
        sudoku(arr, 0, n);  
    }
    for(int j = 0; j < 9; j++) {
        for(int k = 0; k < 9; k++) {
            printf("%d ",arr[j][k]);
        }
      printf("\n");
    }
    free(arr[0]);
    free(arr);
}