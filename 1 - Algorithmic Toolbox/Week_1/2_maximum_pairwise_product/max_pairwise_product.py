import random

def MaxPairwiseProduct( numbers: list[int] ) -> int:
    result: int = 0
    n: int = len( numbers )

    for i in range( n ):
        for j in range( i + 1, n ):
            if ( numbers[i] * numbers[j] > result ):
                result = numbers[i] * numbers[j]
    
    return result


def MaxPairwiseProductFast( numbers: list[int] ) -> int:
    n: int = len( numbers )

    max_index1: int = -1
    for i in range( n ):
        if ( ( max_index1 == -1 ) or ( numbers[i] > numbers[max_index1] ) ):
            max_index1 = i
    
    max_index2: int = -1
    for j in range( n ):
        if ( ( j != max_index1 ) and ( ( max_index2 == -1 ) or ( numbers[j] > numbers[max_index2] ) ) ):
            max_index2 = j
    
    return numbers[max_index1] * numbers[max_index2]

def stress_test( ):
    while( True ):
        n: int = int( random.random() * 100 )
        a: list[int] = []
        print( n )
        for i in range( n ):
            a.append( int( random.random() * 100 ) )

        print( a )
        res1: int = MaxPairwiseProduct( a )
        res2: int = MaxPairwiseProductFast( a )
        if ( res1 != res2 ):
            print( "Wrong Answer", res1, res2 )
            break
        else: print( "Correct" )

if __name__ == "__main__":
    user_input: int = int( input() )
    numbers: list[int] =[ int(x) for x in input().split() ]

    result: int = MaxPairwiseProductFast( numbers )
    stress_test()
