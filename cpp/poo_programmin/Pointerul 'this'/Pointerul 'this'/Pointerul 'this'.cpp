#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

class rational
{
private:
	long a,b;
	void simplificare();
public:
	rational (long A=0, long B=1)
	{
		a=A;
		b=B;
		simplificare();
	}

	long numarator()
	{
		return a;
	}

	long numitor()
	{
		return b;
	}

	rational operator +(rational x)
	{
		rational y;

		y.a=a*x.b+b*x.a;
		y.b=b*x.b;
		y.simplificare();
		return y;
	}

	rational operator -(rational x)
	{
		rational y;

		y.a=a*x.b-b*x.a;
		y.b=b*x.b;
		y.simplificare();
		return y;
	}

	rational operator *(rational x)
	{
		rational y;

		y.a=a*x.a;
		y.b=b*x.b;
		y.simplificare();
		return y;
	}

	rational operator /(rational x)
	{
		rational y;

		y.a=a*x.b;
		y.b=b*x.a;
		y.simplificare();
		return y;
	}

	rational operator =(rational &x)
	{
		a=x.a;
		b=x.b;
		return *this;
	}

	rational operator +=(rational x)
	{
		return *this=*this+x;
	}

	rational operator -=(rational x)
	{
		return *this=*this-x;
	}

	rational operator *=(rational x)
	{
		return *this=*this*x;
	}

	rational operator /=(rational x)
	{
		return *this=*this/x;
	}

	int operator ==(rational x)
	{
		return a==x.a && b==x.b;
	}

	int operator !=(rational x)
	{
		return !(*this==x);
	}

	rational operator ++()
	{
		a+=b;
		return *this;
	}

	rational operator --()
	{
		a-=b;
		return *this;
	}

	rational operator ++(int)
	{
		rational c=*this;

		a+=b;
		return c;
	}

	rational operator --(int)
	{
		rational c=*this;

		a-=b;
		return c;
	}

	long operator !()
	{
		return !a;
	}

	int operator <(rational x)
	{
		if((a*x.b)<(x.a*b))
			return 1;
		return 0;
	}
	
	int operator <=(rational x)
	{
		if((a*x.b)==(b*x.a))
			return 1;
		if(*this<x)
			return 1;
		return 0;
	}

	int operator >(rational x)
	{
		if((a*x.b)>(x.a*b))
			return 1;
		return 0;
	}
	
	int operator >=(rational x)
	{
		if((a*x.b)==(b*x.a))
			return 1;
		if(*this>x)
			return 1;
		return 0;
	}

	friend ostream& operator <<(ostream& out, rational x)
	{
		out<<"("<<x.a<<","<<x.b<<")";
		return out;
	}

	friend istream& operator >>(istream& in, rational x)
	{
		in>>x.a>>x.b;
		return in;
	}

};

void rational::simplificare()
{
	long A=a, B=b, r;

	while (B)
	{
		r=A%B;
		A=B;
		B=r;
	}
	if(A)
	{
		a/=A;
		b/=A;
	}
}


void main()
{
	rational x(7,15), y(1,5), z, t(3,7), u(5,8);

	z=x+y;
	cout<<x<<"+"<<y<<"="<<z<<endl;
	cout<<x<<"-"<<y<<"="<<(x-y)<<endl;
	cout<<x<<"*"<<y<<"="<<(x*y)<<endl;
	cout<<x<<"/"<<y<<"="<<(x/y)<<endl;
	if(t<u)
		cout<<t<<"<"<<u<<endl;
	if(x>=y)
		cout<<x<<">="<<y<<endl;

	getch();
}

