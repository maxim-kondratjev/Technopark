#ifndef WORKER
#define WORKER
class Worker
{
public:
	Worker(char* name, char* pos, int year, int salary);
	Worker();
	~Worker();
	Worker& operator=(Worker& buf);
	void set_name(char*);//const char*
	void set_position(char*);//...
	void set_entranceyear(int);
	void set_salary(int);
	char* get_name();//const char* (char* const????!!?! ПОЧИТАТЬ)
	char* get_position();//...
	int get_entranceyear();
	int get_salary();
	void show();
private:
	char* name;
	char* position;
	int entranceyear;
	int salary;
};
#endif
