#include <stdio.h>

int main(){
    int arr [100]={0};
    int ans [100]={0};
    int i, n;
    int count=0;
    printf("請輸入待判斷的序列長度，2<=n<=100\n");
    scanf("%d", &n);
    if (n<2 || n>100){
        printf("去你的");
    }
    else {
        printf("請依序輸入序列\n");
        for (i=0; i<n; i++){
            scanf("%d", &(arr[i]));
        }
        printf("以下是矩陣元素確認\n");
        for (i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n以下列出最長的回文：\n");
        if (n==2){
            if (arr[0]==arr[1]){
                printf("回文序列為%d %d", arr[0], arr[1]);
            }
            else {
                printf("沒有回文序列");
            }
        }
        else{
            if (n%2==1){
                ans[(n-1)/2]= arr[(n-1)/2];
            }
            else {
                ans[n/2]= arr[n/2];
            }
            for (i=0; i<n/2; i++){
                if (arr[i]!=arr[n-i-1]){
                    break;
                }
                count++;
                ans[i]=arr[i];
                ans[n-i-1]= arr[n-i-1];
            }
            if (count==0){
                printf("沒有回文序列");
            }
            else {
                for (i=0; i<n;i++){
                    printf("%d ", ans[i]);
                }
            }
        }
    }
}




