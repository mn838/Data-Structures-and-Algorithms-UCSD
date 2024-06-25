
def sum_of_fibonacci( fibonacci_index: int ) -> int:
    fibonacci_index %= 60
    
    if ( fibonacci_index <= 1 ):
        return fibonacci_index

    total: int = 1
    prev_val: int = 0
    curr_val = 1
    temp_val: int = 0

    for i in range( 1, fibonacci_index ):
        temp_val = prev_val
        prev_val = curr_val
        curr_val = ( temp_val + prev_val ) % 10
        total += curr_val

    return total % 10


def main( ) -> None:
    user_input = int( input( ) )
    print( sum_of_fibonacci( user_input ) )

if __name__ == "__main__":
    main( )