#include <stdio.h>  //加到尾巴，加到頭，找節點，顯示全部，插入，刪除，回傳總長度
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[10];
    char name[10];
    int age;
}Data;

typedef struct node{
    Data data;
    struct node *nextnode;
}Chain_node;

Chain_node *addend (Chain_node *head, Data getdata){
    Chain_node *Newnode, *temp;
    Newnode = (Chain_node *)malloc(sizeof(Chain_node));
    if (!Newnode){
        printf("要求記憶體失敗!\n");
        return NULL;
    }
    else { //前兩句先處理new node自己的事情
        Newnode->data = getdata; //data放到new node的data區
        Newnode->nextnode = NULL; //由於插入在尾巴，尾巴的下一個當然是指向NULL
        //接下來處理與原list的關係

        if (head == NULL){ //如果頭是NULL，表示list只有newnode一個，將head指向node
            head = Newnode;
            return head;
        }
        else {  //用temp記住頭的位置，然後用while尋找原表的表尾，非表尾(!=NULL)則繼續找下個
            temp = head;
            while (temp->nextnode != NULL){
                temp = temp->nextnode;
            }
            temp->nextnode = Newnode; //找到原表的表尾(newnode的上家)，就將上家指向下一位的指標指向自己
            return head;
        }
    }
}

Chain_node *addhead (Chain_node *head, Data getdata){
    Chain_node *Newnode = (Chain_node*)malloc(sizeof(Chain_node));
    if (!Newnode){
        printf("run out of memory!\n");
        return NULL;
    }
    else{
        Newnode->data = getdata;    //存資料
        Newnode->nextnode = head;   //插入頭，所以原來的head變成newnode的nextnode
        head = Newnode; //紀錄newnode成為list中新的頭
        return head;
    }
}

Chain_node *findnode (Chain_node *head, char *query){
    Chain_node *temp = head;
    while(temp){
        if(strcmp (temp->data.key, query) == 0){
            return temp;
        }
        else {
            temp = temp->nextnode;
        }
    }
    return NULL;
}

Chain_node *insertnode(Chain_node *head, char *query, Data getdata){
    Chain_node *Newnode, *temp;
    Newnode = (Chain_node *)malloc(sizeof(Chain_node));
    if(!Newnode){
        printf("要求記憶體失敗!\n");
        return NULL;
    }
    else {
        Newnode->data = getdata;
        temp = findnode(head, query); //指向找到的位置，//插在temp跟temp的下家中間
        if (temp){  //如果有找到query
            Newnode->nextnode = temp->nextnode; //temp的下家就是newnode的下家
            temp->nextnode = Newnode;   //temp的下家變成newnode
        }
        else{
            printf("未找到插入位!\n");
            free(Newnode);
        }
        return head;
    }
}

int deletenode (Chain_node *head, char *query){
    Chain_node *lastnode, *temp;    //需要知道被害者與他的上家，將上家連到被害者的下家後，消失被害者
    temp = head;
    while(temp){
        if (strcmp(temp->data.key, query) == 0){
            lastnode->nextnode = temp->nextnode; //如果找到了就幹掉回傳1
            free(temp);
            return 1;
        }
        else{
            lastnode = temp;    //並非這個點，就將上家改成當前點
            temp = temp->nextnode;  //當前點改成下家，就完成整組後移
        }
    }
    return 0;   //全部找完沒找到，當然刪除失敗回傳0
}

int length (Chain_node *head){
    Chain_node *temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->nextnode;
    }
    return len;
}

void displayallnode (Chain_node *head){ //將當前位置的資料存到一個current點內，印出來後指向下一個
    Chain_node *temp = head;
    Data currentnode;
    int count = 1;
    printf("list中有%d個節點，資料如下:\n", length(head));
    while (temp){
        currentnode = temp->data;
        printf("node %d = (%s, %s, %d)\n", count, currentnode.key, currentnode.name, currentnode.age);
        temp = temp->nextnode;
        count++;
    }
}

void main(){
    Chain_node *node, *head = NULL;
    Data nodedata;
    char key[10], findkey[10];
    char menu, choice;

    do {
        printf("請輸入串列中的資料: 關鍵字、姓名、年齡\n");
        fflush(stdin);//清空輸入緩衝區
        scanf("%s%s%d", nodedata.key, nodedata.name, &nodedata.age);
        printf("你想幹嘛?\n1. 頭 2. 尾 3. 插入指定位置後 4.刪除資料 5.搜尋節點\n");
        choice = getche();
        printf("\n");
        switch (choice){
            case '1':
                head = addhead(head, nodedata);
                break;
            case '2':
                head = addend(head, nodedata);
                break;
            case '3':
                printf("輸入要插入的位置\n");
                fflush(stdin); //清空輸入緩衝區
                scanf("%s", &findkey);
                head = insertnode(head, findkey, nodedata);
                break;
            case '4':
                printf("請輸入欲刪除的關鍵字\n");
                fflush(stdin); //清空輸入緩衝區
                scanf("%s", key);
                deletenode(head, key);
                break;
            case '5':
                printf("請輸入搜尋關鍵字\n");
                fflush(stdin);
                scanf("%s", key);
                node = findnode(head, key);
                if (node != NULL){//如果節點指標可用，則取用資料
                    nodedata = node->data;
                    printf("關鍵字%s對應的節點為(%s, %s, %d)\n", key, nodedata.key, nodedata.name, nodedata.age);
                }
                else {
                    printf("未找到為%s的節點\n", key);
                }
                break;
            default:
                printf("不合理輸入，滾吧!\n");
                exit(0);
        }
        displayallnode(head);
        printf("是否繼續調整資料?\n");
        printf("1. 要\n2. 不要\n");
        menu = getche();
        printf("\n");
    }while(menu == '1');

    printf("Goodbye!\n");
}
