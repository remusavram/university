#include "stdafx.h"
#include <iostream>
//#include<fstream>
#include<conio.h>

using namespace std;

class Vector
{
private:
	int distanta,*v;
public:
	Vector(int distanta);
	Vector(const Vector& vec);
	Vector& operator =(Vector& vec);
	~Vector();

	int GetDistanta()
	{
		return distanta;
	}

	int Get(int i)
	{
		if(i<0 || i>=distanta)
			throw "Index Out Of Bounds";
		return v[i];
	}

	friend ostream& operator<<(ostream& out, Vector& vec);
	friend istream& operator>>(istream& in, Vector& vec);

	friend Vector operator +(Vector &v1, Vector &v2)
	{
		Vector rez(v1.distanta);
		for(int i=0;i<rez.distanta;i++)
			rez.v[i]=v1.v[i]+v2.v[i];
		return rez;
	}

	friend Vector operator -(Vector &v1, Vector &v2)
	{
		Vector rez(v1.distanta);
		for(int i=0;i<rez.distanta;i++)
			rez.v[i]=v1.v[i]-v2.v[i];
		return rez;
	}

	friend Vector operator *(Vector &v1, int x)
	{
		Vector rez(v1.distanta);
		for(int i=0;i<rez.distanta;i++)
			rez.v[i]=v1.v[i]*x;
		return rez;
	}

	friend Vector operator +=(Vector &v1, Vector &v2)
	{
		v1=v1+v2;
	
	}

};

Vector::Vector(int distanta)
{
	this->distanta=distanta;
	v=new int[distanta];
	for(int i=0;i<distanta;i++)
		v[i]=0;
}

Vector::~Vector()
{
	delete [] v;
}

Vector::Vector(const Vector& vec)
{
	distanta=vec.distanta;
	v=new int[distanta];
	for(int i=0;i<distanta;i++)
		v[i]=vec.v[i];
}

Vector& Vector::operator=(Vector& vec)
{
	if(this!=&vec)
	{
		for(int i=0;i<distanta;i++)
			delete [] v;
		distanta=vec.distanta;

		v=new int[distanta];
		for(int i=0;i<distanta;i++)
			v[i]=vec.v[i];
	}
	return *this;
}

ostream& operator<<(ostream& out, Vector &vec)
{
	for(int i=0;i<vec.distanta;i++)
			out<<vec.v[i]<<" ";
		out<<endl;
	return out;
}

istream& operator>>(istream& in, Vector& vec)
{
	for(int i=0;i<vec.distanta;i++)
	{
		cout<<"v["<<i+1<<"]= ";
		in>>vec.v[i];
	}
	return in;
}

void main()
{
/*	int distanta1,distanta2;


	ifstream f("Vectori.in");
	f>>distanta1;

	Vector vec(distanta1);
	f>>vec;

	Vector vector1=vec;

	f.close();

	ofstream g("Vectori.out");
	g<<vector1;
	g<<endl;

	g.close();
*/
	int distanta;
	cout<<"Introduceti dimensiunea vectorilor: ";
	cin>>distanta;
	cout<<endl<<"Introduceti elementele primului vector: "<<endl;
	Vector vec1(distanta);
	cin>>vec1;
	cout<<endl<<"Introduceti elementele celui de-al doilea vector: "<<endl;
	Vector vec2(distanta);
	cin>>vec2;
	
	Vector rez1=vec1+vec2;
	cout<<endl<<"Suma celor doi vectori este: ";
	cout<<rez1;

	Vector rez2=vec1-vec2;
	cout<<endl<<"Diferenta dintre primul vector si al doilea este: ";
	cout<<rez2;

	Vector rez3=vec1*3;
	cout<<endl<<"Imultirea primului vector cu 3 este: ";
	cout<<rez3;

	ofstream g("Vectori.out");
	g<<"Suma celor doi vectori este: ";
	g<<rez1<<endl;
	g<<"Diferenta dintre primul vector si al doilea este: ";
	g<<rez2<<endl;
	g<<"Imultirea primului vector cu 3 este: "<<rez3;

	g.close();
	getch();
}

