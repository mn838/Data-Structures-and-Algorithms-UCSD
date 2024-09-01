#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

void inorder(long *key, long *left, long *right, long idx)
{
    if (idx == -1) {
        return ;
    }
    inorder(key, left, right, left[idx]) ;
    printf("%ld ", key[idx]) ;
    inorder(key, left, right, right[idx]) ;
}

void preorder(long *key, long *left, long *right, long idx)
{
    if (idx == -1) {
        return ;
    }
    printf("%ld ", key[idx]) ;
    preorder(key, left, right, left[idx]) ;
    preorder(key, left, right, right[idx]) ; 
}

void postorder(long *key, long *left, long *right, long idx)
{
    if (idx == -1) {
        return ;
    }
    postorder(key, left, right, left[idx]) ;
    postorder(key, left, right, right[idx]) ; 
    printf("%ld ", key[idx]) ;
}

int main(int argc, char **argv)
{
    long key[MAX_LEN] ;
    long right[MAX_LEN] ;
    long left[MAX_LEN] ;

    int n ;
    scanf("%d", &n) ;

    for (long i = 0; i < n; i++) {
        scanf("%ld %ld %ld", &key[i], &left[i], &right[i]) ;
    } 

    inorder(key, left, right, 0);
    putchar('\n');
    preorder(key, left, right, 0);
    putchar('\n');
    postorder(key, left, right, 0);
    putchar('\n');

    return 0;
}