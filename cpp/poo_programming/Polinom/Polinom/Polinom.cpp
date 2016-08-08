/*Polinom = == + - * += -= *= val intr-un punct << >> coef max/min,
constructor cop,destructor*/


#include "math.h"
#include "conio.h"
#include <iostream>
#include<process.h>
#include<iomanip>
using namespace std;

class Polinom
{
private:
	int grad;
	double *a;
public:
	Polinom();
	Polinom (const Polinom &); //constructor de copiere
	~Polinom()
         {
				 delete[]a;
	}
	
	Polinom operator =(const Polinom &);
	Polinom operator + (Polinom );
	Polinom operator-(Polinom );
	Polinom operator*(Polinom );
	Polinom operator+=(Polinom );
	Polinom operator-=(Polinom );
	Polinom operator*=(Polinom );
	int operator==(Polinom );
	int operator!=(Polinom );
	double SumaCoef();
	double ProdCoef();
	double MaxCoef();
	double Valoare(double);
	friend ostream& operator <<(ostream &,Polinom);
	friend istream& operator >>(istream &,Polinom&);

	
};

Polinom:: Polinom(const Polinom &P)
{
	grad=P.grad;
	if(grad>=0)
			a=new double[grad+1];
	for(int i=0;i<=grad;i++)
		a[i]=P.a[i];
}

Polinom::Polinom()
{
	grad=0;
	a=new double[50];
	memset(a,0,50* sizeof(double));
	
}

Polinom Polinom:: operator = (const Polinom &P)
{
	grad=P.grad;
	a=new double[grad+1];
	for(int i=0;i<=grad;i++)
		a[i]=P.a[i];
	return (*this);

}


Polinom Polinom:: operator + (Polinom P)
{   
    Polinom S;
	if(grad>P.grad)
		S.grad=grad;
	else
		S.grad=P.grad;
	S.a=new double[S.grad+1];
    for(int i=0;i<=S.grad;i++)
		S.a[i]=a[i]+P.a[i];
	return S;
}



Polinom Polinom::operator += (Polinom P)
{
	return (*this)+P;
}

Polinom Polinom::operator - (Polinom P)
{
	Polinom D;
	if (P.grad>grad)
		D.grad=P.grad;
	else
		D.grad=grad;

	D.a=new double[D.grad+1];

	for (int i=0;i<=D.grad;i++)
		D.a[i]=a[i]-P.a[i];
	return D; 
}

Polinom Polinom::operator -= (Polinom P)
{
	return (*this)-P;
}

Polinom Polinom::operator * (Polinom P)
{
	Polinom Pr;
	Pr.grad=grad+P.grad;
 	Pr.a=new double[Pr.grad+1];

	int i,j;
	for (i=0;i<=Pr.grad;i++)
		Pr.a[i]=0;
	for (i=0;i<=grad;i++)
		for (j=0;j<=P.grad;j++)
			Pr.a[i+j]=Pr.a[i+j]+(a[i]*P.a[j]);
	return Pr;
}

Polinom Polinom::operator *= (Polinom P)
{
	return (*this)*P;
}

int Polinom:: operator == (Polinom P)
{
	if (grad!=P.grad)
		return 0;
	for (int i=0;i<=grad;i++)
		if (a[i]!=P.a[i]) 
			return 0;
	return 1;
}

int Polinom::operator != (Polinom P)
{
	if ((*this)==P)
		return 0;
	return 1;
}

double Polinom:: SumaCoef()
{
	double suma=0;
	for (int i=0;i<=grad;i++)
		suma=suma+a[i];
	return suma;
}

double Polinom:: ProdCoef()
{
	double prod=1;
	for (int i=0;i<=grad;i++)
		prod=prod*a[i];
	return prod;
}

double Polinom:: MaxCoef()
{
	double max=a[0];
	for (int i=1;i<=grad;i++)
		if (a[i]>max)
			max=a[i];
	return max;
}

double Polinom:: Valoare(double x)
{
	double val=a[0];
	for(int i=0;i<=grad;i++)
		val+=a[i]*pow(x,i);
	return val;
}
		


ostream & operator <<(ostream &out,Polinom P){
    out<<P.grad<<" "<<endl;
    for(int i=0;i<=P.grad;i++)
	out<<P.a[i]<<" ";
    return out;
}


istream & operator >>(istream &in,Polinom &P)
{
   in>>P.grad;
   for(int i=0;i<=P.grad;i++)
		in>>P.a[i];
    return in;
}


int main()
{
	Polinom c, d, e;
	int ch,x;
	cout<<"Introduceti gradul, apoi coeficientii primului polinom:";
	cin>>c;
	cout<<c;
	cout<<"Introduceti gradul, apoi coef celui de-al doilea polinom:";
	cin>>d;
	cout<<d;
	

	do
		{
		cout<<endl<<endl;
		cout<<" Apasati tasta pentru operatia dorita: "<<endl;
		cout<<" ----------------------------- "<<endl;
		cout<<"1. Adunare polinom cu polinom; "<<endl;
        	cout<<"2. Atribuire = "<<endl;
		cout<<"3. Verificare =="<<endl;
		cout<<"4.Verificare !="<<endl;
		cout<<"5.Scadere polinom cu polinom"<<endl;
		cout<<"6.Inmultire polinom cu polinom"<<endl;

		cout<<"7. Coeficientul maxim"<<endl;
		cout<<"8. Suma coeficientilor."<<endl;
		cout<<"9. Produsul coeficientilor"<<endl;
		cout<<"0. Valoarea intr-un punct"<<endl;


		
		cout<<" ESC pentru iesire "<<endl<<endl;
		ch=getch();

			switch(ch){
				case '1' :
					cout<<"suma polinoamelor este: ";
					cout<<c+d;
					break;

				case '2' :
					d=c;
					cout<<d;
					break;
				case '3' :
					if (c==d){
						cout<<"Polinoame egale"<<endl;
						break;
						}
					else{
						cout<<"Polinoame diferite"<<endl;break;}
				case '4' :
					
					if (c!=d){
						cout<<"Polinoame dif"<<endl;
						break;
						}
					else{
						cout<<"Polinoame egale"<<endl;break;}


				case '5' :
					
					cout<<"diferenta polinoamelor este: ";
					cout<<c-d;
					break;

				case '6' :
					cout<<"produsul polinoamelor este: ";
					cout<<c*d;
					break;

				case '7' :
		
					cout<<"Coeficientul maxim a polinomului este "<<c.MaxCoef()<<endl;
					break;

				case '8' :
					cout<<"Suma coeficientilor polinomului este "<<c.SumaCoef()<<endl;
					break;

				case '9' :
					cout<<"Produsul coeficientilor polinomului este "<<c.ProdCoef()<<endl;
					break;
				case '0' :
					cout<"x=";cin>>x;
					cout<<"valoarea este:"<<c.Valoare(x)<<endl;
					break;
			}

		}
		while(ch!=27);
		return 0;
}
