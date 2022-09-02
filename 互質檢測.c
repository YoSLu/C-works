#include <stdio.h>

int huzi (int a, int b){
    int check=1;
    int bigger, smaller;
    if (a>b){
        bigger=a;
        smaller=b;
    }
    else if (a==b){
        return check=0;
    }
    else {
        bigger=b;
        smaller=a;
    }
    int yinshu_of_small[smaller];
    yinshu_of_small[0]=1;
    int smallseq=1;
    for (int i=2; i*i<=smaller; i++){
        if (smaller%i==0){
            yinshu_of_small[smallseq]=i;
            smallseq++;
            yinshu_of_small[smallseq]=smaller/i;
            smallseq++;
        }
        else{
            continue;
        }
    }
    for (int i=1; i<smallseq; i++){
        if (bigger%yinshu_of_small[i]==0){
            check=0;
            break;
        }
        else{
            check=1;
        }
    }
    return check;
}

int main(){
    int n, i;
    int count=0;
    printf("要做幾個正整數?");
    scanf("%d", &n);
    int arr[n];
    printf("\n輸入檢測互質的正整數元素");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("\n確認方陣元素--------------");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n呼叫互質函數--------------");
    for (i=0; i<(n-1); i++){
        for (int j=1; j<(n-i); j++){
            count+=huzi(arr[i], arr[i+j]);
        }
    }
    printf("\n輸入正整數中有%d組互質", count);
}



