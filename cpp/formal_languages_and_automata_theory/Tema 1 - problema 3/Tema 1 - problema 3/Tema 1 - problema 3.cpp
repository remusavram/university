// Se da un sir de caractere care contine subsirul "SA". Sa se inlocuiasca toate aparitiile acestuia cu "aa".


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <malloc.h>

using namespace std;


int strreplace1(char *s1, char *s2, char *s3)   //inlocuirea primei aparitii
{
	char *poz, *s4;
	long l, l2=strlen(s1);
	poz=strstr(s1,s2);
	if(poz!=NULL)
	{
		l=poz-s1;
		s4=new char[strlen(s1)+1];
		strcpy(s4,s1);
		strncpy(s1,s4,l);
		s1[l]='\0';
		strcat(s1,s3);
		for(int i=0;i<l2+strlen(s2)-l;i++)
			s4[i]=s4[i+l+strlen(s2)];
		strcat(s1,s4);
		delete [] s4;
		return l+1; 
	}
	return 0;
}


int strreplace(char *s1, char *s2, char *s3)		// inlocuirea tuturor aparitiilor
{
	char *poz;
	poz=strstr(s1,s2);
	while(poz!=NULL)
	{
		strreplace1(s1,s2,s3);
		poz=strstr(s1,s2);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{

	char sirul_cu_care_inlocuim[3]="aa", sirul_ce_trebuie_inlocuit[3]="SA", sirul_initial[1000]; 
	cout<<"Introduceti un sir de caractere ce contine cel putin o data subsirul 'SA': "<<endl;
	gets(sirul_initial);
	strreplace(sirul_initial,sirul_ce_trebuie_inlocuit,sirul_cu_care_inlocuim);
	cout<<sirul_initial;
	
	getch();
	return 0;
}




/*
char sirul_cu_care_inlocuim[3]="aa";
	char sirul_ce_trebuie_inlocuit[3]="SA";
	char sirul_initial[1000];

	cout<<"Introduceti un sir de caractere ce contine cel putin o data subsirul 'SA': ";
	gets(sirul_initial);

	char *verificare=strstr(sirul_initial,sirul_ce_trebuie_inlocuit);
	while(verificare!=NULL)
	{
		char *poz, sir_temp[1000];
		long lungime;
		poz=strstr(sirul_initial,sirul_ce_trebuie_inlocuit);
		if(poz!=NULL)
		{
			lungime=poz-sirul_initial;								// pozitia aparitiei
			strcpy(sir_temp,sirul_initial);							// se copiaza sirul_initial in sir_temp
			strncpy(sirul_initial,sir_temp,lungime);
			sirul_initial[1]='\0';
			strcat(sirul_initial,sirul_ce_trebuie_inlocuit);
			strcat(sirul_initial,poz+strlen(sirul_cu_care_inlocuim));
			free(sir_temp);
		}
		verificare=strstr(sirul_initial,sirul_ce_trebuie_inlocuit);
	}
	cout<<sirul_initial;

	for(int i=s4[l+2];i<l2;i++)
		{
			s5[n]=s4[i];
			n++;
		}
*/