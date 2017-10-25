#include "Multiset.h"
#include <stdio.h>

using namespace std;

Multiset::Multiset()//список инициализации работает во время выделения памяти под объект
	: size(0)
	, arrptr(nullptr)
{
}

Multiset::Multiset(const int* arrptr,const int size)
{
	this->size = size;
	this->arrptr = new int[size];
	for (int i = 0; i < size; i++) // memcpy()
	{
		this->arrptr[i] = arrptr[i];
	}
}

Multiset::Multiset(const Multiset& M)
{
	this->size = M.size;
	this->arrptr = new int[size];
	for (int i = 0; i < size; i++)//memcpy
		this->arrptr[i] = M.arrptr[i];
}

Multiset::~Multiset()
{
	delete[] this->arrptr;
}

Multiset Multiset::operator + (const Multiset& M) const
{
	Multiset buf;
	Multiset buf1 = *this*M;
	buf.size = this->size + M.size-buf1.size;
	buf.arrptr = new int[buf.size];
	for (int i = 0; i < this->size; i++)//memcpy
		buf.arrptr[i] = this->arrptr[i];
	except(M, buf1, buf, this->size, false);
	return buf;
}

Multiset Multiset::operator - (const Multiset& M) const
{
	Multiset Mbuf1;
	Multiset Mbuf2 = *this*M;
	Mbuf1.size = this->size - Mbuf2.size;
	Mbuf1.arrptr = new int[Mbuf1.size];
	except(*this,Mbuf2, Mbuf1, 0, false);
	return Mbuf1;
}

Multiset Multiset::operator * (const Multiset& M) const
{
	Multiset Mbuf;
	bool* isFirst = new bool[this->size];
	for (int k = 0; k < this->size; k++)
		isFirst[k] = true;
	for (int i = 0; i < M.size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (M.arrptr[i] == this->arrptr[j]&&isFirst[j])
			{
				isFirst[j] = false;
				Mbuf.size++;
				break;
			}
		}
	}
	delete[] isFirst;
	Mbuf.arrptr = new int[Mbuf.size];
	except(M, *this, Mbuf, 0, true);
	return Mbuf;
}

Multiset& Multiset::operator = (Multiset M)
{
	std::swap(this, &M); //свапает области памяти после завершения оператора вызывается деструктор M
	return *this;
}

int& Multiset::operator[] (const int n)
{
	return this->arrptr[n];
}

ostream& operator << (ostream& stream, const Multiset& M)
{
	char buf[20];
	sprintf(buf, "%d", M.size);
	stream << "Множество размером ";
	stream << buf << ":\n"<<"{ ";
	for (int i = 0; i < M.size; i++)
	{
		sprintf(buf, "%d", M.arrptr[i]);
		stream << buf << " ";
	}
	stream << "}\n";
	return stream;
}

Multiset in_One_M(const Multiset& M1, const Multiset& M2)
{
	Multiset buf=(M1+M2)-(M1*M2);
	return buf;
}

void Multiset::except(const Multiset& M,
	const Multiset& ex,const Multiset& destination,
	int counter,
	bool inversion)
{
	bool eq = true;
	bool* isFirst = new bool[ex.size];
	for (int k = 0; k < ex.size; k++)
	{
		isFirst[k] = true;
	}
	for (int j = 0; j < M.size; j++)
	{
		eq = false;
		for (int i = 0; i < ex.size; i++)
		{
			if (ex.arrptr[i] == M.arrptr[j] && isFirst[i])
			{
				if (inversion)
				{
					destination.arrptr[counter] = M.arrptr[j];
					counter++;
				}
				isFirst[i] = false;
				eq = true;
				break;
			}
		}
		if (!inversion)
		{
			if (!eq)
			{
				destination.arrptr[counter] = M.arrptr[j];
				counter++;
			}
		}
	}
	delete[]isFirst;
}
