#include <stdio.h>  //初始化，加入，刪除，取點
#include <stdlib.h> //free，回傳長度，判斷空與滿

#define maxlen 15

typedef struct {
    char name[10];
    int age;
}Data;

typedef struct queue{
    int head;
    int tail;
    Data data[maxlen];
}Q;

Q *init(){
    Q *q = (Q *)malloc(sizeof(q));
    if (!q){
        printf("run out of memory!\n");
        return NULL;
    }
    q->head = 0; //若要求記憶體成功，將頭尾都設為0
    q->tail = 0;
    return q;
}

int empty (Q *q){
    return (q->head == q->tail);   //如果頭尾位置相同就是空了
}

int full(Q *q){
    return (q->tail == maxlen); //如果屁股跟max一樣就滿了
}

void clear(Q *q){
    if (q){
        q->head = 0;
        q->tail = 0;    //跟初始化觀念一樣
    }
}

int enQ (Q *q, Data data){
    if (q->tail == maxlen){ //先判斷滿了沒
        printf("queue is full!\n");
        return 0;
    }
    q->data [q->tail++] = data;  //塞了之後將tail++
    return 1;
}

Data deQ (Q *q){
    if (q->head == q->tail){ //先判斷空了沒
        printf("queue is empty!\n");
        exit(0);
    }
    return (q->data[q->head++]);   //先回傳後再--位置
}

Data pick(Q *q){
    if (q->head == q->tail){ //先判斷空了沒
        printf("queue is empty!\n");
        exit (0);
    }
    return (q->data[q->head]);
}

int len(Q *q){
    return ((q->tail - q->head));
}

void main(){
    Q *q;
    Data data, data1, picktest;
    char menu;
    q = init();
    printf("入queue\n");

    do{
        printf("enter name and age\n");
        scanf("%s%d", data.name, &data.age);
        enQ (q, data);
        printf("是否還要再加入?\n");
        printf("1. 要 2. 不要\n");
        menu = getche();
        printf("\n");
    }while(menu == '1');

    picktest = pick(q);
    printf("最前面是%s, %d\n", picktest.name, picktest.age);

    printf("現在依序拿出queue\n");
    printf("按任意鍵執行\n");
    getchar();

    do{
        getchar();
        data1 = deQ(q);
        printf("拿出來的是%s, %d\n", data1.name, data1.age);
    }while(1);
    clear(q);
}
