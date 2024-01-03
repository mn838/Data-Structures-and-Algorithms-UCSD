#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills( int dist, int tank, vector<int> & stops ) {
    int num_stops = 0 ;
    stops.push_back(dist) ;
    int tank_left = tank ;

    int prev_stop = 0 ;
    for( auto stop: stops ) {
        int distance = stop - prev_stop ;

        if( distance <= tank_left ) {
            tank_left -= distance ;
        } else {
            if( distance > tank ) {
                return -1 ;
            } else {
                num_stops++ ;
                tank_left = tank - distance ;
            }
        }
        prev_stop = stop ;

    }

    return num_stops ;
}


int main( ) {
    int d = 0 ;
    cin >> d ;
    int m = 0 ;
    cin >> m ;
    int n = 0 ;
    cin >> n ;

    vector<int> stops(n) ;
    for( size_t i = 0; i < n; ++i )
        cin >> stops.at(i) ;

    cout << compute_min_refills(d, m, stops) << "\n" ;

    return 0 ;
}
