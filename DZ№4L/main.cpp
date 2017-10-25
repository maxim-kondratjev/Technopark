#include <iostream>
#include "Worker.h"
#include "Functions.h"

int main()
{
	system("chcp 1251>nul");
	Worker* arrptr = NULL;
	int sizearr = 0;
	while (true)
	{
		switch (menu())
		{
		case 1: arrptr=create_workeks_arr(sizearr); break;
		case 2: print_by_exp(arrptr, sizearr); break;
		case 3: print_by_sal(arrptr, sizearr); break;
		case 4: print_by_pos(arrptr, sizearr); break;
		case 5: print(arrptr, sizearr); break;
		case 6: return 0;
		}
	}
}
