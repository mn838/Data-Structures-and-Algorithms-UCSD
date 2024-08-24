#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 16
#define MAX_NUMBER 10000000

typedef struct Contact {
    char *name ;
} Contact ;

typedef struct PhoneBook {
    Contact *contacts[MAX_NUMBER] ;
} PhoneBook ;

PhoneBook* createPhoneBook() {
    PhoneBook *pb = malloc(sizeof(PhoneBook));
    for (int i = 0; i < MAX_NUMBER; i++) {
        pb->contacts[i] = NULL;
    }
    return pb;
}

void deletePhoneBook(PhoneBook *pb) {
    for (int i = 0; i < MAX_NUMBER; i++) {
        if (pb->contacts[i] != NULL) {
            free(pb->contacts[i]->name);
            free(pb->contacts[i]);
        }
    }
    free(pb);
}

void add(PhoneBook *pb, int number, char *name)
{
    if (pb->contacts[number] == NULL) {
        pb->contacts[number] = malloc(sizeof(Contact)) ;
        pb->contacts[number]->name = malloc(sizeof(char) * strlen(name) + 1) ;
    } else {
        pb->contacts[number]->name = realloc(pb->contacts[number]->name, strlen(name) * sizeof(char) + 1) ;
    }
    strcpy(pb->contacts[number]->name, name) ;
}

char* find(PhoneBook *pb, int number)
{
    if (pb->contacts[number] != NULL) {
        return pb->contacts[number]->name ;
    }
    return "not found" ;
}

void del(PhoneBook *pb, int number)
{
    if (pb->contacts[number] != NULL) {
        if (pb->contacts[number]->name != NULL) {
            free(pb->contacts[number]->name) ;
        }
        free(pb->contacts[number]) ;
        pb->contacts[number] = NULL ;
    }
}

int main(void)
{
    int num_ops ;
    scanf("%d", &num_ops) ;

    if (num_ops == 0) {
        return 0 ;
    }

    PhoneBook *pb = createPhoneBook() ;
    for (int i = 0; i < MAX_NUMBER; i++) {
        pb->contacts[i] = NULL ;
    }

    char op[MAX_LEN];
    for (int i = 0; i < num_ops; i++) {
        int key;
        scanf("%s", op);
        if (strcmp(op, "add") == 0) {
            char value[MAX_LEN];
            scanf("%d %s", &key, value);
            add(pb, key, value);
        } else if (strcmp(op, "find") == 0) {
            scanf("%d", &key);
            printf("%s\n", find(pb, key));
        } else if (strcmp(op, "del") == 0) {
            scanf("%d", &key);
            del(pb, key);
        }
    }

    deletePhoneBook(pb) ;

    return 0 ;
}