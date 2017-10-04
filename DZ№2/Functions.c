#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double get_elem(void* matr, int row, int col)
{
	return ((double**)matr)[row][col];
}

void set_elem(void* matr, int row, int col, double elem)
{
	((double**)matr)[row][col] = elem;
}

void* set_matr(void* matr, int nrows, int ncols, int no_nul_elem, FILE* file)
{
	matr = (double**)malloc(nrows*(sizeof(double*)));
	if (matr==NULL)
	{
		printf("ERROR\nmemory not allocated\n");
		return NULL;
	}
	for (int i = 0; i < nrows; i++)
	{
		((double**)matr)[i] = (double*)malloc(ncols*(sizeof(double)));
		if (((double**)matr)[i] == NULL)
		{
			printf("ERROR\nmemory not allocated\n");
			return NULL;
		}
	}
	for (int r = 0; r < nrows; r++)
	{
		for (int c = 0; c < ncols; c++)
		{
			set_elem((double**)matr, r, c, 0);
		}
	}
	for (int i = 0; i < no_nul_elem; i++)
	{
		int r = 0;
		int c = 0;
		double elem = 0;
		if (fscanf(file, "%d%d%lf", &r, &c, &elem)!=3 || r > nrows || c > ncols)
		{
			printf("ERROR\noverstepping\n");
			return NULL;
		}
		set_elem((double**)matr, (r-1), (c-1), elem);
	}
	void* ptr=matr;
	return ptr;
}

void* read_matr(char* filename, int* nrows, int* ncols)
{
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("ERROR\nfile not opened\n");
		return NULL;
	}
	int no_nul_elem = 0;
	if (3 != fscanf(file, "%d%d%d", nrows, ncols, &no_nul_elem))
	{
		printf("ERROR\nfile not read\n");
		return NULL;
	}
	void* matr = set_matr(matr, *nrows, *ncols, no_nul_elem, file);
	if(matr==NULL)
	{
		return NULL;
	}
	if (fclose(file) != 0)
	{
		printf("ERROR\nfile not closed\n");
		return NULL;
	}
	return matr;
}

double norm_counter(void* matr, int nrows, int ncols)
{
	double* sumrow = (double*)malloc(nrows * sizeof(double));
	if (sumrow == NULL)
	{
		printf("ERROR\nmemory not allocated\n");
		return -1;
	}
	for (int i = 0; i < nrows; i++)
	{
		sumrow[i] = 0;
		for (int j = 0; j < ncols; j++)
		{
			sumrow[i] = sumrow[i] + fabs(get_elem(matr, i, j));
		}
	}
	double max = 0;
	for (int i = 0; i < nrows; i++)
	{
		if (max < sumrow[i]) max = sumrow[i];
	}
	free(sumrow);
	return max;
}

void clean_memory(void* ptr, int rows, int cols)
{
	for (int r=0; r<rows; r++)
	{
		free(((double**)ptr)[r]);
	}
	free(ptr);
}


