#include <new>
#include <string.h>
#include <iostream>
#include "Worker.h"
#include "Functions.h"
#include <stdlib.h>

using namespace std;

Worker& Worker::operator=(Worker& buf)
{
	set_name(buf.name);
	set_position(buf.position);
	set_entranceyear(buf.entranceyear);
	set_salary(buf.salary);
	return *this;
}


Worker::Worker(char* name, char* position, int year, int salary)
{
	char_alloc(this->name, strlen(name)+1);
	memcpy(this->name, name, strlen(name)+1);
	char_alloc(this->position, strlen(position)+1);//обработку ошибок не делаем try catch
	memcpy(this->position, position, strlen(position)+1);
	this->entranceyear = year;
	this->salary = salary;
}

Worker::Worker()
{
	this->name = NULL;
	this->position = NULL;
	this->entranceyear = 0;
	this->salary = 0;
}

Worker::~Worker()
{
	delete this->name;
	delete this->position;
}

void Worker::set_name(char* name)
{
	if ((this->name)!=NULL)
	{
		delete this->name;
	}
	char_alloc(this->name, strlen(name) + 1);
	memcpy(this->name, name, strlen(name) + 1);
}

char* Worker::get_name()
{
	return this->name;
}

void Worker::set_position(char* position) 
{
	if ((this->position) != NULL)
	{
		delete this->position;
	}
	char_alloc(this->position, strlen(position) + 1);
	memcpy(this->position, position, strlen(position) + 1);
}

char* Worker::get_position()
{
	return this->position;
}

void Worker::set_entranceyear(int year)
{
	this->entranceyear = year;
}

int Worker::get_entranceyear()
{
	return this->entranceyear;
}

void Worker::set_salary(int salary)
{
	this->salary = salary;
}

int Worker::get_salary()
{
	return this->salary;
}

void Worker::show()
{
	cout << "---------------------------" << endl;
	cout << "Работник " << this->name << ":" << endl;
	cout << "Должность: "<< this->position << endl;
	cout << "Год поступления на работу: " << this->entranceyear << "г. " << endl;
	cout << "Зарплата: " << this->salary << "р" << endl;
	cout << "---------------------------" << endl;
}
