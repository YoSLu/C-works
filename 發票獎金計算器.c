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
        printf("\n頭獎獎金20萬");
        money=200000;
        break;
    case 2:
        printf("\n二獎獎金4萬");
        money=40000;
        break;
    case 3:
        printf("\n三獎獎金1萬");
        money=10000;
        break;
    case 4:
        printf("\n四獎獎金4000");
        money=4000;
        break;
    case 5:
        printf("\n五獎獎金1000");
        money=1000;
        break;
    case 6:
        printf("\n末獎獎金200");
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
    printf("輸入本期發票中獎號碼，前三組特獎，後三組頭獎:\n");
    for (i=0; i<6; i++){
        scanf("%d", &prizenumber[i]);
    }
    printf("\n確認中獎號碼:");
    for (i=0; i<6; i++){
        printf("%d ", prizenumber[i]);
    }
    printf("\n輸入最多十組發票對獎號碼:\n");
    for (i=0; i<10; i++){
        scanf("%d ", &ticketnumber[i]);
    }
    for (i=0; i<10;i++){
        for (int j=0; j<3; j++){
            if (ticketnumber[i]==prizenumber[j]){
                printf("第%d張中特獎，獎金200萬", i+1);
                sum_of_money+=2000000;
            }
        }
    }
    for (i=0; i<10;i++){
        for (int j=3; j<6; j++){
            sum_of_money+=prize (prizenumber[j],ticketnumber[i]);
        }
    }
    printf("\n總獎金=%d元", sum_of_money);
}



