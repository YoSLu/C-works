#include <stdio.h>
#include <ctype.h>

int main(void){
    char c;
    int cal[5]={0};
    printf("�п�J���N�r��\n");
    while (scanf("%c", &c) != EOF) {
        if (isalnum(c)){
            if (isalpha(c)){
                cal[1]++;
                switch (c){
                case 'a': case 'e': case 'i' : case 'o':  case 'u':
                    cal[2]++;
                    break;
                default:
                    cal[3]++;
                    break;
                }
            }
            else {
                cal[0]++;
            }
        }
        else {
            cal[4]++;
        }
    }
    printf("�Ʀr=%d��\n�r��=%d��\n����=%d��\n�l��=%d��\n�_�Ǧr��%d��", cal[0], cal[1], cal[2], cal[3], cal[4]-1);//�n���������r��
    return 0;
}
