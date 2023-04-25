#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Entry
{
    char *key;
    char *value;
    struct Entry *next;
} Entry;

typedef struct HashTable
{
    int collisons;
    int size;
    Entry **table;
} HashTable;

bool IsPrime(unsigned int n);
unsigned int TableSize(unsigned int n);
static long hash(char *key);
Entry *init_entry(const char *key, const char *value);
void delete_entry(Entry *entry);
HashTable *init_hash_table(int Elements);
void delete_hashtable(HashTable *HT);
void printTable(HashTable *HT);
void hash_table_insert(HashTable *HT, const char *key, const char *value);
char *hash_table_lookup(HashTable *HT, const char *key);
int get_collisions(HashTable *HT);