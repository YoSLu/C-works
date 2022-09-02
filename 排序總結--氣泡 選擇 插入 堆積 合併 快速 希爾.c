#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 20

int bubblesort (int *a, int len){
    int i, j, k, temp;
    int swap = 0;
    printf("開始泡泡排序\n");
    for (i = 0; i<len; i++){
        int flag = 0;          //flag 用來計算交換的次數，如果一輪排序中沒有交換過(即flag==0)，那就是排好了可以跳出
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
            printf("第%d次排序結果:", i+1);
            for (k = 0; k<len; k++){
                printf("%d ", a[k]);
            }
            printf("\n");
            swap++; //計算做了幾次，拿來跟其他排序法pk的
        }
    }
    return swap;
}

int selectionsort (int *a, int len){
    int i, j, k, h, temp;
    int swap = 0;
    printf("開始選擇排序\n");
    for (i=0; i<len; i++){
        int flag = 0;
        for (h=1; h<len; h++){
            if (a[h-1]>a[h]){ //如果還需要排序，那一定有人前一個比後一個大的
                swap++;
                flag++;    //swap用來計算交換次數(與其他排序法pk)，若有交換則將flag=1來繼續排序迴圈
                break;
            }
        }
        if (flag == 0){
            return swap;
        }   //從這步後才開始排序
        k=i;
        for (j=i+1; j<len; j++){
            if (a[j]<a[k]){
                k=j; //找到並記錄剩下數列中最小的那個
            }
        }
        if (k != i){
            temp = a[i];    //如果最小的跟當前號碼不同，就交換
            a[i] = a[k];
            a[k] = temp;
        }
        printf("第%d步排序結果:", i+1);
        for (h=0; h<len; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
}

int insertionsort (int *a, int len){
    int i, j, t, h;
    int swap = 0;
    printf("開始插入排序\n");
    for (i=1; i<len; i++){
        int flag = 0;
        for (h=1; h<len; h++){
            if (a[h-1]>a[h]){ //如果還需要排序，那一定有人前一個比後一個大的
                swap++;
                flag++;    //swap用來計算交換次數(與其他排序法pk)，若有交換則將flag=1來繼續排序迴圈
                break;
            }
        }
        if (flag == 0){
            break;
        }   //從這步後才開始排序
        t = a[i];
        j = i-1;	//只比到第i-1項
        while(j >= 0 && t < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
        printf("第%d步排序結果:", i);
        for (h=0; h<len; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
    return swap;
}

int shellsort (int *a, int len){	//插入的改進
    int i, j, h;
    int r, temp;
    int x = 0;
    printf("開始shell排序\n");
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
        printf("第%d步排序結果:", x);
        for (h=0; h<len; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
    return x;
}

void quicksort(int *a, int left, int right){ //遞迴只會做一次，所以比較次數沒意義
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
    for (i= len/2; i >= 0; i--){ //做成大根堆
        while ((2*i+1)<len){ //第i點有右子樹
            j = 2 * i + 1;
            if ((j+1) < len){
                if (a[j]<a[j+1]){ //左<右，所以拿右來比較
                    j++; //用序號+1代表指向右子樹
                }
            }
            if (a[i]<a[j]){  //堆的資料交換，必須重整堆的序號i=j
               t = a[i];
               a[i] = a[j];
               a[j] = t;
               i = j;
            }
            else {
                break; //堆沒有被破壞所以直接跳出
            }
        }
    }
    printf("原資料構成的堆:");
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
        printf("第%d步排序結果:", len-i);
        for (h=0; h<len; h++){
            printf("%d ", a[h]);
        }
        printf("\n");
    }
    return (len-1);
}

int min(int x, int y) {
    return x < y ? x : y;   //傳回較小的值
}
int mergesort(int arr[], int len) {
    printf("開始合併排序\n");
    int *a = arr;
    int count = 0;
    int *b = (int *) malloc(len * sizeof(int));	//merge需要n的額外空間暫存結果
    if (!b){
        printf("記憶體配置失敗!\n");
        return 0;
    }

    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg * 2) {	//陣列從1的大小開始合併
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;   //用start 與end切成兩半
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
        printf("第%d步排序結果:", count+1);
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
    srand(time(NULL)); //隨機產生種子
    for (i=0; i<size; i++){
        num[i] = rand()/19+5; //產生待排序數列，並複製幾份，才能比較各種排序法的效率
        num_bubble[i] = num[i];
        num_selection[i] = num[i];
        num_insertion[i] = num[i];
        num_shell[i] = num[i];
        num_quicksort[i] = num[i];
        num_heap[i] = num[i];
        num_merge[i] = num[i];
    }
    printf("排序前的陣列如下:\n");
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
    printf("開始快速排序\n第1步排序結果:");
    for (i=0; i<size; i++){
        printf("%d ", num_quicksort[i]);
    }
    printf("\n\n");
    heap_count = heapsort(num_heap, size);
    printf("\n");
    merge_count = mergesort(num_merge, size);
    printf("\n");
    printf("這次的戰績:\n泡泡排序:%d次\n選擇排序:%d次\n插入排序:%d次\nshell排序:%d次\n堆積排序:%d次\n合併排序:%d次\n", bubble_count, selection_count, insertion_count, shell_count, heap_count, merge_count);
}
