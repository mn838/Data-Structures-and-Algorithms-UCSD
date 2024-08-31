#include <stdio.h>
#include <stdlib.h>

long sum_of_fibonacci(long fibonacci_index)
{
    fibonacci_index %= 60;

    if (fibonacci_index == 0) {
        return 0;
    } else if (fibonacci_index == 1) {
        return 1;
    }

    long prev_val = 0;
    long curr_val = 1;
    long temp_val;
    long total = 1; // F(1) is already 1

    for (long i = 2; i <= fibonacci_index; i++) {
        temp_val = prev_val;
        prev_val = curr_val;
        curr_val = (temp_val + prev_val) % 10;
        total = (total + curr_val) % 10;
    }

    return total;
}

int main(void)
{
    long start;
    long end;
    scanf("%ld %ld", &start, &end);

    long sum_end = sum_of_fibonacci(end);
    long sum_start_minus_one = (start == 0) ? 0 : sum_of_fibonacci(start - 1);

    long result = (sum_end - sum_start_minus_one);
    if (result < 0) {
        result += 10;
    }

    printf("%ld\n", result);

    return 0;
}
