#include <stdio.h>
#include <stdlib.h>
#define max 9

int board[max][max];
int row[max][max+1];
int column[max][max+1];
int squareNum[max][max+1];


/*
    가로의 인덱스를 3으로 나눈 몫에서 3을 곱하고 세로의 인덱스를 3으로 나눈 몫으로 더해주면
    왼쪽 위부터 1 부터 오른쪽 아래 사각형 part 까지 9가 된다.
*/
int square(int x, int y) {
    return ((x / 3) * 3 + (y / 3));
}
void sudoku(int n) {
    if(n == 81) {
        return;
    }
    /*
        x와 같은 경우 0~8까지 첫번째 가로줄 (인덱스 상으론 0) 9~17까지 두번째 가로줄...
        72~80까지 9번째 가로줄(인덱스 상으로 8)
        y와 같은 경우 0~8번쨰 세로 줄이 계속 반복된다.
    */
    int x = n / max;
    int y = n % max;

    if(board[x][y] == 0) {
        for(int i = 1; i < 10; i++) {
            if(row[x][y] == 0 && column[x][y] == 0 && squareNum[square(x,y)][i] == 0) {
                row[x][y] = column[x][y] = squareNum[square(x,y)][i] = 1;
                board[x][y] = i;
                sudoku(n + 1);
                /*
                    만약 조건에 맞지 않아서 sudoku 함수가 끝나게 될 경우 바꾸었던
                    값을 다시 0으로 바꾸어주어야 바뀐상태가 그대로 유지되지 않음
                */
                board[x][y] = 0;
                row[x][y] = column[x][y] = squareNum[square(x,y)][i] = 0;
            }
        }
    } else {
        // 현재 스도쿠 보드에 숫자가 있는 경우는 숫자를 바꿀 수 없기에 바로 다음 칸을 고려한다.
        sudoku(n+1);
    }

}

int main() {
    for(int i = 0; i < max; i++) {
        for(int j = 0; j < max; j++) {
            scanf("%d", &board[i][j]);
            if(board[i][j] != 0) {
                row[i][board[i][j]] = 1; // 해당 가로줄에 입력한 board[i][j] 값이 존재
                column[j][board[i][j]] = 1; // 해당 세로줄에 입력한 board[i][j] 값이 존재
                squareNum[square(i,j)][board[i][j]] = 1; // 현재 위치의 사각형 번호에 board[i][j] 값이 존재
            }
        }
    }

    sudoku(0);

    printf("\n\n");
    for(int j = 0; j < 9; j++) {
        for(int k = 0; k < 9; k++) {
            printf("%d ",board[j][k]);
        }
        printf("\n");
    }
    return 0;
}