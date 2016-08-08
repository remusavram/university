/* Se da o fraza care contine cuvinte respectiv: ",", "?", "!". Sa se afiseze toate cuvintele in ordinea care apar in fraza."
Adina are mere!

1. Adina
2. are
3. mere!
*/

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
	{

	char propozitie[1000];
	int nr=1, x;
	cout<<"Introduceti o propozitie: ";
	gets(propozitie);
	x=strlen(propozitie);
	while(propozitie[0]==' ')
		for(int i=0;i<x;i++)
			propozitie[i]=propozitie[i+1];
	cout<<endl<<nr++<<". ";
	for(int i=0;i<strlen(propozitie)-1;i++)
	{
		if(propozitie[i]==' ' && propozitie[i+1]!=' ' && propozitie[i]!='!' && propozitie[i]!='?' && propozitie[i]!=';' && propozitie[i]!=':' && propozitie[i]!=',' && propozitie[i]!='.' && propozitie[i+1]!='!' && propozitie[i+1]!='?' && propozitie[i+1]!=';' && propozitie[i+1]!=':' && propozitie[i+1]!=',' && propozitie[i+1]!='.')
		{
			cout<<endl<<nr<<". ";
			nr++;
		}
		else
			if(propozitie[i]!='!' && propozitie[i]!='?' && propozitie[i]!=';' && propozitie[i]!=':' && propozitie[i]!=',' && propozitie[i]!='.')
				cout<<propozitie[i];
	}
	if(propozitie[strlen(propozitie)-1]!=' ' && propozitie[strlen(propozitie)-1]!='!' && propozitie[strlen(propozitie)-1]!='?' && propozitie[strlen(propozitie)-1]!=';' && propozitie[strlen(propozitie)-1]!=':' && propozitie[strlen(propozitie)-1]!=',' && propozitie[strlen(propozitie)-1]!='.') 
		cout<<propozitie[strlen(propozitie)-1];

	getch();
	return 0;
}
