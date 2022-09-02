#include <stdio.h>

int main(){
    char a[20];
    char b[20];
    int A, B = 0;
    int i, j;
    printf("enter two 4 digits number without replicate\n");
    scanf("%s %s", &a, &b);


    for (i=0; i<4; i++){
        for (j=1; j<(4-i); j++){
            if (a[i] == a[i+j]) {
                printf("replicate!\n");
                system ("pause");
            }
            else if (b[i] == b[i+j]){
                printf("replicate!\n");
                system ("pause");
            }
            else continue;
        }
    }

    for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            if(a[i] == b[j]){
                if(i == j){
                    A++;
                }
                else B++;
            }
            else continue;
        }
    }
    printf("the input has %dA%dB", A, B);
}
