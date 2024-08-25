#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 16

typedef struct String {
    char *str ;
    struct String *next ;
} String ;

String** init(int num_buckets)
{
    String **new = malloc(num_buckets * sizeof(String *)) ;
    for (int i = 0; i < num_buckets; i++) {
        new[i] = NULL ;
    }

    return new ;
}

int hash(int num_buckets, char *word)
{
    unsigned long p = 1000000007 ;
    unsigned long x = 263 ;
    unsigned long h = 0 ;

    for (int i = strlen(word) - 1; i >= 0; i--) {
        h = (h * x + word[i]) % p ;
    }

    return (int)(h % num_buckets) ;
}

void add(String **base, int num_buckets, char *word)
{
    int h = hash(num_buckets, word) ;
    String *list = base[h] ;

    for ( ; list != NULL; list = list->next) {
        if (strcmp(list->str, word) == 0) {
            break ;
        }
    }

    if (list == NULL) {
        list = malloc(sizeof(*list)) ;
        list->str = malloc(sizeof(char) * strlen(word) + 1) ;
        strcpy(list->str, word) ;
        list->next = base[h] ;
        base[h] = list ;
    }
}

String* find(String** base, int num_buckets, char *word)
{
    int h = hash(num_buckets, word) ;
    String *list = base[h] ;

    for ( ; list != NULL; list = list->next) {
        if (strcmp(list->str, word) == 0) {
            return list ;
        }
    }

    return NULL ;
}

void del(String **base, int num_buckets, char *word)
{
    int h = hash(num_buckets, word);
    String *curr = base[h] ;
    String *prev = NULL ;

    for ( ; curr != NULL; curr = curr->next) {
        if (strcmp(curr->str, word) == 0) {
            if (prev == NULL) {
                base[h] = curr->next ;
            } else {
                prev->next = curr->next ;
            }
            free(curr->str) ;
            free(curr) ;
        }
        prev = curr ;
    }
}

void check(String **base, int num_nuckets, int idx)
{
    String *list = base[idx] ;

    for ( ; list != NULL; list = list->next) {
        printf("%s ", list->str) ;
    }

    putchar('\n') ;
}

void free_hash(String **base, int num_buckets)
{
    String *curr ;
    String *prev ;

    for (int i = 0; i < num_buckets; i++) {
        for (prev = base[i]; prev != NULL; prev = curr) {
            curr = prev->next ;
            free(prev->str) ;
            free(prev) ;
        }
    }

    free(base) ;
}

int main(void)
{
    int num_buckets ;
    scanf("%d", &num_buckets) ;

    int num_queries ;
    scanf("%d", &num_queries) ;

    if (num_buckets == 0 || num_queries == 0) {
        return 0 ;
    }

    String **hash = init(num_buckets) ;

    char cmd[6] ;
    char word[16] ;

    for (int i = 0; i < num_queries; i++) {
        scanf("%s", cmd) ;
        if (strcmp(cmd, "add") == 0) {
            scanf("%s", word) ;
            add(hash, num_buckets, word) ;
        } else if (strcmp(cmd, "find") == 0) {
            scanf("%s", word) ;
            if (find(hash, num_buckets, word) == NULL) {
                printf("no\n") ;
            } else {
                printf("yes\n") ;
            }
        } else if (strcmp(cmd, "del") == 0) {
            scanf("%s", word) ;
            del(hash, num_buckets, word) ;
        } else if (strcmp(cmd, "check") == 0) {
            int idx ;
            scanf("%d", &idx) ;
            check(hash, num_buckets, idx) ;
        }
    }

    free_hash(hash, num_buckets) ;

    return 0 ;
}