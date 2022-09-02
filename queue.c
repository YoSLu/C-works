#include <stdio.h>  //��l�ơA�[�J�A�R���A���I
#include <stdlib.h> //free�A�^�Ǫ��סA�P�_�ŻP��

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
    q->head = 0; //�Y�n�D�O���馨�\�A�N�Y�����]��0
    q->tail = 0;
    return q;
}

int empty (Q *q){
    return (q->head == q->tail);   //�p�G�Y����m�ۦP�N�O�ŤF
}

int full(Q *q){
    return (q->tail == maxlen); //�p�G���Ѹ�max�@�˴N���F
}

void clear(Q *q){
    if (q){
        q->head = 0;
        q->tail = 0;    //���l���[���@��
    }
}

int enQ (Q *q, Data data){
    if (q->tail == maxlen){ //���P�_���F�S
        printf("queue is full!\n");
        return 0;
    }
    q->data [q->tail++] = data;  //��F����Ntail++
    return 1;
}

Data deQ (Q *q){
    if (q->head == q->tail){ //���P�_�ŤF�S
        printf("queue is empty!\n");
        exit(0);
    }
    return (q->data[q->head++]);   //���^�ǫ�A--��m
}

Data pick(Q *q){
    if (q->head == q->tail){ //���P�_�ŤF�S
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
    printf("�Jqueue\n");

    do{
        printf("enter name and age\n");
        scanf("%s%d", data.name, &data.age);
        enQ (q, data);
        printf("�O�_�٭n�A�[�J?\n");
        printf("1. �n 2. ���n\n");
        menu = getche();
        printf("\n");
    }while(menu == '1');

    picktest = pick(q);
    printf("�̫e���O%s, %d\n", picktest.name, picktest.age);

    printf("�{�b�̧Ǯ��Xqueue\n");
    printf("�����N�����\n");
    getchar();

    do{
        getchar();
        data1 = deQ(q);
        printf("���X�Ӫ��O%s, %d\n", data1.name, data1.age);
    }while(1);
    clear(q);
}
