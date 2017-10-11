#include <stdio.h>
#include "Functions.h"

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Invalid number of argument\n");
		return 0;
	}
	Vector* vptr = NULL;
	if (v_init(&vptr)==0)
	{
		printf("Vector not initialized\n");
		return 0;
	}
	if (readfile(argv[1], vptr)==0)
	{
		printf("File not read\n");
		return 0;
	}
	if (writefile(argv[2], vptr)==0)
	{
		printf("File not written\n");
		return 0;
	}
	return 1;
}
