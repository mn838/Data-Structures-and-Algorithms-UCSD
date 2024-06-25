"""
Given an integer n, find the last digit of the nth Fibonacci number F(n) (that is, F(n) mod 10).

Author: Mahi Nuthanapati
Date: 06/24/2024
"""

def fib( fibonacci_index: int ) -> int:
    """
    Calculates the last digit of the Fibonacci number at the given index.

    Args:
        fibonacci_index (int): The index of the Fibonacci number.

    Returns:
        int: The last digit of the Fibonacci number at the given index.
    """
    if ( fibonacci_index <= 1 ):
        return fibonacci_index
    
    current_val: int = 0
    temp_val: int = 0
    next_val: int = 1

    for i in range( 1, fibonacci_index ):
        temp_val = current_val
        current_val = next_val
        next_val = ( temp_val + current_val ) % 10

    return next_val

def main( ) -> None:
    """
    Reads user input and prints the last digit of the Fibonacci number at the given index.
    """
    user_input = int( input( ) )
    print( fib( user_input ) )

if __name__ == "__main__":
    main( )