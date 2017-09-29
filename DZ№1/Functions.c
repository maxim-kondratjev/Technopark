#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int sentencecounter(FILE* fileptr)
{
	int amountS=0;
	char ch = 'A';
	while ((ch = fgetc(fileptr)) != EOF)
	{
		if (ch == '!' || ch == '?' || ch == '.')
			amountS++;
	}
	rewind(fileptr);
	return amountS;
}
int wordcounter(int* arrname, int size, char* word, FILE* file)
{
	int amountW = 0;
	int amountS = 0;
	int flag = 1;//для посимвольного сравнения (становится 1 в начале слова, 0 - при не совпадении символов или большем количестве букв, знаке пунктуации, пробеле)
	int numofletters = 0;
	char ch = '.';
	while ((ch = fgetc(file)) != EOF)
	{
		if (ispunct(ch) || isspace(ch))
		{
			if (flag == 1) amountW++;
			if (ch == '!' || ch == '?' || ch == '.')
			{
				arrname[amountS] = amountW;
				amountW = 0;
				amountS++;
			}
				flag = 0;
				numofletters = 0;
		}
		else
		{
			if (numofletters == 0) flag = 1;
			numofletters++;
			if (!(numofletters > strlen(word)))
			{
				if (ch != word[numofletters-1]) flag = 0;
			}
			else flag = 0;
		}
	}
	if (ch == EOF) return 1;
	else return 0;
}

double discounter(int* arrname, int size)
{
	double average = 0;
	for (int i = 0; i<size; i++)
	{
		average = average + arrname[i];
	}
	average = average / size;
	double D = 0;
	for (int i = 0; i<size; i++)
	{
		D = D + (arrname[i] - average)*(arrname[i] - average);
	}
	D = sqrt(D / (size - 1));
	return D;
}

double dispersion(char* Word, char* File)
{
	FILE* Fileptr = fopen(File, "r");
	if (Fileptr==NULL)
	{
		printf("ERROR\nfile not find\n");
		return -1;
	}
	int N=sentencecounter(Fileptr);
	int* arrWinS = (int*)malloc(N * sizeof(int));
	if (arrWinS == NULL) 
	{ 
		return -1; 
		printf("ERROR\nmemory not allocated\n"); 
	}
	if (!wordcounter(arrWinS, N, Word, Fileptr))
	{
		printf("ERROR\nfile not read\n");
		return -1;
	}
	double dis = discounter(arrWinS, N);
	free(arrWinS);
	if (fclose(Fileptr)==0) return dis;
	else 
	{ 
		printf("ERROR\nfile not close\n"); 
		return -1; 
	}
}
