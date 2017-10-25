#ifndef MULTISET
#define MULTISET

#include <iostream>

using namespace std;

class Multiset
{
public:
	Multiset();
	Multiset(const int* arrptr,const int size);
	Multiset(const Multiset& Multiset);
	~Multiset();
	Multiset operator + (const Multiset& M) const; // vim; sizeof
	Multiset operator - (const Multiset& M) const; //можно возвращать const...
	Multiset operator * (const Multiset& M) const;
	Multiset& operator = (const Multiset& M);
	int& operator [] (const int n);
	friend ostream& operator << (ostream& stream, const Multiset& Multiset);

private:
	void except(const Multiset &M,
		const Multiset& exception,
		const Multiset& destination,
		int counter,
		bool inversion);//используется в операторах и нигде больше поэтому можно private
	int size;
	int* arrptr;
};

Multiset in_One_M(const Multiset& M1, const Multiset& M2);//к приватным полям не обращается поэтому выносим из коасса

#endif
