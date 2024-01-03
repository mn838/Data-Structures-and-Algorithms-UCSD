#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool compareByStart(const Segment &a, const Segment &b)
{
    return a.start < b.start;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  
  std::sort( segments.begin(), segments.end(), compareByStart ) ;
  int start = segments[0].end ;

  for( auto segment: segments ) {
    if( segment.start > start ) {
      points.push_back(start) ;
      start = segment.end ;
    } else {
      start = std::min(segment.end, start) ;
    }
  }

  points.push_back(start) ;
  
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
