#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int a=1,b=0;

	try
	{
		if(!b)
			throw "Impartire prin zero.";
		cout<<(a/b)<<endl;
	}
	catch(char *mesaj_Eroare)
	{
		cerr<<mesaj_Eroare<<endl;
	}

	getch();
	return 0;
}

