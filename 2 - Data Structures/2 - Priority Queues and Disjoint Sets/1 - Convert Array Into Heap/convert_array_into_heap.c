#include <stdio.h>
#include <stdlib.h>

int *swap_i, *swap_j, nswap ;

typedef struct Heap {
    int size ;
    int *heap_arr ;
} Heap ;

int left_child(int i)
{
    return 2 * i + 1 ;
}

int right_child(int i)
{
    return 2 * i + 2 ;
}

void sift_down(int *arr, int size, int idx)
{
    int max_idx = idx ;
    int left = left_child(idx) ;
    if (left < size && arr[left] < arr[max_idx]) {
        max_idx = left ;
    }

    int right = right_child(idx) ;
    if (right < size && arr[right] < arr[max_idx]) {
        max_idx = right ;
    }

    if (idx != max_idx) {
        swap_i[nswap] = idx ;
        swap_j[nswap] = max_idx ;
        nswap++ ;

        int temp = arr[idx] ;
        arr[idx] = arr[max_idx] ;
        arr[max_idx] = temp ;
        sift_down(arr, size, max_idx) ;
    }
}

void build_heap(int *arr, int arr_size)
{
    for (int i = arr_size / 2; i > 0; i--) {
        sift_down(arr, arr_size, i - 1) ;
    }
}

Heap *heap_init(int size, int *arr)
{
    Heap *heap = malloc(sizeof(Heap)) ;
    if (heap == NULL) {
        fprintf(stderr, "MALLOC failed\n") ;
        exit(0) ;
    }

    heap->size = size ;
    heap->heap_arr = malloc(sizeof(int) * size) ;
    if (heap->heap_arr == NULL) {
        fprintf(stderr, "MALLOC failed\n") ;
        exit(0) ;
    }

    for (int i = 0; i < size; i++) {
        heap->heap_arr[i] = arr[i] ;
    }

    build_heap(heap->heap_arr, size) ;

    return heap ;
}



int main()
{
    int num ;
    scanf("%d", &num) ;

    int arr[num] ;
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]) ;
    }

    swap_i = malloc((4 * num) * sizeof(*swap_i)) ;
    swap_j = malloc((4 * num) * sizeof(*swap_j)) ;
    nswap = 0 ;

    Heap *h = heap_init(num, arr) ;

    printf("%d\n", nswap) ;
    for (int i = 0; i < nswap; i++) {
        printf("%d %d\n", swap_i[i], swap_j[i]) ;
    }

    free(h->heap_arr) ;
    free(h) ;
    free(swap_i) ;
    free(swap_j) ;

    return 0 ;
}