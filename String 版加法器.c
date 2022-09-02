#include <stdio.h>
#include <string.h>

int main(){
    //先移位，再把位數相加，超過10的減10而後前一位+1存到sum
    char big1[200];
    char big2[200];
    char sum[300]={'\0'};
    char *end;
    int i, j, dev;

    printf("enter 2 num for plus\n");
    scanf("%s %s", &big1, &big2);

    if (strlen(big1) >strlen(big2)){
        dev = strlen(big1) - strlen(big2);
        end = big2;
        for (i = (strlen(big2) -1); i >= 0 ; i--){
            end[i+dev] = end[i];
        }
        for (j=0; j<dev; j++){
            end[j]='0';
        }
    }
    else if (strlen(big1) <strlen(big2)){
        dev = strlen(big2)- strlen(big1);
        end = big1;
        for (i = (strlen(big1)-1) ; i >= 0 ; i--){
            end[i+dev] = end[i];
        }
        for (j=0; j<(dev-1); j++){
            end[j]='0';
        }
    }
    else {
        end = big1;
    }

    if ((big1[0] -'0' + big2[0] -'0') > 9){
        char *b1 = big1;
        char *b2 = big2;
        for (i = (strlen(big1)-1); i >= 0 ; i--){
            b1[i+1] = b1[i];
            b2[i+1] = b2[i];
        }
        big1[0] = '0';
        big2[0] = '0';
    }
    for (i=(strlen(end)-1); i>=0; i--){
        sum[i] += big1[i] -'0' + big2[i] - '0';
        if (sum[i] > 9){
            sum[i]-=10;
            sum[i-1]++;
        }
    }

    for (i=0; i<strlen(end); i++){
        printf("%d", sum[i]);
    }
    printf("\nup is the sum");
}
