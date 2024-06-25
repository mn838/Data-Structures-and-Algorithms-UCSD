

def EuclidianGCD( a: int, b: int ) -> int:
    if ( b == 0 ):
        return a
    
    a %= b
    return EuclidianGCD( b, a )

def main( ) -> None:
    a, b = map( int, input( ).split( ) )
    print( EuclidianGCD( a, b ) )

if __name__ == "__main__":
    main( )