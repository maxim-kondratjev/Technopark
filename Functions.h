#ifndef FUNCTIONS
#define FUNCTIONS
#include "Worker.h"

int menu();
bool char_alloc(char* &charptr, int size);
Worker* create_workeks_arr(int &size);
void write_workers(Worker* &arrptr, int amount);
void print_by_exp(Worker* arr, int N);
void print_by_sal(Worker* arr, int N);
void print_by_pos(Worker* arr, int N);
void print(Worker* arr, int N);
void good_cin(int& N, int b_line, int t_line);
void good_cin(int&N, int b_line);
#endif
