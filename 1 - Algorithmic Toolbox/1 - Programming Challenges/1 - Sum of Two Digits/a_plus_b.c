#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
    return a + b ;
}

int main(void)
{
    int a ;
    int b ;

    scanf("%d %d", &a, &b) ;
    printf("%d\n", add(a, b)) ;

    return 0 ;
}