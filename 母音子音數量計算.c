#include <stdio.h>
#include <ctype.h>

int main(void){
    char c;
    int cal[5]={0};
    printf("請輸入任意字元\n");
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
    printf("數字=%d個\n字母=%d個\n母音=%d個\n子音=%d個\n奇怪字元%d個", cal[0], cal[1], cal[2], cal[3], cal[4]-1);//要扣掉結束字元
    return 0;
}
