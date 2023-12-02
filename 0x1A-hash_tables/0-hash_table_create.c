#include "hash_tables.h"

/**
 * hash_table_create - function that creats a hash table
 * @size: size of the array
 *
 * Return: When an error occurs - NULL
 *         Otherwise - pointer to the new hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table_created;
	unsigned long int j;

	/* allocate space for the hash table */
	hash_table_created = malloc(sizeof(hash_table_t));

	if (hash_table_created == NULL)
		return (NULL);

	hash_table_created->size = size;
	hash_table_created->array = malloc(sizeof(hash_node_t *) * size);

	if (hash_table_created->array == NULL)
		return (NULL);

	for (j = 0; j < size; j++)
	{
		hash_table_created->array[j] = NULL;
	}

	return (hash_table_created);
}
