#include <stdio.h>

int main(){
    int i, j, k;
    int m, n;
    int cross, ding, turn, dead, garden, count=0;
    cross=ding=turn=dead=garden=count=0;
    int city[10][10]={0};
    printf("�п�J�������j�pn��m�C�A2<=m, n<=100\n");
    scanf("%d %d", &m ,&n);
    if (n<2 || n>100 || m<2 || m>100){
        printf("�h�A��");
    }
    else {
        printf("�п�J�������D�����e�A1���D���A0���ؿv\n");
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                scanf("%d", &city[i][j]);
            }
        }
        printf("�H�U�O�������e�T�{\n");
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                printf("%d ", city[i][j]);
            }
            printf("\n");
        }
        printf("�H�U�O�C�X�Q�r�B�B�r�B���s�B���ѡB�x��ƶq\n");
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
    printf("������\n�Q�r%d��\n�B�r%d��\n���s%d��\n����%d��\n�x��%d��", cross, ding, turn, dead, garden);
    }
}
//



