#include <stdio.h>

void sudoku(int (*board)[9], int n) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == 0) {
                board[i][j] == n;
                if(i / 3 == 0) {
                    if(j / 3 ==0) {
                        for(int k = 0; k < 3; k++) {
                            for(int)
                        }
                    }
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



  
    for(int j = 0; j < 9; j++) {
        for(int k = 0; k < 9; k++) {
            printf("%d ",arr[j][k]);
        }
      printf("\n");
    }
    
}