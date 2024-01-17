#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

std::pair<int, int> partition3( vector<int>& a, int l, int r ) {
  int v = a[l] ;
  int i  = 1 + l ;
  while( i <= r ) {
    if( a[i] < v ) {
      swap( a[l], a[i] ) ;
      l++ ;
      i++ ;
    } else if ( a[i] > v ) {
      swap( a[i], a[r] ) ;
      r-- ;
    } else {
      i++ ;
    }
  }

  return std::make_pair( l, r ) ;
}

void randomized_quick_sort(vector<int>& a, int l, int r) {
  if( l >= r ) {
    return ;
  }

  int pivot = l + rand() % ( r - l + 1 ) ;
  swap( a[l], a[pivot] ) ;
  std::pair<int, int> parts = partition3( a, l, r ) ;
  int part1 = parts.first ;
  int part2 = parts.second ;
  randomized_quick_sort( a, l, part1 ) ;
  randomized_quick_sort( a, part2 + 1, r ) ;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
