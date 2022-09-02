#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 20

int bubblesort (int *a, int len){
    int i, j, k, temp;
    int swap = 0;
    printf("�}�l�w�w�Ƨ�\n");
    for (i = 0; i<len; i++){
        int flag = 0;          //flag �Ψӭp��洫�����ơA�p�G�@���ƧǤ��S���洫�L(�Yflag==0)�A���N�O�Ʀn�F�i�H���X
        for (j=0; j<len; j++){
            if (a[j-1]>a[j]){
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                flag++;
            }
        }
        if (flag == 0){
            break;
        }
        else {
            printf("��%d���Ƨǵ��G:", i+1);
            for (k = 0; k<len; k++){
                printf("%d ", a[k]);
            }
            printf("\n");
            swap++; //�p�ⰵ�F�X���A���Ӹ��L�ƧǪkpk��
        }
    }
    return swap;
}

int selectionsort (int *a, int len){
    int i, j, k, h, temp;
    int swap = 0;
    printf("�}�l��ܱƧ�\n");
    for (i=0; i<len; i++){
        int flag = 0;
        for (h=1; h<len; h++){
            if (a[h-1]>a[h]){ //�p�G�ٻݭn�ƧǡA���@�w���H�e�@�Ӥ��@�Ӥj��
                swap++;
                flag++;    //swap�Ψӭp��洫����(�P��L�ƧǪkpk)�A�Y���洫�h�Nflag=1���~��Ƨǰj��
                break;
            }
        }
        if (flag == 0){
            return swap;
        }   //�q�o�B��~�}�l�Ƨ�
        k=i;
        for (j=i+1; j<len; j++){
            if (a[j]<a[k]){
                k=j; //���ðO���ѤU�ƦC���̤p������
            }
        }
        if (k != i){
            temp = a[i];    //�p�G�̤p�����e���X���P�A�N�洫
            a[i] = a[k];
            a[k] = temp;
        }
        printf("��%d�B�Ƨǵ��G:", i+1);
        for (h=0; h<len; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
}

int insertionsort (int *a, int len){
    int i, j, t, h;
    int swap = 0;
    printf("�}�l���J�Ƨ�\n");
    for (i=1; i<len; i++){
        int flag = 0;
        for (h=1; h<len; h++){
            if (a[h-1]>a[h]){ //�p�G�ٻݭn�ƧǡA���@�w���H�e�@�Ӥ��@�Ӥj��
                swap++;
                flag++;    //swap�Ψӭp��洫����(�P��L�ƧǪkpk)�A�Y���洫�h�Nflag=1���~��Ƨǰj��
                break;
            }
        }
        if (flag == 0){
            break;
        }   //�q�o�B��~�}�l�Ƨ�
        t = a[i];
        j = i-1;	//�u����i-1��
        while(j >= 0 && t < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
        printf("��%d�B�Ƨǵ��G:", i);
        for (h=0; h<len; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
    return swap;
}

int shellsort (int *a, int len){	//���J����i
    int i, j, h;
    int r, temp;
    int x = 0;
    printf("�}�lshell�Ƨ�\n");
    for (r = len/2; r >= 1; r /= 2){
        for (i = r; i < len; i++){
            temp = a[i];
            j = i-r;
            while (j >= 0 && temp <a[j]){
                a[j+r] = a[j];
                j-=r;
            }
            a[j+r] = temp;
        }
        x++;
        printf("��%d�B�Ƨǵ��G:", x);
        for (h=0; h<len; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
    return x;
}

void quicksort(int *a, int left, int right){ //���j�u�|���@���A�ҥH������ƨS�N�q
    int f, t, rtemp, ltemp;
    ltemp = left;
    rtemp = right;
    f = a[(left + right)/2];

    while (ltemp < rtemp){
        while(a[ltemp]<f){
            ++ltemp;
        }
        while(a[rtemp]>f){
            --rtemp;
        }
        if (ltemp <= rtemp){
            t = a[ltemp];
            a[ltemp] = a[rtemp];
            a[rtemp] = t;
            --rtemp;
            ++ltemp;
        }
    }
    if (ltemp == rtemp){
        ltemp++;
    }
    if (left < rtemp){
        quicksort(a, left, ltemp-1);
    }
    if (ltemp<right){
        quicksort(a, rtemp+1, right);
    }
}

int heapsort(int a[], int len){
    int i, j, k, h, t;
    for (i= len/2; i >= 0; i--){ //�����j�ڰ�
        while ((2*i+1)<len){ //��i�I���k�l��
            j = 2 * i + 1;
            if ((j+1) < len){
                if (a[j]<a[j+1]){ //��<�k�A�ҥH���k�Ӥ��
                    j++; //�ΧǸ�+1�N����V�k�l��
                }
            }
            if (a[i]<a[j]){  //�諸��ƥ洫�A��������諸�Ǹ�i=j
               t = a[i];
               a[i] = a[j];
               a[j] = t;
               i = j;
            }
            else {
                break; //��S���Q�}�a�ҥH�������X
            }
        }
    }
    printf("���ƺc������:");
    for (h=0; h<len; h++){
        printf("%d ", a[h]);
    }
    printf("\n");
    for (i=len-1; i>0; i--){
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        k = 0;
        while (2*k+1<i){
            j=2*k+1;
            if ((j+1)<i){
                if (a[j]<a[j+1]){
                    j++;
                }
            }
            if (a[k]<a[j]){
                t = a[k];
                a[k] = a[j];
                a[j] = t;
                k = j;
            }
            else {
                break;
            }
        }
        printf("��%d�B�Ƨǵ��G:", len-i);
        for (h=0; h<len; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
    return (len-1);
}

int min(int x, int y) {
    return x < y ? x : y;   //�Ǧ^���p����
}
int mergesort(int arr[], int len) {
    printf("�}�l�X�ֱƧ�\n");
    int *a = arr;
    int count = 0;
    int *b = (int *) malloc(len * sizeof(int));	//merge�ݭnn���B�~�Ŷ��Ȧs���G
    if (!b){
        printf("�O����t�m����!\n");
        return 0;
    }

    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg * 2) {	//�}�C�q1���j�p�}�l�X��
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;   //��start �Pend������b
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
        count++;
        printf("��%d�B�Ƨǵ��G:", count+1);
        for (int h=0; h<size; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++){
            b[i] = a[i];
        }
        b = a;
    }
    free(b);
    return count+1;
}


void main (){
    int num[size], num_bubble[size], num_selection[size], num_insertion[size], num_shell[size], num_quicksort[size], num_heap[size], num_merge[size];
    int i, bubble_count, selection_count, insertion_count, shell_count, heap_count, merge_count;
    srand(time(NULL)); //�H�����ͺؤl
    for (i=0; i<size; i++){
        num[i] = rand()/19+5; //���ͫݱƧǼƦC�A�ýƻs�X���A�~�����U�رƧǪk���Ĳv
        num_bubble[i] = num[i];
        num_selection[i] = num[i];
        num_insertion[i] = num[i];
        num_shell[i] = num[i];
        num_quicksort[i] = num[i];
        num_heap[i] = num[i];
        num_merge[i] = num[i];
    }
    printf("�Ƨǫe���}�C�p�U:\n");
    for (i=0; i<size; i++){
        printf("%d ", num[i]);
    }
    printf("\n\n");

    bubble_count = bubblesort(num_bubble, size);
    printf("\n");
    selection_count = selectionsort(num_selection, size);
    printf("\n");
    insertion_count = insertionsort(num_insertion, size);
    printf("\n");
    shell_count = shellsort(num_shell, size);
    printf("\n");
    quicksort(num_quicksort, 0, size-1);
    printf("�}�l�ֳt�Ƨ�\n��1�B�Ƨǵ��G:");
    for (i=0; i<size; i++){
        printf("%d ", num_quicksort[i]);
    }
    printf("\n\n");
    heap_count = heapsort(num_heap, size);
    printf("\n");
    merge_count = mergesort(num_merge, size);
    printf("\n");
    printf("�o�������Z:\n�w�w�Ƨ�:%d��\n��ܱƧ�:%d��\n���J�Ƨ�:%d��\nshell�Ƨ�:%d��\n��n�Ƨ�:%d��\n�X�ֱƧ�:%d��\n", bubble_count, selection_count, insertion_count, shell_count, heap_count, merge_count);
}
