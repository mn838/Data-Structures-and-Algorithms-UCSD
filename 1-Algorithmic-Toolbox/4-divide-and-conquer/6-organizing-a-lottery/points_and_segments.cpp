#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include <chrono>
using namespace std ;
using namespace std::chrono ;

void printVector( vector<pair<int, int>> vec ) {
  cout << "{" ;
  for( auto&& i : vec ) {
    cout << "<" <<i.first << " " << i.second << ">" << "," ;
  }
  cout << "}" << endl ;
}

bool sort_alg( const pair<int,int> &a, const pair<int,int> &b ) {
  if (a.first == b.first){
    return a.second < b.second;
  } else {
    return a.first < b.first ;
  }
}

vector<int> fast_count_segments( vector<int> starts, vector<int> ends, vector<int> points ) {
  vector<int> cnt( points.size() ) ;

  vector<pair<int, int>> vec ;

  vec.reserve(starts.size() * 2 + points.size());

  for( int point: points ) {
    vec.push_back(make_pair(point, 1)) ;
  }
  for( int start: starts ) {
    vec.push_back(make_pair(start, 0)) ;
  }
  for( int end: ends ) {
    vec.push_back(make_pair(end, 2)) ;
  }

  sort(vec.begin(), vec.end(), sort_alg) ;

  unordered_map<int, int> map ;
  map.reserve(points.size());
  int count = 0 ;

  for ( auto&& i: vec ) {
    if ( i.second == 0 ) {
      count++ ;
    } else if ( i.second == 2 ) {
      count-- ;
    } else {
      map.insert(make_pair(i.first, count));
    }
  }

  for (int i = 0; i < points.size(); i++) {
		cnt[i] = map[points[i]];
	}

  return cnt ;
}

vector<int> naive_count_segments( vector<int> starts, vector<int> ends, vector<int> points ) {
  vector<int> cnt( points.size() ) ;
  for ( size_t i = 0; i < points.size(); i++ ) {
    for ( size_t j = 0; j < starts.size(); j++ ) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j] ;
    }
  }
  return cnt ;
}

void test( ) {
  while (true) {
    int n = rand( ) % 10 ;
    int m = rand( ) % 10 ;

    vector<int> starts( n ), ends( n ) ;
    for ( size_t i = 0; i < starts.size(); i++ ) {
      int start = rand( ) % 1000 ;
      int end = rand( ) % 1000 ;
      if ( start > end ) {
        i-- ;
      } else {
        starts[i] = start ;
        ends[i] = end ;
      }
    }

    vector<int> points( m ) ;
    for ( size_t i = 0; i < points.size(); i++ ) {
      points[i] = rand( ) % 1000 ;
    }

    assert( fast_count_segments( starts, ends, points ) == naive_count_segments( starts, ends, points ) ) ;
  }
}

int main( ) {

  int n, m ;
  cin >> n >> m ;
  vector<int> starts( n ), ends( n ) ;
  for ( size_t i = 0; i < starts.size(); i++ ) {
    cin >> starts[i] >> ends[i] ;
  }
  vector<int> points( m ) ;
  for ( size_t i = 0; i < points.size(); i++ ) {
    cin >> points[i] ;
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments( starts, ends, points ) ;
  for ( size_t i = 0; i < cnt.size(); i++ ) {
    std::cout << cnt[i] << ' ' ;
  }

  return 0 ;
//    test( ) ;
}
