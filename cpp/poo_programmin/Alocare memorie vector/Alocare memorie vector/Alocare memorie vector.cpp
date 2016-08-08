#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int n,*a;

	cout<<"Dati lungimea vectorului: ";
	cin>>n;

	if(!(a=new int[n]))
	{
		cerr<<"Eroare! Memorie insuficienta."<<endl;
		exit(1);
	}

	delete [] a;

	return 0;
}

