
#include <iostream>

using namespace std;

class File
{
public:
	File()
	{
		const char buf[9] = "newfile\0";
		filename = new char[strlen(buf) + 1];
		strcpy_s(filename, strlen(buf) + 1, buf);
		cout << "create: " << filename;
	}
	virtual void Open() = 0;
	virtual ~File()
	{
		cout << filename << endl;
		delete[]filename;
	}
protected:
	char* filename;
	void rename(const char* name,const char* res)
	{
		char* buf = new char[strlen(name) + 1];
		strcpy_s(buf, strlen(name) + 1, name);
		delete[] filename;
		filename = new char[strlen(buf) + 1 + strlen(res)];
		strcpy_s(filename, strlen(buf) + 1, buf);
		strcat_s(filename, strlen(buf) + 1 + strlen(res), res);
	}
};

class Image :public File
{
public:
	Image()
	{
		rename(filename,".image");
		cout << "("<<filename<<")"<< endl;
	}
	Image(const char* name)
	{
		rename(name,".image");
		cout << "(" << filename << ")" << endl;
	}
	void Open()
	{
		cout << "open: " << filename << endl;
	}
	~Image() 
	{
		cout << "delete: ";
	};
};

class Video :public File
{
public:
	Video()
	{
		rename(filename, ".video");
		cout << "(" << filename << ")" << endl;
	}
	Video(const char* name)
	{
		rename(name, ".video");
		cout << "(" << filename << ")" << endl;
	}
	void Open()
	{
		cout << "open: " << filename << endl;
	}
	~Video()
	{
		cout << "delete: ";
	};
};

class Text :public File
{
public:
	Text()
	{
		rename(filename, ".text");
		cout << "(" << filename << ")" << endl;
	}
	Text(const char* name)
	{
		rename(name, ".text");
		cout << "(" << filename << ")" << endl;
	}
	void Open()
	{
		cout << "open: " << filename << endl;
	}
	~Text()
	{
		cout << "delete: ";
	};
};
