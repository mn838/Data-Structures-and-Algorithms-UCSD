#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_LEN 100000

int key[MAX_LEN] = {0} ;
int right[MAX_LEN] = {-1} ;
int left[MAX_LEN] = {-1} ;
int small[MAX_LEN] = {INT_MAX} ;
int large[MAX_LEN] = {INT_MIN} ;

bool is_bst(int idx)
{
    if (idx == -1) {
        return true ;
    }

    if (left[idx] == -1) {
        small[idx] = key[idx] ;
    } else {
        if (!is_bst(left[idx])) {
            return false ;
        } 
        if (key[idx] <= large[left[idx]]) {
            return false ;
        }
        small[idx] = small[left[idx]] ;
    }

    if (right[idx] == -1) {
        large[idx] = key[idx] ;
    } else {
        if (!is_bst(right[idx])) {
            return false ;
        } else if (key[idx] >= small[right[idx]]) {
            return false ;
        }
        large[idx] = large[right[idx]] ;
    } 

    return true ;
}

int main(void)
{
    int n ;
    scanf("%d", &n) ;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &key[i], &left[i], &right[i]) ;
    }

    if (is_bst(0)) {
        printf("CORRECT\n") ;
    } else {
        printf("INCORRECT\n") ;
    }

    return 0 ;
}