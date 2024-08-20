#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    unsigned long process_time ;
    unsigned long thread_id ;
    unsigned long start_time ;
} Job ;

typedef struct Thread {
    unsigned long id ;
    unsigned long busy ;
} Thread ;

unsigned long left_child(unsigned long i)
{
    return 2 * i + 1 ; 
}

unsigned long right_child(unsigned long i)
{
    return 2 * i + 2 ; 
}

void swap(Thread *arr, unsigned long i, unsigned long j) 
{
    Thread temp = arr[i] ;
    arr[i] = arr[j] ;
    arr[j] = temp ;
}

void sift_down(Thread *arr, unsigned long num_threads, unsigned long i) 
{
    unsigned long max_idx = i ;
    unsigned long left = left_child(i) ;
    if ((left < num_threads) && 
            ((arr[left].busy < arr[max_idx].busy) || 
            ((arr[left].busy == arr[max_idx].busy) && 
            (arr[left].id < arr[max_idx].id)))) {
        max_idx = left ;
    }
    unsigned long right = right_child(i) ;
    if ((right < num_threads) && 
            ((arr[right].busy < arr[max_idx].busy) || 
            ((arr[right].busy == arr[max_idx].busy) && 
            (arr[right].id < arr[max_idx].id)))) {
        max_idx = right ;
    }

    if (max_idx != i) {
        swap(arr, i, max_idx) ;
        sift_down(arr, num_threads, max_idx) ;
    }
}   

void process(Job *arr, unsigned long arr_size, unsigned long num_threads)
{
    Thread *cpu ;
    cpu = malloc(sizeof(Thread) * num_threads) ;

    for (unsigned long i = 0; i < num_threads; i++) {
        cpu[i].id = i ;
        cpu[i].busy = 0 ;
    }

    for (unsigned long i = 0; i < arr_size; i++) {
        arr[i].thread_id = cpu[0].id ;
        arr[i].start_time = cpu[0].busy ;
        cpu[0].busy += arr[i].process_time ;
        sift_down(cpu, num_threads, 0) ;
    }

    free(cpu) ;
}

int main()
{
    unsigned long num_threads ;
    scanf("%ld", &num_threads) ;

    unsigned long arr_size ;
    scanf("%ld", &arr_size) ;

    Job *jarr = malloc(sizeof(Job) * arr_size) ;

    for (unsigned long i = 0; i < arr_size; i++) {
        scanf("%ld", &jarr[i].process_time) ;
    }

    process(jarr, arr_size, num_threads) ;

    for (unsigned long i = 0; i < arr_size; i++) {
        printf("%lu %lu\n", jarr[i].thread_id, jarr[i].start_time) ;
    }
    
    free(jarr) ;
    return 0 ;
}