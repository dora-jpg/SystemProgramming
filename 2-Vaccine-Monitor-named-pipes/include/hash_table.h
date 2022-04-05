/* Hash table with extendible hashing */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
typedef struct HashT HashT;

HashT* HashT_init(unsigned int nbuckets, void (*destroy_item)(void *)); /*nbuckets is a minimum estimate, destroy_item is the function to destroy the items to which hash table entries point */
void HashT_delete(HashT* hash_table);

bool HashT_insert(HashT* hash_table, char* key, void* item); 
void HashT_remove(HashT* hash_table, char* key);

bool HashT_exists(HashT* hash_table, char* key);
void* HashT_get(HashT* hash_table, char* key); /* returns NULL if key is not found*/

void HashT_print(HashT* hash_table, void (*print)(void*));
void* HashT_getNextEntry(HashT* hash_table); /*First call with a pointer to hash table to get 1st item. For next item call with NULL. If there are no more elements it returns NULL*/

void HashT_stats(HashT* hash_table); /* prints number of items, number of bucketσ and load factor */

#endif