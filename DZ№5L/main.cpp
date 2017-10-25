#include "Multiset.h"

using namespace std;

int main()//нет обработки ошибок при выделении памяти
{
	setlocale(LC_ALL, "");
	int arr1[]={3,3,3,3};
	int arr2[] = {3,3,3,4};
	Multiset a(arr1, 4);//sizeof(arr1)/sizeof(*arr1) для размера
	cout << a;
	Multiset b(arr2, 4);
	cout << b;
	Multiset d = a + b;
	cout << d;
	Multiset c = a*b;
	cout << c;
	d = d - c;
	cout << d;
	d = in_One_M(a, b);
	cout << d;
}
