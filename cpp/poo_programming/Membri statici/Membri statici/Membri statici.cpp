#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

class test
{
private:
	static int n;
public:
	test()
	{
		n++;
	}

	static int NrInstante()
	{
		return n;
	}
};

int test::n=0;


void main()
{
	test t1, t2, t3;
	cout<<test::NrInstante()<<endl;
	getch();
}

