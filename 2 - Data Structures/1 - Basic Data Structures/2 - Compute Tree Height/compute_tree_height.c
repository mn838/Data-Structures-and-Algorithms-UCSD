#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node ;
struct Node {
    int key ;
    Node *parent ;
    Node **child ;
    int num_children ;
} ;

Node* find_root(Node *nodes_list, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
		if (nodes_list[i].parent == NULL)
			return &nodes_list[i];
	}
}

int maxheight(Node *tree) {
    if (tree->num_children == 0) {
        return 1 ;
    }

    int max_child_height = 0 ;
    for (int i = 0; i < tree->num_children; i++) {
        int child_height = maxheight(tree->child[i]) ;
        if (child_height > max_child_height) {
            max_child_height = child_height;
        }
    }

    return 1 + max_child_height ;
}

int main(void) {
    int num_nodes ;
    scanf("%d", &num_nodes) ;
    Node *nodes_list = malloc(num_nodes * sizeof(Node)) ;

    for (int child_index = 0; child_index < num_nodes; child_index++) {
        int parent_idx ;
        scanf("%d", &parent_idx) ;

        nodes_list[child_index].key = child_index ;

        if (parent_idx >= 0) {
            nodes_list[child_index].parent = &nodes_list[parent_idx] ;
            nodes_list[parent_idx].num_children++ ;
            nodes_list[parent_idx].child = realloc(nodes_list[parent_idx].child, nodes_list[parent_idx].num_children * sizeof(Node*)) ;
            nodes_list[parent_idx].child[nodes_list[parent_idx].num_children - 1] = &nodes_list[child_index];
        }
    }

    Node* root = find_root(nodes_list, num_nodes) ;

    int max_height = maxheight(root) ;
    printf("%d\n", max_height) ;

    free(nodes_list) ;

    return 0 ;
}