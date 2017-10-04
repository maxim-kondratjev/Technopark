#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		void* matr = NULL;//хранение структурой
		int rows = 0;
		int cols = 0;
		double norma = 0;
		if ((matr=read_matr(argv[i], &rows, &cols)) != NULL)
		{
			norma = norm_counter(matr, rows, cols);
			printf("norma of matrix '%s' is %lf\n", argv[i], norma);
		}
		clean_memory(matr, rows, cols);//очистка только при выделении тк на NULLPTR сломается
	}
	return 0;
}
