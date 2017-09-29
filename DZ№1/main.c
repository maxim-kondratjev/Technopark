#include <stdio.h>
#include "Functions.h"

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		double dis = dispersion(argv[1], argv[2]);
		if (dis==-1) printf("Something went wrong\n");
		else printf("Dispersion %s in %s  is %g\n", argv[1], argv[2], dis);
	}
	else
	{
		printf("Invalid number of arguments\n");
	}
	return 0;
}
