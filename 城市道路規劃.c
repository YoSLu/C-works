#include <stdio.h>

int main(){
    int i, j, k;
    int m, n;
    int cross, ding, turn, dead, garden, count=0;
    cross=ding=turn=dead=garden=count=0;
    int city[10][10]={0};
    printf("請輸入城市的大小n行m列，2<=m, n<=100\n");
    scanf("%d %d", &m ,&n);
    if (n<2 || n>100 || m<2 || m>100){
        printf("去你的");
    }
    else {
        printf("請輸入城市的道路內容，1為道路，0為建築\n");
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                scanf("%d", &city[i][j]);
            }
        }
        printf("以下是城市內容確認\n");
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                printf("%d ", city[i][j]);
            }
            printf("\n");
        }
        printf("以下是列出十字、丁字、轉彎、死巷、庭園數量\n");
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                if (city[i][j]==0){
                    continue;
                }
                else {
                    count=0;
                    if (city[i-1][j]==1){
                        count++;
                    }
                    if (city[i+1][j]==1){
                        count++;
                    }
                    if (city[i][j-1]==1){
                        count++;
                    }
                    if (city[i][j+1]==1){
                        count++;
                    }
                    switch(count){
                    case 0:
                        garden++;
                        break;
                    case 1:
                        dead++;
                        break;
                    case 2:
                        if (city[i+1][j]==city[i-1][j] || city[i][j-1]==city[i][j+1]|)
                            continue;
                        else
                            turn++;
                        break;
                    case 3:
                        ding++;
                        break;
                    case 4:
                        cross++;
                        break;
                    }
                }
            }
        }
    printf("本市中\n十字%d個\n丁字%d個\n轉彎%d個\n死巷%d個\n庭園%d個", cross, ding, turn, dead, garden);
    }
}
//



