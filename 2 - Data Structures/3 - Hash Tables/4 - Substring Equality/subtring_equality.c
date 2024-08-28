#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 500000

void precompute_hashes(char *word, unsigned long *hash_table_1, unsigned long *hash_table_2, unsigned long *power_x_mod_m1, unsigned long *power_x_mod_m2, unsigned long word_len, int x, int m_1, int m_2)
{
    hash_table_1[0] = 0 ;
    hash_table_2[0] = 0 ;
    power_x_mod_m1[0] = 1 ;
    power_x_mod_m2[0] = 1 ;

    for (unsigned long i = 1; i <= word_len; i++) {
        hash_table_1[i] = (hash_table_1[i - 1] * x + word[i - 1]) % m_1 ;
        hash_table_2[i] = (hash_table_2[i - 1] * x + word[i - 1]) % m_2 ;
        power_x_mod_m1[i] = (power_x_mod_m1[i - 1] * x) % m_1 ;
        power_x_mod_m2[i] = (power_x_mod_m2[i - 1] * x) % m_2 ;
    }
}

void substring_equality(int start_1, int start_2, int gap, unsigned long *hash_table_1, unsigned long *hash_table_2, unsigned long *power_x_mod_m1, unsigned long *power_x_mod_m2, int m_1, int m_2)
{
    unsigned long hash_1_m1 = (hash_table_1[start_1 + gap] - power_x_mod_m1[gap] * hash_table_1[start_1] % m_1 + m_1) % m_1 ;
    unsigned long hash_2_m1 = (hash_table_1[start_2 + gap] - power_x_mod_m1[gap] * hash_table_1[start_2] % m_1 + m_1) % m_1 ;

    unsigned long hash_1_m2 = (hash_table_2[start_1 + gap] - power_x_mod_m2[gap] * hash_table_2[start_1] % m_2 + m_2) % m_2 ;
    unsigned long hash_2_m2 = (hash_table_2[start_2 + gap] - power_x_mod_m2[gap] * hash_table_2[start_2] % m_2 + m_2) % m_2 ;

    if (hash_1_m1 == hash_2_m1 && hash_1_m2 == hash_2_m2) {
        printf("Yes\n") ;
    } else {
        printf("No\n") ;
    }
}


int main(void)
{
    char str[MAX_LEN] ;
    scanf("%s", str) ;
    
    int num_queries ;
    scanf("%d", &num_queries) ;

    int start_1 ;
    int start_2 ;
    int gap ;

    unsigned long word_len = strlen(str) ;
    int m_1 = 1000000007 ;
    int m_2 = 1000000009 ;
    int x = 263 ;

    unsigned long *hash_table_1 = malloc(sizeof(unsigned long) * (word_len + 1)) ;
    unsigned long *hash_table_2 = malloc(sizeof(unsigned long) * (word_len + 1)) ;
    unsigned long *power_x_mod_m1 = malloc(sizeof(unsigned long) * (word_len + 1)) ;
    unsigned long *power_x_mod_m2 = malloc(sizeof(unsigned long) * (word_len + 1)) ;

    precompute_hashes(str, hash_table_1, hash_table_2, power_x_mod_m1, power_x_mod_m2, word_len, x, m_1, m_2) ;

    for (int i = 0; i < num_queries; i++) {
        scanf("%d %d %d", &start_1, &start_2, &gap) ;
	substring_equality(start_1, start_2, gap, hash_table_1, hash_table_2, power_x_mod_m1, power_x_mod_m2, m_1, m_2) ;
    }

    free(hash_table_1) ;
    free(hash_table_2) ;
    free(power_x_mod_m1) ;
    free(power_x_mod_m2) ;

    return 0 ;
}
