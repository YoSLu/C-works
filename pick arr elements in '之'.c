#include <stdio.h>

int main(){
    int arr [20][20]={0};
    int i, j, k;
    int m, n;
    printf("�п�J�x�}����B�C�� (��<20)\n");
    scanf("%d%d", &m, &n);
    printf("�Ш̧ǿ�J�x�}������\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
        scanf("%d", &(arr[i][j]));
        }
    }
    printf("�H�U�O�x�}�����T�{\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("�H�U�C�X�Ҧ��j��۾F����������\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            if (arr[i][j]>arr[i+1][j] && arr[i][j]>arr[i-1][j] && arr[i][j]>arr[i][j+1] && arr[i][j]>arr[i][j-1]){
                printf("��%d��%d�C��%d ", i+1, j+1, arr[i][j]);
            }
        }
        printf("\n");
    }

    printf("�Τ��r�ΦC�|����\n");
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
    printf("�C�|�׹﨤����\n");
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



