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
    printf("�п�J�ǥͼƶq�B�ҵ{�ƶq�A�p��10�r\n");
    scanf("%d %d", &student, &course);
    printf("�Ш̧ǿ�J�C�Ӿǥͦb�U���Ҫ����Z\n");
    for (i=0; i<student; i++){
        for (j=0; j<course; j++){
            scanf("%d", &s[i][j]);
        }
    }
    printf("�H�U�O�T�{���G\n");
    for (i=0; i<student; i++){
        printf("�ǥ�%d���Z=", i+1);
        for (j=0; j<course; j++){
            printf("%d ", s[i][j]);
            if ((j+1)%(course)==0){
                printf("\n");
            }
        }
    }
    printf("�H�U�O�@�~���G-----------\n");
    printf("�C��ǥͥ������Z�p�U\n");
    for (i=0; i<student; i++){
        for (j=0; j<course; j++){
            avr_s+=s[i][j];
            if ((j+1)%(course)==0){
                printf("�ǥ�%d�������Z=%d\n", i+1, avr_s/course);
                avr_s=0;
            }
        }
    }
    printf("�C���ҥ������Z�p�U\n");
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
          printf("�ҵ{%d�������Z=%d\n",k+1, avr_c[k]/student);
    }
    printf("�C�Ӿǥͳ̰��P�̧C���Z�p�U---------------\n");
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
        printf("�ǥ�%d�̰����Z=%d�A�̧C���Z=%d\n", i+1, max_s[i], min_s[i]);
    }
    printf("�C���ҵ{�̰��P�̧C���Z�p�U---------------------\n");
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
        printf("�ҵ{%d�̰����Z=%d�A�̧C���Z=%d\n", j+1, max_c[j], min_c[j]);
    }
}



