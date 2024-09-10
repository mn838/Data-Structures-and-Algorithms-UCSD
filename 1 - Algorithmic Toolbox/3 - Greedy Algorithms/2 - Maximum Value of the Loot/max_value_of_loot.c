#include <stdio.h>
#include <stdlib.h>

double max_value(double values[], double weights[], int num_items, int max_capacity) 
{
    double value = 0.0 ;

    // Calculate the cost (value/weight ratio) for each item
    double *cost = (double *) malloc(num_items * sizeof(double)) ;
    int *sort_indexes = (int *) malloc(num_items * sizeof(int)) ;

    for (int i = 0; i < num_items; i++) {
        cost[i] = values[i] / weights[i] ;
        sort_indexes[i] = i ;
    }

    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (cost[sort_indexes[i]] < cost[sort_indexes[j]]) {
                int temp = sort_indexes[i] ;
                sort_indexes[i] = sort_indexes[j] ;
                sort_indexes[j] = temp ;
            }
        }
    }

    // Calculate the maximum value that can be achieved with the given capacity
    for (int i = 0; i < num_items; i++) {
        int sorted_index = sort_indexes[i] ;

        if (max_capacity == 0) {
            free(cost) ;
            free(sort_indexes) ;
            return value ;
        }

        int capacity_intake = (weights[sorted_index] < max_capacity) ? weights[sorted_index] : max_capacity ;
        max_capacity -= capacity_intake ;
        value += capacity_intake * cost[sorted_index] ;
    }

    free(cost) ;
    free(sort_indexes) ;
    return value ;
}

int main(void) 
{
    int num_items, max_capacity ;
    scanf("%d %d", &num_items, &max_capacity) ;

    double *values = (double *) malloc(num_items * sizeof(double)) ;
    double *weights = (double *) malloc(num_items * sizeof(double)) ;

    for (int i = 0; i < num_items; i++) {
        double value, weight ;
        scanf("%lf %lf", &value, &weight) ;
        values[i] = value ;
        weights[i] = weight ;
    }

    printf("%.4lf\n", max_value(values, weights, num_items, max_capacity)) ;

    free(values) ;
    free(weights) ;
    return 0 ;
}
