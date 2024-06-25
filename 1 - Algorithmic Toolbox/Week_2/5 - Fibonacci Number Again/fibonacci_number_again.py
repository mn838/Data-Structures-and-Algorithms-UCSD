"""
Given two integers n and m, output F(n) mod m (that is, the remainder of F(n) when divided by m).

Name: Mahi Nuthanapati
Date: 06/24/2024
"""

def pisano_number( modulo: int ) -> list[int]:
    """
    Function to calculate the pisano number for a given modulo.
    
    Args:
        modulo (int): The modulo for which the pisano number is to be calculated.

    Returns:
        list[int]: The pisano number for the given modulo.
    """
    num_elements: int = ( modulo ** 2 ) - 1
    pisano_list: list[int] = []

    pisano_list.append(0)
    pisano_list.append(1)

    for i in range( 2, num_elements ):
        pisano_list.append( ( pisano_list[i - 1] + pisano_list[i - 2] ) % modulo )
        if( pisano_list[i] == 1 and pisano_list[i - 1] == 0 ):
            return pisano_list[0 : i - 1]
    
    return pisano_list

def fibonacci( fibonacci_index: int, pisano_modulo: int ) -> int:
    """
    Function to calculate the fibonacci number at the given index modulo.

    Args:
        fibonacci_index (int): index of the fibonacci number.
        pisano_modulo (int): argument for pisano_number function.
    
    Returns:
        fibonacci value at the given index modulo.
    """
    pisano_list: list[int] = pisano_number( pisano_modulo )
    num_elements_pisano: int = len( pisano_list )

    simple_fibonacci_index: int = fibonacci_index % num_elements_pisano

    return pisano_list[simple_fibonacci_index]

def main( ) -> None:
    """
    Reads user input and prints the fibonacci number at the given index modulo.
    
    Args:

    Returns:

    """
    fibonacci_index, pisano_modulo = map( int, input( ).split( ) )
    print( fibonacci( fibonacci_index, pisano_modulo ) )

if __name__ == '__main__':
    main( )