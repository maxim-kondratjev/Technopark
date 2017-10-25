#include <cstring>
#include "Functions.h"
#include "Worker.h"
#include <ctime>
#include <iostream>

using namespace std;

void good_cin(int& N,int bottom_line, int top_line)
{
	do
	{
		cin >> N;
		if (!cin || N>top_line || N<bottom_line) cout << "Error !! Enter again !\n";
		cin.clear();
		cin.ignore(256, '\n');
	} while (!cin || N>top_line || N<bottom_line);
}

void good_cin(int& N, int bottom_line)
{
	do
	{
		cin >> N;
		if (!cin || N<bottom_line) cout << "Error !! Enter again !\n";
		cin.clear();
		cin.ignore(256, '\n');
	} while (!cin || N<bottom_line);
}

void write_workers(Worker* &arrptr, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		int salary = 0;
		int year = 0;
		char name[40];
		char position[40];
		cout << "Работник(" << i + 1 << ")\n";
		cout << "Введите имя\n";
		cin.getline(name, 40, '\n');
		cout << "Введите должность\n";
		cin.getline(position, 40, '\n');
		cout << "Введите заработную плату\n";
		good_cin(salary, 1);
		cout << "Введите год поступления на работу\n";
		good_cin(year, 1);
		Worker buf(name, position, year, salary);
		arrptr[i]=buf;
	}
}

int menu()
{
	cout << "1-заполнение списка работников" << endl;
	cout << "2-список работников, стаж которых превышает заданное число лет" << endl;
	cout << "3-список работников, зарплата которых больше заданной" << endl;
	cout << "4-список работников, занимающих заданную должность" << endl;
	cout << "5-вывод полного списка работников" << endl;
	cout << "6-выход" << endl;
	int choice;
	good_cin(choice, 1, 6);
	return choice;
}

bool char_alloc(char* &charptr, int size)
{
	try
	{
		charptr = new char[size];
	}
	catch (std::bad_alloc& ba)
	{
		cerr << "bad_alloc caught: " << ba.what() << '\n';
		return 0;
	}
	return 1;
}

Worker* create_workeks_arr(int &N)
{
	N = -1;
	cout << "Введите число работников:\n";
	good_cin(N, 1);
	Worker* ptr = NULL;
	try
	{
		ptr = new Worker[N];
	}
	catch (std::bad_alloc& ba)
	{
		cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
	write_workers(ptr, N);
	return ptr;
}

void print_by_exp(Worker* arr, int N)
{
	int stage = -1;
	cout << "Введите нижнюю границу стажа" << endl;
	good_cin(stage, 0);
	time_t sec = time(0);
	tm* date = localtime(&sec);
	int now_year = 1900+date->tm_year;
	for (int i = 0; i < N; i++)
	{
		if (now_year-arr[i].get_entranceyear()>=stage)
			arr[i].show();
	}
}

void print_by_sal(Worker* arr, int N)
{
	int sal = -1;
	cout << "Введите нижнюю границу зарплат" << endl;
	good_cin(sal, 0);
	for (int i = 0; i < N; i++)
	{
		if (arr[i].get_salary()>=sal)
			arr[i].show();
	}
}

void print_by_pos(Worker* arr, int N)
{
	char pos[40];
	cout << "Введите искомую должность" << endl;
	cin.getline(pos, 40, '\n');
	for (int i = 0; i < N; i++)
	{
		if(strcmp(pos,arr[i].get_position())==0)//в конструкторе по умолчанию делать пустую строку
		arr[i].show();
	}
}

void print(Worker* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		arr[i].show();
	}
}
