// Se da un sir de caractere care contine subsirul "SA". Sa se inlocuiasca toate aparitiile acestuia cu "aa".


#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	char sirul_cu_care_inlocuim[3]="aa";
	char sirul_ce_trebuie_inlocuit[3]="SA";
	char sirul_initial[1000];

	cout<<"Introduceti un sir de caractere ce contine cel putin o data subsirul 'SA': ";
	gets(sirul_initial);

	for(int i=0;i<strlen(sirul_initial)-1;i++)
		if((sirul_initial[i]==sirul_ce_trebuie_inlocuit[0]) && (sirul_initial[i+1]==sirul_ce_trebuie_inlocuit[1]))
		{
			sirul_initial[i]=sirul_cu_care_inlocuim[0];
			sirul_initial[i+1]=sirul_cu_care_inlocuim[1];
		}
		cout<<sirul_initial;

	getch();
	return 0;
}