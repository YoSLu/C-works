#include <stdio.h>

int main(){
    int arr [100]={0};
    int ans [100]={0};
    int i, n;
    int count=0;
    printf("�п�J�ݧP�_���ǦC���סA2<=n<=100\n");
    scanf("%d", &n);
    if (n<2 || n>100){
        printf("�h�A��");
    }
    else {
        printf("�Ш̧ǿ�J�ǦC\n");
        for (i=0; i<n; i++){
            scanf("%d", &(arr[i]));
        }
        printf("�H�U�O�x�}�����T�{\n");
        for (i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n�H�U�C�X�̪����^��G\n");
        if (n==2){
            if (arr[0]==arr[1]){
                printf("�^��ǦC��%d %d", arr[0], arr[1]);
            }
            else {
                printf("�S���^��ǦC");
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
                printf("�S���^��ǦC");
            }
            else {
                for (i=0; i<n;i++){
                    printf("%d ", ans[i]);
                }
            }
        }
    }
}




