#include <stdio.h>  //初始化，判斷空，判斷滿
#include <stdlib.h> //清空，消滅，push, pop, pick

#define maxlen 20

typedef struct {
    char name[10];
    int age;
}Data;

typedef struct {
    int top;
    Data data[maxlen];
}stack;

stack *init(){
    stack *p = (stack *)malloc(sizeof(stack));
    if (!p){
        printf("run out of memory!\n");
        return NULL;
    }
    p->top = 0; //若要求記憶體成功，指標設成0並傳回
    return p;
}

int empty (stack *p){
    return (p->top == 0);   //用判斷句決定t的值並傳回，比if少寫幾行
}

int full(stack *p){
    return (p->top == maxlen);
}

void clear(stack *p){
    if (p){
        p->top = 0;
    }
}

void freestack(stack *p){
    if(p){
        free(p);
    }
}

int push (stack *p, Data data){ //傳回新增成功與否，所以用int
    if (p->top+1 > maxlen){ //先判斷滿了沒
        printf("stack is full!\n");
        return 0;
    }
    p->data [++p->top] = data;  //位置先+1然後再保存到該位置，其實分開來寫也行
    return 1;
}

Data pop (stack *p){
    if (p->top == 0){ //先判斷空了沒
        printf("stack is empty!\n");
        exit(0);
    }
    return p->data[p->top--];   //先回傳後再--位置
}

Data pick(stack *p){
    if (p->top == 0){ //先判斷空了沒
        printf("stack is empty!\n");
        exit (0);
    }
    return p->data[p->top];
}

void main(){
    stack *st;
    Data data, data1, picktest;
    char menu;
    st = init();
    printf("入堆疊\n");

    do{
        printf("enter name and age\n");
        scanf("%s%d", data.name, &data.age);
        push (st, data);
        printf("是否還要再加入?\n");
        printf("1. 要 2. 不要\n");
        menu = getche();
        printf("\n");
    }while(menu == '1');

    picktest = pick(st);
    printf("最上面是%s, %d\n", picktest.name, picktest.age);

    printf("現在依序拿出堆疊\n");
    printf("按任意鍵移出堆疊\n");
    getchar();

    do{
        getchar();
        data1 = pop(st);
        printf("拿出來的是%s, %d\n", data1.name, data1.age);
    }while(1);
    freestack(st);
}
