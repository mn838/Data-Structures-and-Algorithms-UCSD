#include <stdio.h>
#include <stdlib.h>

typedef struct Table {
    unsigned int *parent ;
    unsigned int *num_rows ;
} Table ;

inline void make_table(Table *table, unsigned int i, unsigned int num_rows)
{
    table->parent[i] = i ;
    table->num_rows[i] = num_rows ;
}

unsigned int find(Table *table, unsigned int i)
{
    if (table->parent[i] != i) {
        table->parent[i] = find(table, table->parent[i]) ;   
    }
    return table->parent[i] ;
}

unsigned int merge(Table *table, unsigned int dest, unsigned int source, unsigned int pmax)
{
    unsigned int dest_root = find(table, dest);
    unsigned int source_root = find(table, source);

    if (dest_root == source_root) {
        return pmax;  // Already in the same set
    }

    // Merge source into destination
    table->parent[source_root] = dest_root;
    unsigned int updated_size = table->num_rows[dest_root] += table->num_rows[source_root];
    table->num_rows[source_root] = 0;

    return (updated_size > pmax) ? updated_size : pmax;
}

int main()
{
    unsigned int num_tables ;
    unsigned int num_queries ;
    Table table ;

    scanf("%u %u", &num_tables, &num_queries) ;
    table.parent = malloc(num_tables * sizeof(*table.parent)) ;
    table.num_rows = malloc(num_tables * sizeof(*table.num_rows)) ;

    unsigned int pmax = 0 ;
    for (unsigned int i = 0; i < num_tables; i++) {
        unsigned int num_rows ;
        scanf("%u", &num_rows) ;
        make_table(&table, i, num_rows) ;
        pmax = (num_rows > pmax) ? num_rows : pmax ;
    }

    for (int i = 0; i < num_queries; i++) {
        unsigned int destination ;
        unsigned int source ;
        scanf("%u %u", &destination, &source) ;
        pmax = merge(&table, destination - 1, source - 1, pmax);
        printf("%u\n", pmax) ;
    }

    free(table.num_rows) ;
    free(table.parent) ;

    return 0 ;
}