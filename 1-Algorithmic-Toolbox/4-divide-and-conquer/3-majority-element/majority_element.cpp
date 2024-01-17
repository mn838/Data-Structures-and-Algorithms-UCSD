#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  std::unordered_map<int, int> counts ;

  if( left == right ) {
    return -1 ;
  }

  for( auto nums: a ) {
    if( counts[nums] ) {
      counts[nums]++ ;
    } else {
      counts[nums] = 1 ;
    }
  }

  for( const auto& key_value: counts ) {
    if( key_value.second > a.size() / 2 ) {
      return 1 ;
    }
  }


  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
