#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Entry
{
    int key;
    int value;
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
unsigned int hash(unsigned int x);
unsigned int unhash(unsigned int x);
Entry *init_entry(int key, int value);
void delete_entry(Entry *entry);
HashTable *init_hash_table(int Elements);
void delete_hashtable(HashTable *HT);
void printTable(HashTable *HT);
void hash_table_insert(HashTable *HT, int key, int value);
int hash_table_lookup(HashTable *HT, int key);
int get_collisions(HashTable *HT);