#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std ;
typedef unsigned long long ull ;

struct Data {
	string pattern, text ;
} ;

Data read_input( ) {
	Data data ;

	cin >> data.pattern ;
	cin >> data.text ;

	return data ;
}

void print_output( const vector<int>& output ) {
	for( int i = output.size() - 1; i >= 0; i-- ) {
		cout << output[i] <<  " " ;
 	}
	cout << endl ;
}

ull hash_function( const string& text, const ull& prime, const ull &x ) {
    ull hash = 0 ;

    for ( int i = static_cast<int>(text.size()) - 1; i >= 0; --i ) {
        hash = ( hash * x + text[i] ) % prime ;
    }

    return hash ;
}

vector<ull> compute_hash( const string& text, const string& pattern, const size_t &pattern_size, const ull &prime, const ull &x ) {
    size_t text_size = text.size() ;

    vector<ull> H( text_size - pattern_size + 1 ) ;

    H[text_size - pattern_size] = hash_function( pattern, prime, x ) ;

    ull y = 1 ;

    for( int i = text_size - pattern_size - 1; i >=0; --i ) {
        H[i] = (ull)( ( ( H[i + 1] * x ) + text[i] - ( y * text[i + pattern_size] ) ) % prime ) ;
    }

    return H ;
}

void RabinKarp( const Data& input ) {
	const string& pattern = input.pattern ; 
	const string& text = input.text ;

	ull prime = 100000007 ;
	ull x = 1 ;

    while( x > ( prime - 1 ) ) {
	    x = 1 + rand( ) / ( ( RAND_MAX + 1u ) / ( prime-1 ) ) ;
	}

    size_t pattern_size = pattern.size() ;
	size_t text_size = text.size() ;

	vector<int> ans ;

    ull pattern_hash = hash_function( pattern, prime, x ) ;

	string t_substr = text.substr( text_size - pattern_size, pattern_size ) ;

	vector<ull> H = compute_hash( text, t_substr, pattern_size, prime, x ) ;

    for ( int i = 0; i <= text_size - pattern_size; ++i ) {
		if ( ( H[i] == pattern_hash ) && ( text.substr( i, pattern_size ).compare( pattern ) == 0 ) ) {
			cout << i << " " ;
		}
	}

	cout << endl ;
}

int main( ) {

	Data data = read_input( ) ;

	RabinKarp( data ) ;

	return 0 ;
}
