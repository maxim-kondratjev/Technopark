#ifndef FUNCTIONS
#define FUNCTIONS
#include <stdio.h>

struct Vector
{
	size_t size;
	size_t cap;
	int* arr;
};

typedef struct Vector Vector;


int v_init(Vector** vptr);
int v_expand(Vector* vptr, int n);
int v_push(Vector* vptr, int elem);
int v_delete_elem(Vector* vptr, int index);
void v_delete(Vector* vptr);
void err();
int readfile(char* filename, Vector* vptr);
int writefile(char* filename, Vector* vptr);

#endif


