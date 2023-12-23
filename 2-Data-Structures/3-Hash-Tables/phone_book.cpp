#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std ;

struct Query {
    string type, name ;
    int number ;
} ;

vector<Query> read_queries( ) {
    int n ;
    cin >> n ;
    vector<Query> queries(n) ;
    for ( int i = 0; i < n; ++i ) {
        cin >> queries[i].type ;
        if ( queries[i].type == "add" )
            cin >> queries[i].number >> queries[i].name ;
        else
            cin >> queries[i].number ;
    }
    return queries ;
}

void write_responses( const vector<string>& result ) {
    for ( size_t i = 0; i < result.size(); ++i )
        cout << result[i] << "\n" ;
}

vector<string> process_queries( const vector<Query>& queries ) {
    vector<string> result;
    unordered_map< int, string > phone_book ;
    
    for( int i = 0; i < queries.size(); i++ ) {
        if( queries[i].type == "add" ) {
            phone_book[queries[i].number] = queries[i].name ;
        } else if ( queries[i].type == "find" ) {
            if( phone_book[queries[i].number] == "" ) {
                result.push_back( "not found" ) ;
            } else {
                result.push_back( phone_book[queries[i].number] ) ;
            }
        } else if ( queries[i].type == "del" ) {
            phone_book.erase( queries[i].number ) ;
        }
    }

    return result;
}

int main( ) {
    write_responses( process_queries( read_queries() ) ) ;
    return 0 ;
}
