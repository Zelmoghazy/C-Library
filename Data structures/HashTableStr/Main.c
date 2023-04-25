#include <stdio.h>
#include <stdlib.h>
#include "./include/HashTable.h"

int main()
{
    HashTable *H1 = init_hash_table(7);
    hash_table_insert(H1, "name1", "Zeyad");
    hash_table_insert(H1, "name2", "russian");
    hash_table_insert(H1, "name3", "pizza");
    hash_table_insert(H1, "name4", "doge");
    hash_table_insert(H1, "name5", "pyro");
    hash_table_insert(H1, "name6", "joost");
    hash_table_insert(H1, "name7", "kalix");
    printTable(H1);
    printf("%d\n", get_collisions(H1));
    printf("%s\n", hash_table_lookup(H1, "name1"));
    printf("%s\n", hash_table_lookup(H1, "nsdjsd"));
    delete_hashtable(H1);
    system("pause");
    return 0;
}