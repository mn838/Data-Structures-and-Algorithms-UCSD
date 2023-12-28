#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

long long MaxPairwiseProduct( const vector<int>& numbers ) {
    long long result ;
    int n = numbers.size() ;

    int maxIndex1 = -1 ;
    int maxIndex2 = -1 ;

    for( int i = 0; i < n; i++ ) {
        if ( maxIndex1 == -1 || numbers[i] > numbers[maxIndex1] ) {
            maxIndex1 = i ;
        }
    }

    for( int i = 0; i < n; i++ ) {
        if ( ( i != maxIndex1 ) && ( ( maxIndex1 == -1 ) || numbers[i] > numbers[maxIndex2] ) ) {
            maxIndex2 = i ;
        }
    }

    result =  ((long long)numbers[maxIndex1]) * numbers[maxIndex2];

    return result ;
}

int main( ) {
    int n ;
    cin >> n ;
    vector<int> numbers(n) ;
    for ( int i = 0; i < n; ++i ) {
        cin >> numbers[i] ;
    }

    cout << MaxPairwiseProduct(numbers) << "\n" ;
    return 0 ;
}
