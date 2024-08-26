#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 5 * 100000

int hash(char *word, int start, int end)
{
    unsigned long h = 0 ;
    long p = 1000000007 ;
    int x = 1;

    for (int i = end + 1; i > start; i--) {
        h = (h * x + word[i - 1]) % p ;
    }

    return h ;
}

void compute_hashes(int *hashes, int pattern_len, char *text, int text_len) 
{
    hashes[text_len - pattern_len] = hash(text, text_len - pattern_len, text_len - 1) ;

    long p = 1000000007;
    long long x = 1;
    long long y = 1;

    for (long long i = 1; i <= pattern_len; i++ ) {
        y = (y * x) % p ;
    }
    for (long long i = (text_len - pattern_len - 1); i >= 0; i--) {
        hashes[i] = (x * hashes[i + 1] + text[i] - y * text[i + pattern_len]) % p ;
    }
}

void rabin_karps(char *pattern, char *text) 
{
    int pattern_len = strlen(pattern) ;
    int text_len = strlen(text) ;

    int *hashes = malloc((text_len - pattern_len + 1) * sizeof(int)) ;
    compute_hashes(hashes, pattern_len, text, text_len) ;

    int pattern_hash = hash(pattern, 0, pattern_len - 1);

    for (int i = 0; i <= text_len - pattern_len; i++) {
        if (hashes[i] != pattern_hash) {
            continue ;
        } else if (strncmp(pattern , text + i, pattern_len) == 0) {
            printf("%d ", i) ;
        }
    }
    putchar('\n') ;
    free(hashes) ;
}

int main(void)
{
    char pattern[MAX_LEN + 1] ;
    char text[MAX_LEN + 1] ;

    scanf("%s", pattern) ;
    scanf("%s", text) ;

    rabin_karps(pattern, text) ;

    return 0 ;
}