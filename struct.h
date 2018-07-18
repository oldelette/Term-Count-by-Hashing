#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct HashTable
{
	char word[50];
	int count;
	struct HashTable *next;
}HashTable;

HashTable hash[MAX];


#endif // STRUCT_H_INCLUDED
