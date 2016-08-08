// Sa se determine daca un sir de caractere contine un anu,e caracter si daca da sa spuna de cate ori.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <malloc.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char sirul[100], caracterul_cautat;						// sirul si caracaterul ce dorim sa il cautam in sir
	int contor=0;												

	cout<<"Introduceti un sir de caractere: ";
	gets(sirul);
	
	cout<<"Introduceti un caracter ce doriti sa aflati daca exista in sirul introdus: ";
	cin>>caracterul_cautat;
	cout<<endl;

	for(int i=0;i<strlen(sirul);i++)
		if(caracterul_cautat==sirul[i])
			contor++;

	if(contor==0)
		cout<<"In sirul intorus nu se gaseste caracterul cautat!";
	else
		if(contor==1)
			cout<<"In sirul introdus caracterul "<<caracterul_cautat<<" apare o singura data!";
		else
			cout<<"In sirul introdus caracterul "<<caracterul_cautat<<" apare de "<<contor<<" ori!";

	getch();
	return 0;
}
