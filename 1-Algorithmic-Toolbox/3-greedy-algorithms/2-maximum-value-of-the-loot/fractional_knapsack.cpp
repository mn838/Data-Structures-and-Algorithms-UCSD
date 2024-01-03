#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector ;
using std::unordered_map ;

bool comp( std::pair<double,int> a, std::pair<double,int> b ) {
    return a.first > b.first;
}

double get_optimal_value( int capacity, vector<int> weights, vector<int> values ) {
  double value = 0.0 ;

  vector<std::pair<double, int> > umap ;

  for( int i = 0; i < weights.size(); i++ ) {
    double value_per_weight = (double)values[i] / (double)weights[i] ;
    umap.push_back(std::make_pair(value_per_weight, weights[i])) ;
  }

  sort( umap.begin(), umap.end(), comp ) ;

  int iter = 0 ;
  while ( capacity > 0 && umap.size() != 0 ) {
    if( umap[iter].first < capacity ) {
      value += umap[iter].first * umap[iter].second ;
      capacity -= umap[iter].second ;
      umap.erase(umap.begin() + iter) ;
    } else {
      value += capacity * umap[iter].first ;
      capacity = 0 ;
    }
  }

  // write your code here

  return value ;
}

int main( ) {
  int n ;
  int capacity ;
  std::cin >> n >> capacity ;
  vector<int> values(n) ;
  vector<int> weights(n) ;
  for ( int i = 0; i < n; i++ ) {
    std::cin >> values[i] >> weights[i] ;
  }

  double optimal_value = get_optimal_value( capacity, weights, values ) ;

  std::cout.precision(10) ;
  std::cout << optimal_value << std::endl ;
  return 0 ;
}
