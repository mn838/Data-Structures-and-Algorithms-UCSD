#include <stdio.h>
#include <stdlib.h>

int get_max(int *nums, int size) {
    int max = nums[0] ;

    for (int i = 1; i < size; i++) {
        if (max < nums[i]) {
            max = nums[i] ;
        }
    }

    return max ;
}

int* max_sliding_window(int *nums, int numsSize, int window_size) {
    int max = 0 ;
    int *ret ;

    if (!numsSize) {
        return NULL ;
    }

    ret = malloc((numsSize - window_size + 1) * sizeof(int)) ;
    ret[0] = get_max(&nums[0], window_size) ;

    for (int i = 1; i + window_size <= numsSize; i++) {
        if (ret[i - 1] < nums[i + window_size - 1]) {
            ret[i] = nums[i + window_size - 1] ;
        } else if (ret[i - 1] == nums[i - 1]) {
            ret[i] = get_max(&nums[i], window_size) ;
        } else {
            ret[i] = ret[i - 1] ;
        }
    }

    return ret ;
}

int main() {
    int n ;
    scanf("%d", &n) ;

    int nums[n] ;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]) ;
    }

    int window ;
    scanf("%d", &window) ;

    int* ret = max_sliding_window(nums, n, window) ;

    for (int i = 0; i < n - window + 1; i++) {
        printf("%d ", ret[i]) ;
    }

    printf("\n") ;

    return 0 ;
}