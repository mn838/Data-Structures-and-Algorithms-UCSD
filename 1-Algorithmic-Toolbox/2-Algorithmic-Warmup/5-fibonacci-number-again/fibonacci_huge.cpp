#include <iostream>
#include <vector>
#define ll long long
using std::vector ;

long long get_fibonacci_huge_naive( long long n, long long m ) {
    if ( n <= 1 )
        return n ;

    long long previous = 0 ;
    long long current  = 1 ;

    for ( long long i = 0; i < n - 1; ++i ) {
        long long tmp_previous = previous ;
        previous = current ;
        current = tmp_previous + current ;
    }

    return current % m ;
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

ll get_fibonacci_huge_fast( ll num, ll mod, int& count ) {

    if( num % count <= 1 ) {
        return num % count ;
    }

    long long a = 0 ;
    long long b = 1 ;
    long long temp ;
    
    for( int i = 2; i < num % count + 1; i++ ) {
        temp = (a + b) % mod ;
        a = b % mod ;
        b = temp ;
    }

    return b ;
}

int main() {
    long long n, m ;

    int count = 0 ;
    int &ref_count = count ;
    std::cin >> n >> m ;
    pisano( m, ref_count ) ;
    std::cout << get_fibonacci_huge_fast( n, m, ref_count ) << '\n';

    return 0 ;
}
