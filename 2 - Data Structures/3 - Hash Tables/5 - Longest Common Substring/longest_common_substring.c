#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000
#define m_1 1000000007
#define m_2 1000000009
#define X 263

typedef struct HashEntry {
    long long hash ;
    int start_index ;
} HashEntry ;

long long *precompute_hashes(char *str, int str_len, int len_substring, int p)
{
    int n = str_len - len_substring + 1 ;
    long long *hashes = (long long *) malloc(n * sizeof(long long)) ;
    long long y = 1 ;

    for (int i = 0; i < len_substring; i++) {
        y = (y * X) % p ;
    }

    char *substring = str + str_len - len_substring ;
    hashes[n - 1] = 0 ;

    for (int i = 0; i < len_substring; i++) {
        hashes[n - 1] = (hashes[n - 1] * X + substring[i]) % p ;
    }

    for (int i = n - 2; i >= 0; i--) {
        hashes[i] = (X * hashes[i + 1] + str[i] - y * str[i + len_substring]) % p ;
        if (hashes[i] < 0) {
            hashes[i] += p ;
        }
    }

    return hashes ;
}

int compare_hashes(const void *a, const void *b)
{
    return ((HashEntry *)a)->hash - ((HashEntry *)b)->hash ;
}

int check_common_substring(char *str_1, char *str_2, int len_str_1, int len_str_2, int len_substring, int *i_1, int *i_2) {
    long long *str_1_hashes = precompute_hashes(str_1, len_str_1, len_substring, m_1) ;
    long long *str_2_hashes = precompute_hashes(str_2, len_str_2, len_substring, m_1) ;

    int n_str_1 = len_str_1 - len_substring + 1 ;
    int n_str_2 = len_str_2 - len_substring + 1 ;

    HashEntry *str_1_entries = (HashEntry *) malloc(n_str_1 * sizeof(HashEntry)) ;
    for (int i = 0; i < n_str_1; i++) {
        str_1_entries[i].hash = str_1_hashes[i] ;
        str_1_entries[i].start_index = i ;
    }

    qsort(str_1_entries, n_str_1, sizeof(HashEntry), compare_hashes) ;

    for (int i = 0; i < n_str_2; i++) {
        HashEntry target ;
        target.hash = str_2_hashes[i] ;
        HashEntry *found = bsearch(&target, str_1_entries, n_str_1, sizeof(HashEntry), compare_hashes) ;

        if (found != NULL) {
            int idx = found->start_index;
            if (strncmp(str_1 + idx, str_2 + i, len_substring) == 0) {
                *i_1 = idx ;
                *i_2 = i ;
                free(str_1_hashes) ;
                free(str_2_hashes) ;
                free(str_1_entries) ;
                return 1 ;
            }
        }
    }

    free(str_1_hashes) ;
    free(str_2_hashes) ;
    free(str_1_entries) ;
    return 0 ;
}

void longest_common_substring(char *str_1, char *str_2, int *start_1, int *start_2, int *best_len)
{
    int len_str_1 = strlen(str_1) ;
    int len_str_2 = strlen(str_2) ;

    int left = 0 ;
    int right = (len_str_1 < len_str_2) ? len_str_1 : len_str_2 ;

    *best_len = 0 ;
    *start_1 = 0 ;
    *start_2 = 0 ;

    while (left <= right) {
        int mid = (left + right) / 2 ;
        int i_1 ;
        int i_2 ;
        if (check_common_substring(str_1, str_2, len_str_1, len_str_2, mid, &i_1, &i_2)) {
            *best_len = mid ;
            *start_1 = i_1 ;
            *start_2 = i_2 ;
            left = mid + 1 ;
        } else {
            right = mid - 1 ;
        }
    }
}

int main(void)
{
    char *str_1 = malloc(sizeof(char) * MAX_LEN) ;
    char *str_2 = malloc(sizeof(char) * MAX_LEN) ;

    while ((scanf("%s %s", str_1, str_2)) == 2) {
        int start_1 ;
        int start_2 ;
        int best_len ;
        longest_common_substring(str_1, str_2, &start_1, &start_2, &best_len) ;
        printf("%d %d %d\n", start_1, start_2, best_len) ;
    }

    free(str_1) ;
    free(str_2) ;

    return 0 ;
}