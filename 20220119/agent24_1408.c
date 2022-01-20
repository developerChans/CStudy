#include <stdio.h>

int main() {
    int realTime[3];
    int startTime[3];

    scanf("%d:%d:%d",&realTime[0],&realTime[1],&realTime[2]);
    scanf("%d:%d:%d",&startTime[0],&startTime[1],&startTime[2]);

    int realTimeBySecond = realTime[0] * 3600 + realTime[1] * 60 + realTime[2];
    int startTimeBySecond = startTime[0] * 3600 + startTime[1] * 60 + startTime[2];

    int resultBySecond;
    if(realTimeBySecond > startTimeBySecond) {
        resultBySecond = 24 * 60 * 60 - (realTimeBySecond - startTimeBySecond);
    } else {
        resultBySecond = startTimeBySecond - realTimeBySecond;
    }

    int resulthour, resultMinute, resultSecond;
    resulthour = resultBySecond / 3600;
    resultMinute = (resultBySecond % 3600) / 60;
    resultSecond = (resultBySecond % 3600) % 60;

    printf("%02d:%02d:%02d\n",resulthour, resultMinute, resultSecond);
    return 0;
}
