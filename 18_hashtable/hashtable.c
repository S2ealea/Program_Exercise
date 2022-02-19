// gcc -fsanitize=address -fno-omit-frame-pointer  -g
//HashTable 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	//Build the dictionary
	#define DICT_TYPE_INT 0
	#define DICT_TYPE_STR 1

	typedef struct dict_entry {
		/*The next entry*/
		struct dict_entry* next;
		/*Key */
		void* key;
		/*Value */
		void* val;

	} dict_entry;

	typedef struct dict {
		/*Hash function*/
		unsigned int (*hash)(void* key);
		/*Array table for storing the dict_entry pointer*/
		dict_entry** table;
		/*Length of the table array*/
		int size;
		/*Mask (size-1)*/
		int sizemask;
	} dict;



	//Hash function
	//For integer
	 unsigned int hash_integer(void* key)
	{
		return (*(int*)key*2654435769)>>28;
	}

	//Hash function TIME33 algorithms for the string
	 unsigned int hash_33 (void* key)
	{
		unsigned int hash = 0;
		while( *(char*)key != 0)
		{
			/*Left rotate 5-bit means *32, pulus a hash , means *33 */
			hash = (hash<<5) + hash + *(char*)key++;
		}

		return hash;
	}



	//Create a dict
	dict* dict_create(int type )
	{
		dict* dict = (struct dict*)malloc(sizeof(struct dict));
		if ( dict == NULL )  return NULL;
		if ( type == DICT_TYPE_INT )
			dict->hash = &hash_integer;
		else
			dict->hash = &hash_33;
		dict->size = 1024;
		dict->sizemask = dict->size - 1;

		/*Apply memory for the array*/
		dict->table = (dict_entry**)malloc(sizeof(dict_entry*)*(dict->size));
		if (dict->table == NULL )  return NULL;

		/*Set array elements to zero*/
		memset(dict->table,0,sizeof(dict_entry*)*(dict->size));

		return dict;
	}


	//Create a dict_entry
	dict_entry* dict_create_entry ( void* key, void* val)
	{
		dict_entry* entry = (dict_entry*)malloc(sizeof(dict_entry));
		if (entry == NULL)  return NULL;
		entry->key = key;
		entry->val = val;
		entry->next = NULL;

		return entry;
	}



	//Dict insert a key-value
	dict* dict_put_entry (dict* dict, void* key, void* val)
	{
		unsigned int hash = dict->hash(key);
		int pos = hash & dict->sizemask;

		dict_entry* entry;
		entry = dict_create_entry(key,val);

		entry->next = dict->table[pos];
		dict->table[pos] = entry;

		return dict;
	}


	//Search the dict
	void* dict_get_value(dict* dict, void* key )
	{
		unsigned int hash = dict->hash(key);
		int pos = hash & dict->sizemask;
		if ( dict->table[pos] == 0 )  return NULL;
		dict_entry *current = dict->table[pos];

		while( current )
		{
			if ( dict->hash(current->key) == dict->hash(key) )
				return current->val;
			else
				current = current->next;
		}

		return NULL;
	}


	//Empty the dict
	void dict_empty( dict* dict )
	{
		int i ;
		for ( i = 0; i < dict->size; i++)
		{
			if (dict->table[i] != 0)
			{
				dict_entry *current,*next;
				current = dict->table[i];
				while(current)
				{
					next = current->next;
					free(current);
					current = next;
				}
				dict->table[i] = 0;
			}
		}
	}


	//Release the dict
	void dict_release( dict* dict )
	{
		dict_empty(dict);
		free(dict->table);
		free(dict);
	}



	//Test code
 /* 创建一个key为字符串类型的字典 */
    dict * dictionary = dict_create(1);

    char str[] = "name";
    char str2[] = "Austin";
    char str3[] = "Lookcos";
    char str4[] = "age";
    int age = 18;

    /* 键值对：("Austin", "Austin") */
    dict_put_entry(dictionary, &str2, &str2);
    puts(dict_get_value(dictionary, &str2));

    /* 键值对：("name", "Austin") */
    dict_put_entry(dictionary, &str, &str2);
    puts(dict_get_value(dictionary, &str));

    /* 键值对：("name", "Lookcos") */
    dict_put_entry(dictionary, &str, &str3);
    puts(dict_get_value(dictionary, &str));
    
    /* 键值对：("age", 18) */
    dict_put_entry(dictionary, &str4, &age);
    printf("age: %d\n", *(int *)dict_get_value(dictionary, &str4));

    /* 字典的释放 */
    dict_empty(dictionary);
    dict_release(dictionary);



	return 0;
}