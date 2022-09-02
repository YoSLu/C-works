#include <stdio.h>  //�[����ڡA�[���Y�A��`�I�A��ܥ����A���J�A�R���A�^���`����
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
        printf("�n�D�O���饢��!\n");
        return NULL;
    }
    else { //�e��y���B�znew node�ۤv���Ʊ�
        Newnode->data = getdata; //data���new node��data��
        Newnode->nextnode = NULL; //�ѩ󴡤J�b���ڡA���ڪ��U�@�ӷ�M�O���VNULL
        //���U�ӳB�z�P��list�����Y

        if (head == NULL){ //�p�G�Y�ONULL�A���list�u��newnode�@�ӡA�Nhead���Vnode
            head = Newnode;
            return head;
        }
        else {  //��temp�O���Y����m�A�M���while�M��������A�D���(!=NULL)�h�~���U��
            temp = head;
            while (temp->nextnode != NULL){
                temp = temp->nextnode;
            }
            temp->nextnode = Newnode; //��������(newnode���W�a)�A�N�N�W�a���V�U�@�쪺���Ы��V�ۤv
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
        Newnode->data = getdata;    //�s���
        Newnode->nextnode = head;   //���J�Y�A�ҥH��Ӫ�head�ܦ�newnode��nextnode
        head = Newnode; //����newnode����list���s���Y
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
        printf("�n�D�O���饢��!\n");
        return NULL;
    }
    else {
        Newnode->data = getdata;
        temp = findnode(head, query); //���V��쪺��m�A//���btemp��temp���U�a����
        if (temp){  //�p�G�����query
            Newnode->nextnode = temp->nextnode; //temp���U�a�N�Onewnode���U�a
            temp->nextnode = Newnode;   //temp���U�a�ܦ�newnode
        }
        else{
            printf("����촡�J��!\n");
            free(Newnode);
        }
        return head;
    }
}

int deletenode (Chain_node *head, char *query){
    Chain_node *lastnode, *temp;    //�ݭn���D�Q�`�̻P�L���W�a�A�N�W�a�s��Q�`�̪��U�a��A�����Q�`��
    temp = head;
    while(temp){
        if (strcmp(temp->data.key, query) == 0){
            lastnode->nextnode = temp->nextnode; //�p�G���F�N�F���^��1
            free(temp);
            return 1;
        }
        else{
            lastnode = temp;    //�ëD�o���I�A�N�N�W�a�令��e�I
            temp = temp->nextnode;  //��e�I�令�U�a�A�N������իᲾ
        }
    }
    return 0;   //�����䧹�S���A��M�R�����Ѧ^��0
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

void displayallnode (Chain_node *head){ //�N��e��m����Ʀs��@��current�I���A�L�X�ӫ���V�U�@��
    Chain_node *temp = head;
    Data currentnode;
    int count = 1;
    printf("list����%d�Ӹ`�I�A��Ʀp�U:\n", length(head));
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
        printf("�п�J��C�������: ����r�B�m�W�B�~��\n");
        fflush(stdin);//�M�ſ�J�w�İ�
        scanf("%s%s%d", nodedata.key, nodedata.name, &nodedata.age);
        printf("�A�Q�F��?\n1. �Y 2. �� 3. ���J���w��m�� 4.�R����� 5.�j�M�`�I\n");
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
                printf("��J�n���J����m\n");
                fflush(stdin); //�M�ſ�J�w�İ�
                scanf("%s", &findkey);
                head = insertnode(head, findkey, nodedata);
                break;
            case '4':
                printf("�п�J���R��������r\n");
                fflush(stdin); //�M�ſ�J�w�İ�
                scanf("%s", key);
                deletenode(head, key);
                break;
            case '5':
                printf("�п�J�j�M����r\n");
                fflush(stdin);
                scanf("%s", key);
                node = findnode(head, key);
                if (node != NULL){//�p�G�`�I���Хi�ΡA�h���θ��
                    nodedata = node->data;
                    printf("����r%s�������`�I��(%s, %s, %d)\n", key, nodedata.key, nodedata.name, nodedata.age);
                }
                else {
                    printf("����쬰%s���`�I\n", key);
                }
                break;
            default:
                printf("���X�z��J�A�u�a!\n");
                exit(0);
        }
        displayallnode(head);
        printf("�O�_�~��վ���?\n");
        printf("1. �n\n2. ���n\n");
        menu = getche();
        printf("\n");
    }while(menu == '1');

    printf("Goodbye!\n");
}
