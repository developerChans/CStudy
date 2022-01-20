#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++) {
        int p;
        scanf("%d",&p);
        int input[p];
        char stringInput[p][22*p];
        int maxIndex =0;
        int maxValue = 0;
        for(int j = 0; j < p; j++) {
            scanf("%d %s",&input[j], stringInput[j]);
            if(maxValue < input[j]) {
                maxValue = input[j];
                maxIndex = j;
            }
        }
        printf("%s\n", stringInput[maxIndex]);
    }
}
