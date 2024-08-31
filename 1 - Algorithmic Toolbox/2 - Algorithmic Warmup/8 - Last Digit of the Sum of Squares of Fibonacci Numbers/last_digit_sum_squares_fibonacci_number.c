#include <stdio.h>
#include <stdlib.h>

long sum_of_fibonacci(long fibonacci_index)
{
    fibonacci_index %= 60 ;

    if (fibonacci_index <= 1) {
        return fibonacci_index ;
    }

    long total = 1 ;
    long prev_val = 0 ;
    long curr_val = 1 ;
    long temp_val = 0 ;

    for (long i = 1; i < fibonacci_index; i++) {
        temp_val = prev_val ;
        prev_val = curr_val ;
        curr_val = (temp_val + prev_val) % 10 ;
        total += curr_val * curr_val ;
    }

    return total % 10 ;
}

int main(void)
{
    long n ;
    scanf("%ld", &n) ;

    printf("%ld\n", sum_of_fibonacci(n)) ;

    return 0 ;
}