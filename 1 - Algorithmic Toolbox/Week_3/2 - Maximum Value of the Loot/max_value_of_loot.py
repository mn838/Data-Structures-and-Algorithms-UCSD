
def max_value( values: list[float], weights: list[float], max_capacity: int ) -> float:
    value = 0.0

    cost = [ v/w for v, w in zip( values, weights ) ]
    sort_lists = [ i for _, i in sorted( zip(cost, range( len( cost ) ) ), reverse=True)]

    for i in range( len( cost ) ):
        sorted_index = sort_lists[i]

        if max_capacity == 0:
            return value
        
        capacity_intake = min( weights[sorted_index], max_capacity )
        max_capacity -= capacity_intake
        value += capacity_intake * cost[sorted_index]
    
    return value

def main( ) -> None:
    num_items, max_capacity = map( int, input( ).split( ) )
    values = []
    weights = []
    for i in range( num_items ):
        user_input = input( )
        value, weight = map( int, user_input.split( " " ) )
        values.append( value )
        weights.append( weight )
    
    print( f'{max_value( values, weights, max_capacity ):.4f}' )

if __name__ == "__main__":
    main( )