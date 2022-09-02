#include <stdio.h>

int square (int n){
    if (n==1){
        return 1;
    }
    else {
        return n * n + square (n-1);
    }
}

int pyramid(int n){
    int dev=0;
    int m;
    if (n == 1){
        printf("1");
    }
    else {
        for (m=0; dev<n; m++){
            dev = square (m+1);
        }
        printf("%d + ", square(m-1));
        return pyramid(n-square(m-1));
    }
}

int main(){
    int n;
    printf("enter the number wanna divide to pyramid num\n");
    scanf("%d", &n);
    pyramid(n);

}


