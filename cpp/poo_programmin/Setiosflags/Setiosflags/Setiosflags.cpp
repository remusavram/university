#include "stdafx.h"
#include "iostream"
#include "iomanip"
#include "conio.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int i=100;
	cout<<setfill('.');
	
	cout<<setiosflags(ios::left);
	cout<<setw(10)<<"Baza 8";
	cout<<setiosflags(ios::right);
	cout<<setw(10)<<oct<<i<<endl;

	cout<<resetiosflags(ios::right);
	cout<<setw(10)<<"Baza 10";
	cout<<setiosflags(ios::dec | ios::right);
	cout<<setw(10)<<i<<endl;
	
	cout<<resetiosflags(ios::right);
	cout<<setw(10)<<"Baza 16";
	cout<<setiosflags(ios::right);
	cout<<setw(10)<<hex<<i<<endl;

	getch();
	return 0;
}
