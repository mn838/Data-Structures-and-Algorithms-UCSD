#include <iostream>

int fibonacci_sum_squares_naive( long long n ) {
    if ( n <= 1 )
        return n ;

    long long previous = 0 ;
    long long current  = 1 ;
    long long sum      = 1 ;

    for ( long long i = 0; i < n - 1; ++i ) {
        long long tmp_previous = previous ;
        previous = current ;
        current = tmp_previous + current ;
        sum += current * current ;
    }

    return sum % 10 ;
}

void pisano( int mod, int& count ) {
    if ( mod <= 3 ) {
        count++ ;
    }

    int a = 0 ;
    int b = 1 ;
    int temp ;

    for( int i = 2; i < mod * mod; i++ ) {
        temp = (a + b) % mod ;
        a = b % mod ;
        b = temp ;
        count++ ;
        if( (a == 0) && (b == 1) ) {
            return ;
        }
    }
}

long long fibonacci_sum_squares_fast( long long n, int& count ) {
    if( n % count <= 1 ) {
        return n % count ;
    }

    long long a = 0 ;
    long long b = 1 ;
    long long temp ;
    long long sum = 1 ;

    for( int i = 2; i < n % count + 1; i++ ) {
        temp = (a + b) % 10 ;
        a = b % 10 ;
        b = temp ;
        sum += b * b ;
    }

    return sum % 10 ;
}

int main() {
    long long n = 0 ;
    std::cin >> n ;
    int count = 0 ;
    int &ref_count = count ;
    pisano( 10, ref_count ) ;
    std::cout << fibonacci_sum_squares_fast(n, ref_count) << '\n' ;
}
