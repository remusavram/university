// Markov.


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <fstream>

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
		strcpy(s4,s1);								//inlocuieste s4 cu s1
		strncpy(s1,s4,l);							// inlocuieste s1 cu s4 l caractere
		s1[l]='\0';									// transforma in sir
		strcat(s1,s3);								// adauga s3
		for(int i=0;i<l2+strlen(s2)-l;i++)			// sterge l caractere din s4	
			s4[i]=s4[i+l+strlen(s2)];
		strcat(s1,s4);								// punem in s1 ce a ramas din s4
		delete [] s4;								// eliberem s4
		return l+1; 
	}
	return 0;
}


int strreplace(char *s1, char *s2, char *s3, int &contor)		// inlocuirea tuturor aparitiilor
{
	char *poz;
	poz=strstr(s1,s2);
	while(poz!=NULL)
	{
		strreplace1(s1,s2,s3);
		cout<<endl<<contor++<<". "<<s1;
		poz=strstr(s1,s2);
	}
	return 0;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	char regula1[100][100],regula2[100][100],propozitie[1000];		
	ifstream f("Numere.in");
	f>>n;
	for(int i=0;i<n;i++)
	{
		f>>regula1[i];
		f>>regula2[i];
	}
	f>>propozitie;
	f.close();
	cout<<"Regulile citite din fisier sunt: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<regula1[i]<<" -> ";
		cout<<regula2[i]<<endl;
	}
	cout<<endl<<"Propozitia citita din fisier este: "<<endl;
	cout<<propozitie<<endl<<endl;
	cout<<"Modificarile pe parcurs sunt: ";

	int verifica=1, contor=1;
	char *propozitie_temp;
	propozitie_temp=new char[strlen(propozitie)+1];
	while(verifica!=0)
	{
		for(int i=0;i<n;i++)
		{
			verifica=0;
			strcpy(propozitie_temp,propozitie);
			strreplace(propozitie,regula1[i],regula2[i],contor);
			if(strcmp(propozitie,propozitie_temp)!=0)
			{
	//			cout<<endl<<contor++<<". "<<propozitie;
				verifica=1;
				break;
			}
		}

	}
	cout<<endl<<endl<<"Rezultatul: "<<propozitie;

	getch();
	return 0;
}
