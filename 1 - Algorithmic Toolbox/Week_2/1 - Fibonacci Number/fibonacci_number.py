"""
This module calculates the Fibonacci number at a given index.

Author: Mahi Nuthanapati
Date: 06/24/2024
"""

def fib( fibonacci_index: int ) -> int:
    """
    Calculates the Fibonacci number at the given index.

    Parameters:
    fibonacci_index (int): The index of the Fibonacci number to calculate.

    Returns:
    int: The Fibonacci number at the given index.
    """
    if ( fibonacci_index <= 1 ):
        return fibonacci_index
    
    current_val: int = 0
    temp_val: int = 0
    next_val: int = 1

    for i in range( 1, fibonacci_index ):
        temp_val = current_val
        current_val = next_val
        next_val = temp_val + current_val

    return next_val

def main( ) -> None:
    """
    Main function to get user input and print the Fibonacci number.
    """
    user_input = int( input( ) )
    print( fib( user_input ) )

if __name__ == "__main__":
    main( )
