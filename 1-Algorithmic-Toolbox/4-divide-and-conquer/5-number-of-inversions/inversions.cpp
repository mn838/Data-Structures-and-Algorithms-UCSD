#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t mid = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid, right);
  size_t i = left ;
  size_t j = mid ;
  size_t k = left ;

  while( i < mid && j < right ) {
    if( a[i] <= a[j] ) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
      number_of_inversions += mid - i;
    }
    k++ ;
  }

  while( i < mid ) {
    b[k] = a[i];
    i++;
    k++;
  }

  while( j < right ) {
    b[k] = a[j];
    j++;
    k++;
  }
  std::copy(b.begin() + left, b.begin() + right, a.begin() + left);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
