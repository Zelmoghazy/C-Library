#include "../include/HashTable.h"

bool IsPrime(unsigned int n) // O(sqrt(n))
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

unsigned int TableSize(unsigned int n)
{
    unsigned int size = n * 1.3;
    while (!IsPrime(size))
    {
        size++;
    }
    return size;
}

static long hash(char *key)
{
    int h = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        h = (h << 4) | (h >> 27);
        h += (int)key[i];
    }
    return h;
}

Entry *init_entry(const char *key, const char *value)
{
    Entry *entry = (Entry *)malloc(sizeof(*entry));
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);
    strcpy(entry->key, key);
    strcpy(entry->value, value);
    entry->next = NULL;
    return entry;
}

void delete_entry(Entry *entry)
{
    free(entry->key);
    free(entry->value);
    free(entry);
}

HashTable *init_hash_table(int Elements)
{
    HashTable *HT = (HashTable *)malloc(sizeof(*HT));
    HT->size = TableSize(Elements);
    HT->collisons = 0;
    HT->table = (Entry **)malloc(sizeof(Entry *) * HT->size);
    for (int i = 0; i < HT->size; i++)
    {
        HT->table[i] = NULL;
    }
    return HT;
}

void delete_hashtable(HashTable *HT)
{
    for (int i = 0; i < HT->size; i++)
    {
        Entry *entry = HT->table[i];
        while (entry != NULL)
        {
            Entry *next = entry->next;
            delete_entry(entry);
            entry = next;
        }
    }
    free(HT->table);
    free(HT);
}
void printTable(HashTable *HT)
{
    printf("----------------------------------\n");
    printf("Start:\n");
    for (int i = 0; i < HT->size; i++)
    {
        Entry *entry = HT->table[i];
        if (entry == NULL)
        {
            printf("\t%i|\t---\n", i);
            continue;
        }
        printf("\t%i|", i);
        while (1)
        {
            printf("\t(%s,%s)->", entry->key, entry->value);
            if (entry->next == NULL)
            {
                break;
            }
            entry = entry->next;
        }
        printf("\n");
    }
    printf("End\n");
    printf("----------------------------------\n");
}

void hash_table_insert(HashTable *HT, const char *key, const char *value)
{
    int index = hash(key) % HT->size;
    Entry *entry = HT->table[index];
    if (entry == NULL)
    {
        HT->table[index] = init_entry(key, value);
        return;
    }
    HT->collisons++;
    Entry *prev = entry;
    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }
        prev = entry;
        entry = prev->next;
    }
    prev->next = init_entry(key, value);
}

char *hash_table_lookup(HashTable *HT, const char *key)
{
    int index = hash(key) % HT->size;
    Entry *entry = HT->table[index];
    if (entry == NULL)
    {
        return "None";
    }
    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            return entry->value;
        }
        entry = entry->next;
    }
    return "None";
}

int get_collisions(HashTable *HT)
{
    return HT->collisons;
}
