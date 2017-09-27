#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int WordsCounter(char* Word, char* file)
{
	FILE* fileptr = fopen(file, "r");
	if (fileptr==NULL)
	{
		printf("%s", "ERROR\nfile is not find\n");
		return 0;
	}
	char* word = NULL;
	int letterAM = 0;
	char* delimS = "!?.\n";
	char* delimW = ",: ;\t";
	int amountW = 0;
	int amountS = 0;
	char* buf = NULL;
	char ch = 'A';
	while ((ch = fgetc(fileptr))!=EOF)
	{
		if (strchr(delimS, ch) == NULL)
		{
			if (strchr(delimW, ch) == NULL)
			{
				if (letterAM > 0)
				{
					buf = word;
				}
				letterAM++;
				word = (char*)malloc((letterAM) * sizeof(char));
				if (letterAM > 1)
				{
					word = buf;
				}
				word[letterAM - 1] = ch;
			}
			else
			{
				if (letterAM > 0)
				{
					word[letterAM] = '\0';
					if (strcmp(word, Word) == 0)
					{
						amountW++;
					}
				}
				word = NULL;
				letterAM = 0;
			}
		}
		else
		{
			amountS++;
			if (letterAM > 0)
			{
				word[letterAM] = '\0';
				if (strcmp(word, Word) == 0)
				{
					amountW++;
				}
			}
			word = NULL;
			letterAM = 0;
		}
	}
	return amountW;
}

double Dispersion(char* wordptr, char* docnameptr)
{
	char* text2 = "text2.txt";
	char* text3 = "text3.txt";
	int AoW = WordsCounter(wordptr, docnameptr);
	int AoW2 = WordsCounter(wordptr, text2);
	int AoW3 = WordsCounter(wordptr, text3);
	int average = (AoW+AoW2+AoW3)/3;
	double D = sqrt(((AoW - average)*(AoW - average) + (AoW2 - average)*(AoW2 - average) + (AoW3 - average)*(AoW3 - average)) / 2);
	return D;
}
