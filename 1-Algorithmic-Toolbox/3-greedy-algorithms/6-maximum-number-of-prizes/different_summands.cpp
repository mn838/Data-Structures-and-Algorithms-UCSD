#include <iostream>
#include <vector>

using std::vector ;

vector<int> optimal_summands( int n ) {
  vector<int> summands ;
  int start_val = 1 ;

  while( n > 0 ) {
    n -= start_val ;
    if( start_val + 1 > n ) {
      summands.push_back( n + start_val ) ;
      n = 0 ;
    } else {
      summands.push_back( start_val ) ;
      start_val++ ;
    }
  }
  return summands ;
}

int main( ) {
  int n ;
  std::cin >> n ;
  vector<int> summands = optimal_summands(n) ;
  std::cout << summands.size() << '\n' ;
  for( size_t i = 0; i < summands.size(); ++i ) {
    std::cout << summands[i] << ' ' ;
  }
}
