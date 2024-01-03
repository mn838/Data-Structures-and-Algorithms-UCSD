#include <iostream>
#define ll long long

ll gcd( ll a, ll b ) {
  if( b == 0 ) {
    return a ;
  }

  return gcd( b,  a % b ) ;
}

ll lcm_fast( ll a, ll b ) {
  return (ll) (a * b) / gcd( a, b ) ;
}

ll lcm_naive( int a, int b ) {
  for ( long l = 1; l <= (ll) a * b; ++l )
    if ( l % a == 0 && l % b == 0 )
      return l ;

  return (ll) a * b ;
}

int main( ) {
  int a, b ;
  std::cin >> a >> b ;
  std::cout << lcm_fast( a, b ) << std::endl ;
  return 0 ;
}
