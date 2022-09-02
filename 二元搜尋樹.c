#include <stdio.h>  //��l�B�M���@�`�I�B�K�[�`�I
#include <stdlib.h> //�o����I�Υ��k�ƾڡB�P�_�ž�
#include <conio.h>  //�M�ž�B�p��`�סB�h�e����M��

#define maxlen 20

typedef int Data;

typedef struct BST {
    Data data;
    struct BST *left;
    struct BST *right;
}bsttype;

bsttype *init(){
    bsttype *node = (bsttype *)malloc(sizeof(bsttype));
    if(node == NULL){
        printf("run out of memory!\n");
        return NULL;
    }   //�p�G�n�D�O���馨�\�N���J�ƾڡA�ó]�m���V���k���O��NULL
    printf("�п�Jroot node��data\n");
    scanf("%d", &node->data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

bsttype *find(bsttype *root, Data query){   //��Jroot���I
    bsttype *ptr;   //�ݭn�@�ӫ��V�����СA�P�ݴM�䪺data
    if (root == NULL){
        return NULL;
    }
    if (root->data == query){ // check node
        return root;
    }
    else {
        if (ptr = find(root->left, query)){
            return ptr; //check left subtree
        }
        else if (ptr = find(root->right, query)){
            return ptr; //check right subtree
        }
        else {
            return NULL;
        }
    }
}

bsttype *addnode(bsttype *root, Data data){
    bsttype *newNode, *currentNode;
    newNode = (bsttype*)malloc(sizeof(bsttype));

    if(!newNode){
        printf("run out of memory!\n");
        return NULL;
    }
    printf("��Jnode�ƾ�\n");
    fflush(stdin);
    scanf("%d", &newNode->data);
    newNode->left = NULL;
    newNode->right = NULL;

    int found = 0;
    currentNode = root;

    while (!found){ //���P�_�P��e�I���j�p�A�A�P�_�O�_�l�𬰪�
        if (currentNode->data < newNode->data){
            if (currentNode->right == NULL){
                found = 2;
            }
            else {  //�G���j�M�𪺥[�I��@
                currentNode = currentNode->right;
            }
        }
        else if (currentNode->data > newNode->data){
            if (currentNode->left == NULL){
                found = 1;
            }
            else {
                currentNode = currentNode->left;
            }
        }
        else {
            found = 3;
        }
    }

        switch (found){ //��m����m��switch��@
        case 1:
            currentNode->left = newNode;
            break;
        case 2:
            currentNode->right = newNode;
            break;
        default:
            printf("data already exist, add fail\n");
            free(newNode);
            newNode = NULL;
    }

    return newNode;
}

bsttype *getleft(bsttype *root){
    if (root){
        return root->left;
    }
    return NULL;
}


bsttype *getright(bsttype *root){
    if (root){
        return root->right;
    }
    return NULL;
}

void pick(bsttype *root){ //�`�N�n�^�ǫ���
    printf("%d\n", root->data);
}

int empty(bsttype *root){
    return !root;   //�p�G���`�I�A�N���O�ž�(�ž𪺱ԭz�����~�Y"0")
}

int depth(bsttype *root){
    int leftdep, rightdep, dep;
    if (root == NULL){
        return 0;
    }
    leftdep = depth(root->left);
    rightdep = depth(root->right);
    dep = (leftdep > rightdep) ? (leftdep+1):(rightdep+1);
    return dep; //����k�j��_�A��N�ǥ�+1�A�_�N�ǥk+1
}

void clear(bsttype *root){
    if(root){   //��J�ڸ`�I�A���j���M���Ҧ��l��A�̫�A�M���ڸ`�I
        clear(root->left);
        clear(root->right);
        clear(root);
        root = NULL;
    }
}

void level(bsttype *root, void (*pick(bsttype *p))){
    bsttype *p; //�w�q�@�ӫ��Ӷ��ǡA�ѫ��вզ���queue�A�N������i�h�A��pick��ƦL�X��
    bsttype *q[maxlen];
    int head = 0;
    int tail = 0;

    if(root){
        tail = (tail+1)%maxlen;  //�p��queue tail�����X
        q[tail] = root; //�N����treenode��iqueue
    }
    while (head != tail){  //����٨S�L��
        head = (head+1)%maxlen;//���Y����}
        p = q[head];
        pick(p);

        if (p->left != NULL){   //�ݬO�_�����l��A�Y���h��Jqueue
            tail = (tail+1)%maxlen;
            q[tail] = p->left;
        }
        if (p->right != NULL){   //�ݬO�_���k�l��A�Y���h��Jqueue
            tail = (tail+1)%maxlen;
            q[tail] = p->right;
        }
    }
}

void DLR(bsttype *root, void(*pick(bsttype *p))){  //�e��
    if(root){
        pick(root); //�ڥ��k
        DLR(root->left, pick);
        DLR(root->right, pick);
    }
}


void LDR(bsttype *root, void(*pick(bsttype *p))){  //����
    if(root){
        LDR(root->left, pick);
        pick(root); //���ڥk
        LDR(root->right, pick);
    }
}


void LRD(bsttype *root, void(*pick(bsttype *p))){  //���
    if(root){
        LRD(root->left, pick);
        LRD(root->right, pick);
        pick(root); //���k��
    }
}

void main(){
    bsttype *root = NULL;
    char menu;
    void(*bsttype_pick1)(); //���V��ƪ�����
    bsttype_pick1 = pick;

    root = init();  //��l�Ʈڸ`�I
    do{
        printf("��ܬO�_�K�[�G����`�I\n");
        printf("0. �_\n1. �O\n");
        menu = getch();
        switch(menu){
            case '1':
                addnode(root, root->data);
                break;
            default:
                ;
        }
    }while(menu != '0');
    printf("���G����`�׬�%d\n", depth(root));
    printf("�H�U���չM��\n");

    printf("�h�ǹM�����G:\n");
    level(root, bsttype_pick1);
    printf("\n");

    printf("�e�ǹM�����G:\n");
    DLR(root, bsttype_pick1);
    printf("\n");

    printf("���ǹM�����G:\n");
    LDR(root, bsttype_pick1);
    printf("\n");

    printf("��ǹM�����G:\n");
    LRD(root, bsttype_pick1);
    printf("\n");
    clear(root);
}
