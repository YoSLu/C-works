#include <stdio.h>

int prize (int a, int b){
    int num=7;
    int money=0;
    int multiplies=1000;
    int temp;
    if (a>b){
        temp=a-b;
    }
    else{
        temp=b-a;
    }
    if (temp%multiplies==0){
        if (b==a){
            num=1;
        }
        else {
            while (temp%multiplies==0){
                num--;
                multiplies*=10;
            }
        }
    }
    switch (num) {
    case 1:
        printf("\n�Y������20�U");
        money=200000;
        break;
    case 2:
        printf("\n�G������4�U");
        money=40000;
        break;
    case 3:
        printf("\n�T������1�U");
        money=10000;
        break;
    case 4:
        printf("\n�|������4000");
        money=4000;
        break;
    case 5:
        printf("\n��������1000");
        money=1000;
        break;
    case 6:
        printf("\n��������200");
        money=200;
        break;
    }
    return money;
}

int main(){
    int prizenumber[6]={0};
    int ticketnumber[10]={0};
    int i, n, count;
    int sum_of_money=0;
    printf("��J�����o���������X�A�e�T�կS���A��T���Y��:\n");
    for (i=0; i<6; i++){
        scanf("%d", &prizenumber[i]);
    }
    printf("\n�T�{�������X:");
    for (i=0; i<6; i++){
        printf("%d ", prizenumber[i]);
    }
    printf("\n��J�̦h�Q�յo��������X:\n");
    for (i=0; i<10; i++){
        scanf("%d ", &ticketnumber[i]);
    }
    for (i=0; i<10;i++){
        for (int j=0; j<3; j++){
            if (ticketnumber[i]==prizenumber[j]){
                printf("��%d�i���S���A����200�U", i+1);
                sum_of_money+=2000000;
            }
        }
    }
    for (i=0; i<10;i++){
        for (int j=3; j<6; j++){
            sum_of_money+=prize (prizenumber[j],ticketnumber[i]);
        }
    }
    printf("\n�`����=%d��", sum_of_money);
}



