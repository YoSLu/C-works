#include
int main(){
    char quest[30];
    printf("enter the quest string\n");
    scanf("%s", &quest);
    int length = strlen(quest);
    switch (quest [length-1]){
        case 'h':
            switch  (quest [length-2] ){
            case 'c': case 's':
            quest[length] = 'e';
            quest[length+1] = 's';
            break;
            default: break;
            }
            break;
        case 'x': case 's': case 'z':
            quest[length] = 'e';
            quest[length+1] = 's';
            break;
        case 'y':
            switch (quest [length-2] ){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                quest[length] = 's';
                break;
            default:
                quest[length-1] = 'i';
                quest[length]= 'e';
                quest[length+1] = 's';
            }
            break;
        default:
            quest[length] = 's';
    }
    printf("the multiple form of quest is ");
    for (int i=0; i<length+2; i++){
        printf("%c", quest[i]);
    }
}
