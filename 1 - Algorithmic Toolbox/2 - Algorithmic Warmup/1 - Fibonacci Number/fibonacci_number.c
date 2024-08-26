#include <stdio.h>
#include <stdlib.h>

int fib(int fib_idx)
{
    if (fib_idx <= 1) {
        return fib_idx ;
    }

    int curr = 0 ;
    int temp = 0 ;
    int next = 1 ;

    for (int i = 1; i < fib_idx; i++) {
        temp = curr ;
        curr = next ;
        next = temp + curr ;
    }

    return next ;
}

int main(void)
{
    int fib_idx ;
    scanf("%d", &fib_idx) ;

    printf("%d\n", fib(fib_idx)) ;

    return 0 ;
}