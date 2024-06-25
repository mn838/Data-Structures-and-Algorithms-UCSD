def add( a: int, b: int ) -> int:
    return a + b

if __name__ == "__main__":
    a, b = map(int, input().split())
    print(add(a, b))