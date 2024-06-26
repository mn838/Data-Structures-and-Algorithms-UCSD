import sys

def largest_number( a: int, n: list[str] ) -> str:
    res: str = ""

    while ( a ):
        max_digit: str = a[0]
        max_index: int = 0
        for i, each in enumerate( a ):
            if IsGreaterOrEqual( each, max_digit ):
                max_digit = each
                max_index = i
        res += max_digit
        del a[max_index]

    return res

def IsGreaterOrEqual( a: str, b: str ) -> bool: 
    return int( a + b ) > int( b + a )

def main( ) -> None:
    user_input = sys.stdin.read( )
    data = user_input.split( )
    n = int( data[0] )
    a = data[1:]
    print( largest_number( a, n ) )

if __name__ == "__main__":
    main( )