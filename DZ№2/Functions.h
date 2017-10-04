#ifndef Functions
#define Functions
#endif 

#include <stdio.h>

double get_elem(void* matr, int rows, int cols);
void set_elem(void* matr, int rows, int cols, double elem);
void* read_matr(char* filename, int* rowsptr, int* colsptr);
void* set_matr(void* matr, int nrows, int ncols, int no_nul_elem, FILE* file);
double norm_counter(void* matr, int nrows, int ncols);
void clean_memory(void* ptr, int rows, int cols);

