#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100002

typedef struct {
    int index ;
    char bracket ;
} Item ;

typedef struct {
    int top ;
    Item arr[MAX_SIZE] ;
} Stack ;

bool isEmpty(Stack *s) {
    return s->top == 0 ;
}

void push(Stack *s, Item x) {
    if (s->top + 1 > MAX_SIZE) {
        printf("\nOverflow\n") ;
        exit(1) ;
    } else {
        s->arr[s->top++] = x ;
    }
}

Item pop(Stack *s) {
    if (s->top == 0) {
        printf("\nNo items in stack\n") ;
        exit(1) ;
    } else {
        return s->arr[--s->top] ;
    }
}

Item top(Stack *s) {
    if (s->top == 0) {
        printf("\nNo items in stack\n") ;
        exit(1) ;
    } else {
        int temp = s->top - 1 ;
        return s->arr[temp] ;
    }
}

bool match(char left_bracket, char right_bracket) {
    if (left_bracket == '{' && right_bracket == '}') {
        return true ;
    } else if (left_bracket == '[' && right_bracket == ']') {
        return true ;
    } else if (left_bracket == '(' && right_bracket == ')') {
        return true ;
    } else {
        return false ;
    }
}

int check_brackets(char* bracks, Stack *s) {
    
    for (int i = 0; i < strlen(bracks); i++) {
        if (bracks[i] == '(' || bracks[i] == '{' || bracks[i] == '[') {
            Item *item = malloc(sizeof(Item)) ;
            item->bracket = bracks[i] ;
            item->index = i ;

            push(s, *item) ;
            free(item) ;
        } else if (bracks[i] == ')' || bracks[i] == '}' || bracks[i] == ']') {
            if (isEmpty(s)) {
                return i ;
            }
            if (!match(pop(s).bracket, bracks[i])) {
                return i ;
            }
        }
    }

    return isEmpty(s) ? -1 : pop(s).index ;
}

int main(void) {
    char input[MAX_SIZE] ;

    scanf("%s", input) ;

    Stack *s = malloc(sizeof(Stack)) ;
    s->top = 0 ;
    
    int ret = check_brackets(input, s) ;
    
    if (ret == -1) {
        printf("Success\n") ;
    } else {
        printf("%d\n", ret + 1) ;
    }

    free(s) ;
    return 0 ;
}