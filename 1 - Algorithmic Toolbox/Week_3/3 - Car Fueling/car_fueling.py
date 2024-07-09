
def get_num_stops( distance_between_cities: int, full_tank_mileage: int, num_stops: int, stops: list[int] ) -> int:
    tank_left = full_tank_mileage
    stops.insert(0, 0)
    stops.append( distance_between_cities )
    num_refills = 0

    if full_tank_mileage >= distance_between_cities:
        return 0

    i = 1
    while i < len( stops ):
        to_next_station = stops[i] - stops[i - 1]

        if to_next_station <= tank_left:
            tank_left -= to_next_station
        else:
            tank_left = full_tank_mileage
            if to_next_station > tank_left:
                return -1
            num_refills += 1
            i -= 1

        i += 1

    return num_refills


def main( ) -> None:
    distance_between_cities = int( input( ) )
    full_tank_mileage = int( input( ) )
    num_stops = int( input( ) )
    stops = list( map( int, input().split() ) )

    print( get_num_stops( distance_between_cities, full_tank_mileage, num_stops, stops ) )

if __name__ == "__main__":
    main( )