#include <stdio.h>
#include <stdlib.h>
#include "Prototypes.h"

int main()
{
	char* word = (char*)malloc(100);
	char* text = (char*)malloc(100);
	printf("Write a word:\n");
	scanf("%s", word);
	printf("Write file's name:\n");
	scanf("%s", text);
	double DIS=Dispersion(word,text);
	printf("%s%s%s","Dispersion ", word, " in ");
	printf("%s%s%g", text, " is ", DIS);
	scanf("%s",word);
	return 0;
}
