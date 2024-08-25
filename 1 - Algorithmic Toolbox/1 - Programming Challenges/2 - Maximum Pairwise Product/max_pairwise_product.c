#include <stdio.h>
#include <stdlib.h>

long long max_pairwise_product(long long *nums, long n)
{
    long long res = 0 ;

    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            if (nums[i] * nums[j] > res) {
                res = nums[i] * nums[j] ;
            }
        }
    }

    return res ;
}

long long max_pairwise_product_fast(long long *nums, long n)
{
    long max_idx_1 = -1 ;
    for (long i = 0; i < n; i++) {
        if ((max_idx_1 == -1) || (nums[i] > nums[max_idx_1])) {
            max_idx_1 = i ;
        }
    }

    long max_idx_2 = -1 ;
    for (long i = 0; i < n; i++) {
        if ((i != max_idx_1) && ((max_idx_2 == -1) || (nums[i] > nums[max_idx_2]))) {
            max_idx_2 = i ;
        }
    }

    return nums[max_idx_1] * nums[max_idx_2] ;
}

int main(void)
{
    long num ;
    scanf("%ld", &num) ;

    long long numbers[num] ;
    for (long i = 0; i < num; i++) {
        scanf("%lld", &numbers[i]) ;
    }

    printf("%lld\n", max_pairwise_product_fast(numbers, num)) ;

    return 0 ;
}