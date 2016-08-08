#include <stdafx.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#pragma warning(disable:4996)

using namespace std;


class stringa
{
private:
	char *s;
public:
	stringa(char *st="")
	{
		s=new char[strlen(st)+1];
		strcpy(s,st);
	}

	stringa(const stringa &str)
	{
//		delete [] s;
		s=new char[strlen(str.s)+1];
		strcpy(s,str.s);
	}

	~stringa()
	{
		delete [] s;
	}

	stringa operator +(stringa str)
	{
		char *st;
		
		st=new char[strlen(s)+strlen(str.s)+1];
		stringa str2(st);
		sprintf(str2.s,"%s%s",s,str.s);
		return str2;
	}

	stringa operator =(const stringa &str)
	{
		delete [] s;
		s=new char[strlen(str.s)+1];
		strcpy(s,str.s);
		return *this;
	}

	stringa operator +=(const stringa &str)
	{
		*this=*this+str;
		return *this;
	}

	int operator ==(const stringa &str)
	{
		if(!strcmp(s,str.s))
			return 1;
		return 0;
	}

	int operator <(stringa str)
	{
		if(strcmp(s,str.s)<0)
			return 1;
		return 0;
	}

	int operator <=(const stringa &str)
	{
		if(strcmp(s,str.s)<=0)
			return 1;
		return 0;
	}

	int operator >(const stringa &str)
	{
		if(strcmp(s,str.s)>0)
			return 1;
		return 0;
	}

	int operator >=(const stringa &str)
	{
		if(strcmp(s,str.s)>=0)
			return 1;
		return 0;
	}

	void set(char *st)
	{
		delete [] s;
		s=new char[strlen(st)+1];
		strcpy(s,st);
	}

	void get(char *st)
	{
		strcpy(st,s);
	}

	int operator !()
	{
		return strlen(s);
	}

	char operator [](int i)
	{
		return s[i];
	}
	
	friend ostream& operator <<(ostream &out, const stringa &str)
	{
		out<<str.s;
		return out;
	}

	friend istream& operator >>(istream &in, const stringa &str)
	{
		in>>str.s;
		return in;
	}
};


void main(void)
{
	stringa s1("string-ul 1"), s2, s;
	char st[100];

	s2.set("string-ul 2");
	s=s1+s2;
	cout<<"Concatenarea celor 2 stringuri: "<<s<<endl;
	s+=s1;
	cout<<"Concatenarea celor 2 stringuri: "<<s<<endl;
	cout<<"Lungimea string-ului: "<<!s<<endl;
	cout<<"Pe pozitia 5 se afla caracterul: "<<s[4]<<endl;
	if(s1==s2)
		cout<<"String-urile sunt identice"<<endl;
	else
		cout<<"String-urile difera"<<endl;
	if(s1<s2)
		cout<<"s1<s2"<<endl;
	s.get(st);
	cout<<"String-ul extras: "<<st<<endl;
		
	getch();
}

