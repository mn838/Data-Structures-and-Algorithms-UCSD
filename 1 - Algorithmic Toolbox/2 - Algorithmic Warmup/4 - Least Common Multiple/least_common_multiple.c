#include <stdio.h>
#include <stdlib.h>

long euclidian_gcd(long a, long b)
{
    if (b == 0) {
        return a ;
    }

    a %= b ;
    return euclidian_gcd(b, a) ;
}

long least_common_multiple(long a, long b)
{
    return (a * b) / euclidian_gcd(a, b) ;
}

int main(void)
{
    long a, b ;
    scanf("%ld %ld", &a, &b) ;

    printf("%ld\n", least_common_multiple(a, b)) ;

    return 0 ;
}