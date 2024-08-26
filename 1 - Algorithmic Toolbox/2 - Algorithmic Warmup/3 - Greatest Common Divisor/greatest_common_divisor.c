#include <stdio.h>
#include <stdio.h>

int euclidian_gcd(int a, int b)
{
    if (b == 0) {
        return a ;
    }

    a %= b ;
    return euclidian_gcd(b, a) ;
}

int main()
{
    int a ;
    scanf("%d", &a) ;

    int b ;
    scanf("%d", &b) ;

    printf("%d\n", euclidian_gcd(a, b)) ;

    return 0 ;
}