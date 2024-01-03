#include <iostream>

int get_change( int m ) {
  int num_coins = 0 ;

  if ( m >= 10 ) {
    num_coins += m / 10 ;
    m = m % 10 ;
  }

  if ( m >= 5 ) {
    num_coins += m / 5 ;
    m = m % 5 ;
  }

  num_coins += m ;

  return num_coins ;
}

int main( ) {
  int m ;
  std::cin >> m ;
  std::cout << get_change(m) << '\n' ;

  return 0 ;
}
