#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;
    int i, j;
    printf("please enter m, n for array row and col\n");
    scanf("%d %d", &m, &n);
    int s[m][n], turn180[m][n];
    int turn90[n][m], turn270[n][m];
    printf("time to enter elements in array\n");

    for (i=0; i<m; i++){
        for (j=0; j<n; j++) {
            scanf(" %c", &s[i][j]);
        }
    }
    printf("\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++) {
            printf(" %c", s[i][j]);
        }
        printf("\n");
    }

    printf("time to turn for 90 degree:\n");

    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            turn90[j][n-i]=s[i][j];
        }
    }
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            printf (" %c", turn90[i][j]);
        }
        printf("\n");
    }

    printf("time to turn for 180 degree:\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            turn180[m-i-1][n-j-1]=s[i][j];
        }
    }
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf (" %c", turn180[i][j]);
        }
        printf("\n");
    }
    printf("time to turn for 270 degree:\n");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            turn270[n-j-1][i]=s[i][j];
        }
    }
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            printf (" %c", turn270[i][j]);
        }
        printf("\n");
    }
}
