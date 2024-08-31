#include <stdio.h>
#include <stdlib.h>

long* pisano_number(long modulo, long* pisano_size)
{
    long num_elements = (modulo * modulo) - 1 ;
    long* pisano_list = (long*)malloc(num_elements * sizeof(long)) ;
    
    pisano_list[0] = 0 ; 
    pisano_list[1] = 1 ;

    for (long i = 2; i < num_elements; i++) {
        pisano_list[i] = (pisano_list[i - 1] + pisano_list[i - 2]) % modulo ;
        if (pisano_list[i] == 1 && pisano_list[i - 1] == 0) {
            *pisano_size = i - 1 ;
            return pisano_list ;
        }
    }

    *pisano_size = num_elements ;
    return pisano_list ;
}

long fibonacci(long fibonacci_index, long modulo)
{
    long pisano_size ;
    long* pisano_list = pisano_number(modulo, &pisano_size) ;

    long simple_fibonacci_index = fibonacci_index % pisano_size ;

    long result = pisano_list[simple_fibonacci_index] ;
    free(pisano_list) ; 

    return result ;
}

int main(void)
{
    long fibonacci_index ;
    long pisano_modulo ;
    scanf("%ld %ld", &fibonacci_index, &pisano_modulo) ;

    printf("%ld\n", fibonacci(fibonacci_index, pisano_modulo)) ;

    return 0 ;
}