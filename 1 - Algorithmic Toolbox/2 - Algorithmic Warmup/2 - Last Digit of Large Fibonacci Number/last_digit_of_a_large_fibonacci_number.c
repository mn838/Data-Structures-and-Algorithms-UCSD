#include <stdio.h>
#include <stdlib.h>

int fib(int fibonacci_index)
{
    if (fibonacci_index <= 1) {
        return fibonacci_index ;
    }

    int curr = 0 ;
    int temp = 0 ;
    int next = 1 ;

    for (int i = 1; i < fibonacci_index; i++) {
        temp = curr ;
        curr = next ;
        next = (temp + curr) % 10 ;
    }

    return next ;
}

int main(void)
{
    int fibonacci_idx ;
    scanf("%d", &fibonacci_idx) ;

    printf("%d\n", fib(fibonacci_idx)) ;

    return 0 ;
}