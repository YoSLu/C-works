#include <stdio.h>

int main(){
    int arr [20][20]={0};
    int i, j, k;
    int m, n;
    printf("請輸入矩陣的行、列數 (需<20)\n");
    scanf("%d%d", &m, &n);
    printf("請依序輸入矩陣內元素\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
        scanf("%d", &(arr[i][j]));
        }
    }
    printf("以下是矩陣元素確認\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("以下列出所有大於相鄰元素的元素\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            if (arr[i][j]>arr[i+1][j] && arr[i][j]>arr[i-1][j] && arr[i][j]>arr[i][j+1] && arr[i][j]>arr[i][j-1]){
                printf("第%d行%d列的%d ", i+1, j+1, arr[i][j]);
            }
        }
        printf("\n");
    }

    printf("用之字形列舉元素\n");
    for (i=0; i<m; i++){
        if (i%2==0){
            for(j=0; j<n; j++){
                printf("%d ", arr[i][j]);
            }
        }
        else {
            for(j=n-1; j>=0; j--){
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    printf("列舉斜對角元素\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            if (i==j){
                printf("%d ", arr[i][j]);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }
}



