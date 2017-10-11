#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "Functions.h"

void err()
{
	int err = errno;
	perror(strerror(err));
	errno = 0;
}

int v_init(Vector** vptr)
{
	*vptr = (Vector*)calloc(1,sizeof(Vector));
	if (*vptr == NULL)
	{
		err();
		return 0;
	}
	return 1;
}

int v_expand(Vector* vptr, int n)
{
	int* buf = (int*)realloc(vptr->arr, vptr->size + n);
	if (buf == NULL)
	{
		err();
		return 0;
	}
	vptr->arr = buf;
	vptr->cap = vptr->size + n;
	return 1;
}

int v_push(Vector* vptr, int elem)
{
	if (v_expand(vptr, sizeof(int))==1)
	{
		vptr->arr[vptr->size / sizeof(int)] = elem;
		vptr->size += sizeof(int);
		return 1;
	}
	else return 0;
}

int v_delete_elem(Vector* vptr, int index)
{
	for (int i = index; i < vptr->size / sizeof(int)-1; i++)
	{
		vptr->arr[i] = vptr->arr[i + 1];
	}
	int* buf = (int*)realloc(vptr->arr, vptr->size - sizeof(int));
	if (buf == NULL)
	{
		err();
		return 0;
	}
	vptr->arr = buf;
	vptr->size -= sizeof(int);
	return 1;
}

void v_delete(Vector* vptr)
{
	free(vptr->arr);
	free(vptr);
}

int readfile(char* filename, Vector* vptr)
{
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		err();
		return 0;
	}
	int number = 0;
	while (fscanf(file, "%d", &number)!=EOF)
	{
		if (v_push(vptr, number)==0)
		{
			fclose(file);
			 return 0;
		}
	}
	fclose(file);
	return 1;
}

int writefile(char* filename, Vector* vptr)
{
	FILE* file = fopen(filename, "w");
	if (file == NULL)
	{
		err();
		return 0;
	}
	for(int i=0; i<vptr->size/sizeof(int); i++)
	{
		fprintf(file, "%d ", vptr->arr[vptr->size / sizeof(int)-1-i]);
	}
	fclose(file);
	return 1;
}

