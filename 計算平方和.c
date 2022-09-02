#include <stdio.h>

int square (int n){
    if (n==1){
        return 1;
    }
    else {
        return n * n + square (n-1);
    }
}

int main(){
    //2^2=(1+1)^2=1^2+2*1*1+1^2
    int n, i;
    printf("input a num to cal the sum of n square\n");
    scanf("%d", &n);
    printf("sum is %d", square(n));
}
