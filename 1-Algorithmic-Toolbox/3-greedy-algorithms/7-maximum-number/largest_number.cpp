#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std ;

void print_vector( vector<int> nums ) {
    for( int i = 0; i < nums.size(); i++ ) {
        cout << nums[i] << " " ;
    }
    cout << "\n" ;
}

int min( vector<string> nums ) {
    int minLength = nums[0].length() ;
    for( string s: nums) {
        if( s.length() > minLength ) {
            minLength = s.length() ;
        }
    }

    return minLength ;
}

string largest_number( vector<string> a ) {
  stringstream ret ;
  vector<int> nums ;

  int minLength = min( a ) ;

  for( size_t i = 0; i < a.size( ); i++ ) {
    string num_string = a[i] ;
    int num_int = stoi( a[i] ) ;
    if( num_string.length() > minLength ) {
        while (num_int > 0) {
            int digit = num_int % 10 ;
            num_int /= 10 ;
            nums.push_back( digit ) ;
        }
    } else {
        nums.push_back( num_int ) ;
    }
  }

  sort( nums.begin(), nums.end(), greater<int>() ) ; 

  for( size_t i = 0; i < nums.size( ); i++ ) {
    ret << nums[i] ;
  }
  string result ;
  ret >> result ;
  return result ;
}

int main( ) {
  int n ;
  cin >> n ;
  vector<string> a(n) ;
  for( size_t i = 0; i < a.size( ); i++ ) {
    cin >> a[i] ;
  }
  cout << largest_number(a) ;
}
