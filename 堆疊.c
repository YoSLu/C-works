#include <stdio.h>  //��l�ơA�P�_�šA�P�_��
#include <stdlib.h> //�M�šA�����Apush, pop, pick

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
    p->top = 0; //�Y�n�D�O���馨�\�A���г]��0�öǦ^
    return p;
}

int empty (stack *p){
    return (p->top == 0);   //�ΧP�_�y�M�wt���ȨöǦ^�A��if�ּg�X��
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

int push (stack *p, Data data){ //�Ǧ^�s�W���\�P�_�A�ҥH��int
    if (p->top+1 > maxlen){ //���P�_���F�S
        printf("stack is full!\n");
        return 0;
    }
    p->data [++p->top] = data;  //��m��+1�M��A�O�s��Ӧ�m�A�����}�Ӽg�]��
    return 1;
}

Data pop (stack *p){
    if (p->top == 0){ //���P�_�ŤF�S
        printf("stack is empty!\n");
        exit(0);
    }
    return p->data[p->top--];   //���^�ǫ�A--��m
}

Data pick(stack *p){
    if (p->top == 0){ //���P�_�ŤF�S
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
    printf("�J���|\n");

    do{
        printf("enter name and age\n");
        scanf("%s%d", data.name, &data.age);
        push (st, data);
        printf("�O�_�٭n�A�[�J?\n");
        printf("1. �n 2. ���n\n");
        menu = getche();
        printf("\n");
    }while(menu == '1');

    picktest = pick(st);
    printf("�̤W���O%s, %d\n", picktest.name, picktest.age);

    printf("�{�b�̧Ǯ��X���|\n");
    printf("�����N�䲾�X���|\n");
    getchar();

    do{
        getchar();
        data1 = pop(st);
        printf("���X�Ӫ��O%s, %d\n", data1.name, data1.age);
    }while(1);
    freestack(st);
}
