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
    umap.push_back(std::make_pair(value_per_weight, i)) ;
  }

  sort( umap.begin(), umap.end(), comp ) ;


  for( int i = 0; i < umap.size(); i++ ) {
    int i_sorted = umap[i].second ;
    if( capacity == 0 ) {
      return value ;
    }
    int capacity_remaining = std::min(weights[i_sorted], capacity) ;
    capacity -= capacity_remaining ;
    value += capacity_remaining * umap[i].first ;
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
