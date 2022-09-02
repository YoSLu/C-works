#include <stdio.h>  //初始、尋找單一節點、添加節點
#include <stdlib.h> //得到該點或左右數據、判斷空樹
#include <conio.h>  //清空樹、計算深度、層前中後遍歷

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
    }   //如果要求記憶體成功就載入數據，並設置指向左右分別為NULL
    printf("請輸入root node的data\n");
    scanf("%d", &node->data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

bsttype *find(bsttype *root, Data query){   //輸入root找點
    bsttype *ptr;   //需要一個指向的指標，與待尋找的data
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
    printf("輸入node數據\n");
    fflush(stdin);
    scanf("%d", &newNode->data);
    newNode->left = NULL;
    newNode->right = NULL;

    int found = 0;
    currentNode = root;

    while (!found){ //先判斷與當前點的大小，再判斷是否子樹為空
        if (currentNode->data < newNode->data){
            if (currentNode->right == NULL){
                found = 2;
            }
            else {  //二元搜尋樹的加點實作
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

        switch (found){ //放置的位置用switch實作
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

void pick(bsttype *root){ //注意要回傳指標
    printf("%d\n", root->data);
}

int empty(bsttype *root){
    return !root;   //如果有節點，就不是空樹(空樹的敘述為錯誤即"0")
}

int depth(bsttype *root){
    int leftdep, rightdep, dep;
    if (root == NULL){
        return 0;
    }
    leftdep = depth(root->left);
    rightdep = depth(root->right);
    dep = (leftdep > rightdep) ? (leftdep+1):(rightdep+1);
    return dep; //左比右大對否，對就傳左+1，否就傳右+1
}

void clear(bsttype *root){
    if(root){   //輸入根節點，遞迴的清掉所有子樹，最後再清掉根節點
        clear(root->left);
        clear(root->right);
        clear(root);
        root = NULL;
    }
}

void level(bsttype *root, void (*pick(bsttype *p))){
    bsttype *p; //定義一個按照順序，由指標組成的queue，將元素塞進去再用pick函數印出來
    bsttype *q[maxlen];
    int head = 0;
    int tail = 0;

    if(root){
        tail = (tail+1)%maxlen;  //計算queue tail的號碼
        q[tail] = root; //將指標treenode塞進queue
    }
    while (head != tail){  //表示還沒印完
        head = (head+1)%maxlen;//算頭的位址
        p = q[head];
        pick(p);

        if (p->left != NULL){   //看是否有左子樹，若有則塞入queue
            tail = (tail+1)%maxlen;
            q[tail] = p->left;
        }
        if (p->right != NULL){   //看是否有右子樹，若有則塞入queue
            tail = (tail+1)%maxlen;
            q[tail] = p->right;
        }
    }
}

void DLR(bsttype *root, void(*pick(bsttype *p))){  //前序
    if(root){
        pick(root); //根左右
        DLR(root->left, pick);
        DLR(root->right, pick);
    }
}


void LDR(bsttype *root, void(*pick(bsttype *p))){  //中序
    if(root){
        LDR(root->left, pick);
        pick(root); //左根右
        LDR(root->right, pick);
    }
}


void LRD(bsttype *root, void(*pick(bsttype *p))){  //後序
    if(root){
        LRD(root->left, pick);
        LRD(root->right, pick);
        pick(root); //左右根
    }
}

void main(){
    bsttype *root = NULL;
    char menu;
    void(*bsttype_pick1)(); //指向函數的指標
    bsttype_pick1 = pick;

    root = init();  //初始化根節點
    do{
        printf("選擇是否添加二元樹節點\n");
        printf("0. 否\n1. 是\n");
        menu = getch();
        switch(menu){
            case '1':
                addnode(root, root->data);
                break;
            default:
                ;
        }
    }while(menu != '0');
    printf("此二元樹深度為%d\n", depth(root));
    printf("以下嘗試遍歷\n");

    printf("層序遍歷結果:\n");
    level(root, bsttype_pick1);
    printf("\n");

    printf("前序遍歷結果:\n");
    DLR(root, bsttype_pick1);
    printf("\n");

    printf("中序遍歷結果:\n");
    LDR(root, bsttype_pick1);
    printf("\n");

    printf("後序遍歷結果:\n");
    LRD(root, bsttype_pick1);
    printf("\n");
    clear(root);
}
