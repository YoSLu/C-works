#include <stdio.h>

int main(){
    int student, course;
    int s[10][10];
    int i, j, k;
    int avr_s=0;
    int avr_c[10]={0};
    int max_s[10]={0};
    int min_s[10]={0};
    int max_c[10]={0};
    int min_c[10]={0};
    printf("請輸入學生數量、課程數量，小於10字\n");
    scanf("%d %d", &student, &course);
    printf("請依序輸入每個學生在各門課的成績\n");
    for (i=0; i<student; i++){
        for (j=0; j<course; j++){
            scanf("%d", &s[i][j]);
        }
    }
    printf("以下是確認結果\n");
    for (i=0; i<student; i++){
        printf("學生%d成績=", i+1);
        for (j=0; j<course; j++){
            printf("%d ", s[i][j]);
            if ((j+1)%(course)==0){
                printf("\n");
            }
        }
    }
    printf("以下是作業結果-----------\n");
    printf("每位學生平均成績如下\n");
    for (i=0; i<student; i++){
        for (j=0; j<course; j++){
            avr_s+=s[i][j];
            if ((j+1)%(course)==0){
                printf("學生%d平均成績=%d\n", i+1, avr_s/course);
                avr_s=0;
            }
        }
    }
    printf("每門課平均成績如下\n");
    for (i=0; i<student; i++){
        for (j=0; j<course; j++){
            if (k==course){
                k=0;
                avr_c[k]+=s[i][j];
                k++;
            }
            else {
                avr_c[k]+=s[i][j];
                k++;
            }
        }
    }
    for (k=0; k<course; k++){
          printf("課程%d平均成績=%d\n",k+1, avr_c[k]/student);
    }
    printf("每個學生最高與最低成績如下---------------\n");
    for (i=0; i<10; i++){
        min_s[i]=max_s[i]+101;
    }

    for (i=0; i<student; i++){
        for (j=0; j<course; j++){
            if (max_s[i]<s[i][j]){
                max_s[i]=s[i][j];
            }
            if (min_s[i]>s[i][j]){
                min_s[i]=s[i][j];
            }
        }
        printf("學生%d最高成績=%d，最低成績=%d\n", i+1, max_s[i], min_s[i]);
    }
    printf("每門課程最高與最低成績如下---------------------\n");
    for (i=0; i<10; i++){
        min_c[i]=max_c[i]+101;
    }
    for (i=0; i<student; i++){
        for (j=0; j<course; j++){
            if (max_c[j]<s[i][j]){
                max_c[j]=s[i][j];
            }
            if (min_c[j]>s[i][j]){
                min_c[j]=s[i][j];
            }
        }
    }
    for (j=0; j<course; j++){
        printf("課程%d最高成績=%d，最低成績=%d\n", j+1, max_c[j], min_c[j]);
    }
}



