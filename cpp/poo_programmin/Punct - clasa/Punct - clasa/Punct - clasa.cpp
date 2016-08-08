#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <math.h>

using namespace std;

class Punct
{
private:
	double x,y;
public:
	Punct(double x=0, double y=0)
	{
		cout<<"apel constructor"<<endl;
		this->x=x;
		this->y=y;
	}

	double Get_x()
	{
		return x;
	}

	double Get_y()
	{
		return y;
	}

	void Set_x(double newx)
	{
		x=newx;
	}

	void Set_y(double newy)
	{
		y=newy;
	}

	double DistanceTo(Punct p)
	{
		return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
	}

	static double Distance2(Punct p1, Punct p2)
	{
		return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
	}

	static int Coliniare(Punct p1, Punct p2, Punct p3);
	friend ostream& operator <<(ostream& , Punct);
};

int Punct::Coliniare(Punct p1, Punct p2, Punct p3)
{
	if((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y)==0)
		return 1;
	return 0;
}

ostream& operator <<(ostream& out, Punct p)
{
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}

double Distance(Punct p1, Punct p2)
{
	return sqrt(pow(p2.Get_x()-p1.Get_x(),2)+pow(p2.Get_y()-p1.Get_y(),2));
}

int Exista_Coliniare(Punct *p, int n)
{
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for(int k=j+1;k<n;k++)
				if(Punct::Coliniare(p[i],p[j],p[k]))
					return 1;
	return 0;
}

void main()
{
	Punct *p;
	int n;

	cout<<"n= ";
	cin>>n;
	p=new Punct[n];
	for(int i=0;i<n;i++)
	{
		double x,y;
		cout<<"x= ";
		cin>>x;
		cout<<"y= ";
		cin>>y;
		p[i].Set_x(x);
		p[i].Set_y(y);
	}
	double max=0;

	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(Punct::Distance2(p[i],p[j])>max)
				max=Punct::Distance2(p[i],p[j]);
	cout<<"Distanta max intre 2 pct: "<<max<<endl;
	if(Exista_Coliniare(p,n))
		cout<<"Exista pt. coliniare"<<endl;
	else
		cout<<"Nu exista pt coliniare"<<endl;
	for(int i=0;i<n;i++)
		cout<<p[i]<<" ";
	delete [] p;

	getch();
}

