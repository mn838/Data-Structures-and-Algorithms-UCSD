#include <stdio.h>
#include <stdlib.h>

int money_change(int money)
{
    int coins = 0 ;

    while (money != 0) {
        if (money >= 10) {
            money -= 10 ;
        } else if (money >= 5) {
            money -= 5 ;
        } else {
            money -= 1 ;
        }
        coins++ ;
    }

    return coins ;
}

int main(void)
{
    int money ;
    scanf("%d", &money) ;

    printf("%d\n", money_change(money)) ;

    return 0 ;
}