#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std ;

void printVector( vector<pair<int, int>> vec ) {
  for( auto&& i: vec ) {
    cout << i.first << " " << i.second << endl ; 
  }
}

double calculation( pair<int, int> pair1, pair<int, int> pair2 ) {
  double calc = sqrt( ( (pair1.first - pair2.first) * (pair1.first - pair2.first) )  + ((pair1.second - pair2.second)* (pair1.second - pair2.second)) ) ;

  return calc ;
}


double minimal_distance( vector<int> x, vector<int> y ) {
  vector<pair<int, int>> vec ;
  vec.reserve( x.size( ) * 2 ) ;

  for( int i = 0; i < x.size( ); i++ ) {
    vec.push_back( make_pair(x[i], y[i] ) ) ;
  }

  double min_value = calculation( vec[0], vec[1] ) ;
  double calc = calculation( vec[0], vec[1] ) ;

  for( int i = 0; i<vec.size(); i++ ) {
    for( int j = i + 1; j <vec.size(); j++ ) {
      calc = calculation( vec[i], vec[j] ) ;
      if( calc < min_value ) {
        min_value = calc ;
      }
    }
  }

  return min_value ;
}

int main( ) {
  size_t n ;
  cin >> n ;
  vector<int> x( n ) ;
  vector<int> y( n ) ;
  for ( size_t i = 0; i < n; i++ ) {
    cin >> x[i] >> y[i] ;
  }
  cout << fixed ;
  cout << setprecision( 9 ) << minimal_distance( x, y ) << "\n" ;
}
