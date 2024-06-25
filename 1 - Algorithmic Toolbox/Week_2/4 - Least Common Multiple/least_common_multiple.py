
def EuclidianGCD( a: int, b: int ) -> int:
    if ( b == 0 ):
        return a
    
    a %= b
    return EuclidianGCD( b, a )

def LCM( a: int, b:int ) -> int:
    return (a * b) // EuclidianGCD( a, b )

def main( ) -> None:
    a, b = map( int, input( ).split( ) )
    print( LCM( a, b ) )

if __name__ == "__main__":
    main( )