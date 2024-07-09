
def max_product(list_1: list[int], list_2: list[int]) -> int:
    list_1.sort()
    list_2.sort()
    max_count = 0

    for i in range(len(list_1)):
        max_count += list_1[i] * list_2[i]

    return max_count


def main( ) -> None:
    num_inputs = int(input())
    list_1 = list(map(int, input().split()))
    list_2 = list(map(int, input().split()))

    print( f'{max_product(list_1, list_2)}' )

if __name__ == '__main__':
    main( )