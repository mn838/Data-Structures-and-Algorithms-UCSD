#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct Stack Stack ;
struct Stack {
    int max_idx ;
    int max_arr[MAX_SIZE] ;
    int idx ;
    int arr[MAX_SIZE] ;
} ;

int get_max(Stack *s) {
    return s->max_arr[s->max_idx] ;
}

void push(Stack *s, int val) {
    s->idx++ ;
    s->arr[s->idx] = val ;
    
    if (val >= s->max_arr[s->max_idx] || s->max_idx == -1) {
        s->max_idx++ ;
        s->max_arr[s->max_idx] = val ;
    }
}

void pop(Stack *s) { 
    int pop_val = s->arr[s->idx] ;
    s->idx-- ;

    if (pop_val == s->max_arr[s->max_idx]) {
        s->max_idx-- ;
    }
}

int main(void) {
    Stack *s = malloc(sizeof(Stack)) ;
    s->idx = -1 ;
    s->max_idx = -1 ;

    int num_queries = 0 ;
    scanf("%d", &num_queries) ;

    char cmd[20] ;

    for (int i = 0; i < num_queries; i++) {
        scanf("%s", cmd) ;
        
        if (strcmp(cmd, "push") == 0) {
            int val = 0 ;
            scanf("%d", &val) ;
            push(s, val) ;
        } else if (strcmp(cmd, "max") == 0) {
            printf("%d\n", get_max(s)) ;
        } else if (strcmp(cmd, "pop") == 0) {
            pop(s) ;
        }
    }


    free(s) ;
    return 0 ;
}