// Se da un sir de caractere.Sa se inverseze sirul.


#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	char sir[1000];
	cout<<"Dati un sir de caractere ce doriti sa il vedeti inversat: "<<endl;
	gets(sir);
	strrev(sir);
	cout<<sir;

	getch();
	return 0;
}