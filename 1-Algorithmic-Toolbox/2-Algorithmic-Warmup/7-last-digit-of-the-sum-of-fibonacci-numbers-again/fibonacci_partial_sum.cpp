#include <iostream>
#include <vector>
using std::vector ;

long long get_fibonacci_partial_sum_naive( long long from, long long to ) {
    long long sum = 0 ;

    long long current = 0 ;
    long long next  = 1 ;

    for ( long long i = 0; i <= to; ++i ) {
        if ( i >= from ) {
            sum += current ;
        }

        long long new_current = next ;
        next = next + current ;
        current = new_current ;
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

int get_fibonacci_partial_sum_fast( long long from, long long to, int& count ) {
    
        if( to % count <= 1 ) {
            return to % count ;
        }

        int to_mod = to % count ;
        int from_mod = from % count ;

        if( to_mod < from_mod ) {
            to_mod += count ;
        }
    
        long long a = 0 ;
        long long b = 1 ;
        long long temp ;
        long long sum = 0 ;

        for( int i = 2; i < from_mod + 1; i++ ) {
            temp = (a + b) ;
            a = b ;
            b = temp ;
        }

        for( int i = from_mod >= 2 ? from_mod : 1; i < to_mod + 1; i++ ) {
            temp = (a + b) ;
            a = b ;
            b = temp ;
            sum += a ;
        }
    
        return sum % 10 ;
}

int main( ) {
    long long from, to ;
    std::cin >> from >> to ;
    int count = 0 ;
    int &ref_count = count ;
    pisano( 10, ref_count ) ;
    std::cout << get_fibonacci_partial_sum_fast(from, to, ref_count) << '\n' ;

    return 0 ;
}
