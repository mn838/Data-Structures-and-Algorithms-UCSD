#include <iostream>

int get_fibonacci_last_digit_naive( int n ) {
    if ( n <= 1 ) {
        return n ;
    }

    int previous = 0 ;
    int current = 1 ;

    for ( int i = 0; i < n - 1; ++i ) {
        int tmp_previous = previous ;
        previous = current ;
        current = tmp_previous + current ;
    }

    return current % 10 ;
}

int get_fibonacci_last_digit_fast( int n ) {
    if( n <= 1 ) {
        return n ;
    }

    int a = 0 ;
    int b = 1 ;
    int temp ;

    for( int i = 1; i < n; i++ ) {
        temp = (a + b) % 10 ;
        a = b ;
        b = temp ;
    }

    return b ;
}

int main( ) {
    int n ;
    std::cin >> n ;
    int c = get_fibonacci_last_digit_fast(n) ;
    std::cout << c << '\n' ;
    }
