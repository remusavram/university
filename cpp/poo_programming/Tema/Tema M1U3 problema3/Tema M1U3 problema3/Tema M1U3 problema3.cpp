#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>

using namespace std;


void spati()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

//============== Minimul ==============

template <class T>
T minimul(T x, T y, T z)
{
	T min=x;
	if(min>y)
		min=y;
	if(min>z)
		min=z;
	return min;
}

//=============== Maximul ===============

template <class T>
T maxim_elemente(T *s)
{
	T nr=strlen(s);
	for(int i=0;i<strlen(s);i++)
		if(s[i]==' ')
			nr--;
	return nr;
}

//============= Cautare secventiala =============

template <class T>
T cautare_secventiala(T *s,T c)
{
	for(int i=0;i<strlen(s);i++)
		if (c==s[i])
			return 1;
	return 0;
}

//================ Cautare Binara ================

template <class T>
T cautare_binara(T *v,T n, T x)
{
	if(x<v[n/2]+1)
		for(int i=0;i<((n/2)+1);i++)
			if(x==v[i])
				return 1;
	if(x>v[n/2])
		for(int i=n/2;i<n;i++)
			if(x==v[i])
				return 1;
	return 0;
}

//================ Interclasare ================

template <class T>
void interclasare(T n, T m, T *v1, T *v2)
{
	T *v3;
	int c1=0,c2=0,c3=0;
	v3=new T[n+m];							//alocam memorie pt un nou vector unde vom pune elementele celor 2 vectori in ordine crescatoare
	for(int i=0;i<(n+m);i++)
	{
	if((c1==n) && (c2!=m))					//verificam daca primul sir a ajuns la sfarsit
			for(int j=n+c2;j<n+m;j++)
				v3[c3++]=v2[c2++];		    //daca da, punem restul elementelor din sirul 2 in sirul nou 
	else
		if((c2==m) && (c1!=n))				//verificam daca al doilea sir a ajuns la sfarsit
			for(int j=m+c1;j<n+m;j++)
				v3[c3++]=v1[c1++];			//daca da, punem restul elementelor din sirul 1 in sirul nou 
		else
			if(v1[c1]<=v2[c2])				//verificam la prozitiile ce au ajuns sirurile care nr. este mai mic
				v3[c3++]=v1[c1++];
			else
				v3[c3++]=v2[c2++];
	}
	if((m+n)==0)
		cout<<endl<<"Nu ati introdus nici un element!"<<endl;
	else
	{
	cout<<endl<<endl<<"Elementele sirurilor interclasate sunt: ";
	for(int i=0;i<((n+m)-1);i++)
		cout<<v3[i]<<", ";
	cout<<v3[m+n-1]<<".";
	}
	delete [] v3;
}

//================== Produs a 2 matrici ==================

template <class T>
void produs_matrice(T nr_lini_matrice_1, T nr_coloane_matrice_1, T **matrice_1, T nr_lini_matrice_2, T nr_coloane_matrice_2, T **matrice_2)
{
	T nr_lini_matrice_3=nr_lini_matrice_1, nr_coloane_matrice_3=nr_coloane_matrice_2;
	T **matrice_3;
	matrice_3=new T*[nr_lini_matrice_3];				//alocam memorie pentru o noua matrice unde vorm retine produsul celor 2 matrici
	for(int i=0;i<nr_lini_matrice_3;i++)
		matrice_3[i]=new T[nr_coloane_matrice_3];
	for(int i=0;i<nr_lini_matrice_3;i++)
		for(int j=0;j<nr_coloane_matrice_3;j++)
			matrice_3[i][j]=0;							//initializam cu 0 elementele matricii noi
	for(int i=0;i<nr_lini_matrice_1;i++)
		for(int j=0;j<nr_coloane_matrice_2;j++)
			for(int k=0;k<nr_lini_matrice_2;k++)
				matrice_3[i][j]=matrice_3[i][j] + matrice_1[i][k]*matrice_2[k][j];	//facem produsul matricilor si il retinem in matricea noua
	cout<<setiosflags(ios::fixed | ios::left);
	for(int i=0;i<nr_lini_matrice_3;i++)
	{
		for(int j=0;j<nr_coloane_matrice_3;j++)
			cout<<setprecision(2)<<setw(9)<<matrice_3[i][j];		//afisam produsul dintre cele 2 matrici
		cout<<endl;
	}
	for(int i=0;i<nr_lini_matrice_3;i++)				//eliberam memoria alocata pentru matricea produs
		delete [] matrice_3[i];		
	delete [] matrice_3;
}

//================== Ridicare matrice la o putere ==================

template <class T>
void ridicare_putere_matrice(int nr_lini_coloane_m, T **matrice_initiala, T **&matrice_rezultat)
{
	T **matrice_temp;
	matrice_temp=new T*[nr_lini_coloane_m];					//alocam memorie pentru o matrice temporara ce va retine produsul dintre matricea initial introdusa si matricea rezultata la un anumit ordin
	for(int i=0;i<nr_lini_coloane_m;i++)
		matrice_temp[i]=new T[nr_lini_coloane_m];
	for(int i=0;i<nr_lini_coloane_m;i++)
		for(int j=0;j<nr_lini_coloane_m;j++)
			matrice_temp[i][j]=0;							//initializam elementele matrii alocate temporar cu 0
	for(int i=0;i<nr_lini_coloane_m;i++)
		for(int j=0;j<nr_lini_coloane_m;j++)
			for(int k=0;k<nr_lini_coloane_m;k++)
				matrice_temp[i][j]=matrice_temp[i][j]+matrice_initiala[i][k]*matrice_rezultat[k][j];		//calculam produsul dintre matricea initiala si matricea rezultata
	for(int i=0;i<nr_lini_coloane_m;i++)
		for(int j=0;j<nr_lini_coloane_m;j++)
			matrice_rezultat[i][j]=matrice_temp[i][j];		//matricea rezultat ia valoarea matrici temporare in care am calculat produsul dintre matircea rezultat si matricea initiala
	for(int i=0;i<nr_lini_coloane_m;i++)	
		delete [] matrice_temp[i];							//eliberam memoria matrici temporare
	delete [] matrice_temp;
}

//========================== Program principal ==========================

int _tmain(int argc, _TCHAR* argv[])
{
	int a,b,c,min,x;
	char optiune,s1[1000],caracter,s2[1000];	

	do
	{
		spati();
		cout<<"1. Minimul a 3 valori."<<endl;
		cout<<"2. Maximul elementelor unui sir."<<endl;
		cout<<"3. Cautare secventiala intr-un sir."<<endl;
		cout<<"4. Cautare binara intr-un sir."<<endl;
		cout<<"5. Interclasarea a doua siruri sortate crescator."<<endl;
		cout<<"6. Produs a 2 matrici."<<endl;
		cout<<"7. Ridicare matrice la o putere."<<endl;
		cout<<"Esc - parasire program!"<<endl;

		optiune=getch();
		spati();
		switch(optiune)
		{
			case '1':
				cout<<"Introduceti numerele ce doriti sa aflati minimul: "<<endl<<endl;
				cout<<"a= ";
				cin>>a;
				cout<<"b= ";
				cin>>b;
				cout<<"c= ";
				cin>>c;
				min=minimul(a,b,c);
				cout<<endl<<"Minimul dintre numerele "<<a<<", "<<b<<", "<<c<<" este: "<<min<<endl;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '2':
				fflush(stdin);
				cout<<"Introduceti sirul: ";
				gets(s1);
				x=maxim_elemente(s1);
				cout<<endl<<"Maximul elementelor din sirul introdus este: "<<x<<endl;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '3':
				fflush(stdin);
				cout<<"Introduceti sirul: ";
				gets(s2);
				cout<<"Introduceti caracterul ce doriti sa il cautati secvential: ";
				cin>>caracter;
				if(cautare_secventiala(s2,caracter))
					cout<<endl<<endl<<"Exista '"<<caracter<<"' in sir!"<<endl;
				else
					cout<<"Nu exista "<<caracter<<" in sir!"<<endl;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '4':
				int n,*v1,y;
				cout<<"Introduceti nr de elemente al vectorului: ";
				cin>>n;
				v1=new int[n];
				for(int i=0;i<n;i++)
				{
					cout<<"v["<<i+1<<"]= ";
					cin>>v1[i];
				}
				cout<<endl<<"Introduceti nr. ce doriti sa il cautati binar: ";
				cin>>y;
				if(cautare_binara(v1,n,y))
					cout<<"Exista '"<<y<<"' in vector!"<<endl;
				else
					cout<<"Nu exista "<<y<<" in sir!"<<endl;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '5':
				int p,m,*v2,*v3;
				cout<<"Introduceti nr. de elemente al primului sir: ";
				cin>>p;
				if(p!=0)
				{
					v2=new int[p];
					cout<<endl<<"Introduceti elementele primului sir ordonat crescator: "<<endl;
					for(int i=0;i<p;i++)
					{
						cout<<"v1["<<i+1<<"]= ";
						cin>>v2[i];
					}
				}
				cout<<endl<<endl<<"Introduceti nr. de elemente pentru al doilea sir: ";
				cin>>m;
				if(m!=0)
				{
					v3=new int[m];
					cout<<endl<<"Introduceti elementele pentru al doilea sir ordonat crescator: "<<endl;
					for(int i=0;i<m;i++)
					{
						cout<<"v2["<<i+1<<"]= ";
						cin>>v3[i];
					}
				}
				interclasare(p,m,v2,v3);
				delete [] v2;
				delete [] v3;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '6':
				float nr_lini_matrice_1, nr_lini_matrice_2, nr_coloane_matrice_1, nr_coloane_matrice_2;
				float  **matrice_1, **matrice_2;
				cout<<"Dati nr. de lini a matricii 1: ";			
				cin>>nr_lini_matrice_1;
				cout<<"Dati nr. de coloane a matricii 1: ";
				cin>>nr_coloane_matrice_1;
				matrice_1=new float*[nr_lini_matrice_1];
				for(int i=0;i<nr_lini_matrice_1;i++)						//alocam memorie pentru matricea 1
					matrice_1[i]=new float[nr_coloane_matrice_1];
				cout<<endl<<"Introduceti elementele matricii 1: "<<endl;
				for(int i=0;i<nr_lini_matrice_1;i++)
					for(int j=0;j<nr_coloane_matrice_1;j++)
					{
						cout<<"matrice.1["<<i+1<<","<<j+1<<"]= ";			//introducem elemente in matricea 1	
						cin>>matrice_1[i][j];
					}
				cout<<endl<<endl<<"Dati nr. de lini a matricii 2: ";
				cin>>nr_lini_matrice_2;
				cout<<"Dati nr. de coloane a matricii 2: ";
				cin>>nr_coloane_matrice_2;
				matrice_2=new float*[nr_lini_matrice_2];					//alocam memorie pentru maticea 2
				for(int i=0;i<nr_lini_matrice_2;i++)
					matrice_2[i]=new float[nr_coloane_matrice_2];
				cout<<endl<<"Introduceti elementele matricii 2: "<<endl;
				for(int i=0;i<nr_lini_matrice_2;i++)
					for(int j=0;j<nr_coloane_matrice_2;j++)
					{
						cout<<"matrice.2["<<i+1<<","<<j+1<<"]= ";			//introducem elemente in matricea 2
						cin>>matrice_2[i][j];
					}
				cout<<endl<<endl<<"Ati introdus matricile: "<<endl<<endl;	//afisam matricile introduse			
				cout<<endl<<"Matricea 1: "<<endl<<endl;
				for(int i=0;i<nr_lini_matrice_1;i++)
				{
					cout<<setiosflags(ios::fixed | ios::left);
					for(int j=0;j<nr_coloane_matrice_1;j++)
						cout<<setprecision(2)<<setw(7)<<matrice_1[i][j];
					cout<<endl;
				}
				cout<<endl<<endl<<"Matricea 2: "<<endl<<endl;
				for(int i=0;i<nr_lini_matrice_2;i++)
				{
					cout<<setiosflags(ios::fixed | ios::left);
					for(int j=0;j<nr_coloane_matrice_2;j++)
						cout<<setprecision(2)<<setw(7)<<matrice_2[i][j];
					cout<<endl;
				}
				if(nr_coloane_matrice_1!=nr_lini_matrice_2)					//verificam daca se poate face produsul intre matrici
					cout<<"Nu se poate efectua produsul celor doua matrici deoarece nr. coloanelor primei matrici este diferit de nr. liniilor celei de-a doua matrici!"<<endl;
				else
				{
					cout<<endl<<endl<<"Produsul celor doua matirici este: "<<endl<<endl;
					produs_matrice(nr_lini_matrice_1, nr_coloane_matrice_1, matrice_1, nr_lini_matrice_2, nr_coloane_matrice_2, matrice_2);
				}
				for(int i=0;i<nr_lini_matrice_1;i++)						//eliberam memoria alocata de cele 2 matrici
					delete [] matrice_1[i];
				delete [] matrice_1;
				for(int i=0;i<nr_lini_matrice_2;i++)
					delete [] matrice_2[i];
				delete [] matrice_2;
				cout<<endl<<endl<<endl<<endl<<endl<<"Apasati orice tasta...";
				break;
			case '7':
				int nr_lini_coloane_m, ordin;
				int **matrice_initiala,**matrice_rezultat;
				cout<<"Introduceti nr. de lini/coloane al matricii patratice: ";
				cin>>nr_lini_coloane_m;
				matrice_initiala=new int*[nr_lini_coloane_m];				//alocam memorie pt matircea initiala			
				for(int i=0;i<nr_lini_coloane_m;i++)
					matrice_initiala[i]=new int[nr_lini_coloane_m];
				cout<<endl<<"Introduceti elementele matricii patratice: "<<endl;
				for(int i=0;i<nr_lini_coloane_m;i++)
					for(int j=0;j<nr_lini_coloane_m;j++)
					{
						cout<<"matrice["<<i+1<<","<<j+1<<"]= ";				//introducem valori in matricea initiala
						cin>>matrice_initiala[i][j];
					}
				matrice_rezultat=new int*[nr_lini_coloane_m];				//alocam memorie pt o alta matrice in care retinem rezultatul matrici initiale la un anumit ordin
				for(int i=0;i<nr_lini_coloane_m;i++)
					matrice_rezultat[i]=new int[nr_lini_coloane_m];
				for(int i=0;i<nr_lini_coloane_m;i++)
					for(int j=0;j<nr_lini_coloane_m;j++)
						matrice_rezultat[i][j]=matrice_initiala[i][j];		//initializam la inceput matricea rezultat cu matricea initiala (matricea rezultat = matricea initiala la puterea 1)
				cout<<endl<<"Ati introdus matricea: "<<endl;
				for(int i=0;i<nr_lini_coloane_m;i++)						//afisam elementele matricii initiale
				{
					for(int j=0;j<nr_lini_coloane_m;j++)
						cout<<matrice_initiala[i][j]<<" ";
					cout<<endl;
				}
				cout<<endl<<"Introduceti puterea la care doriti sa ridicati matricea: ";
				cin>>ordin;
				cout<<endl<<"Matricea introdusa la puterea "<<ordin<<" este: "<<endl<<endl;
				while (ordin>=2)															//cat timp nu s-a ajuns la ordinul ce dorim sa ridicam matricea reapelam functia 
				{
					ordin--;
					ridicare_putere_matrice(nr_lini_coloane_m,matrice_initiala,matrice_rezultat);		//functia tamplate care ridica o matrice la urmatoarea putere
				}
				for(int i=0;i<nr_lini_coloane_m;i++)
				{
					for(int j=0;j<nr_lini_coloane_m;j++)
						cout<<matrice_rezultat[i][j]<<" ";
					cout<<endl;
				}
				for(int i=0;i<nr_lini_coloane_m;i++)						//eliberam memoria alocata pentru matricea initiala si matricea rezultat
				{
					delete [] matrice_initiala[i];
					delete [] matrice_rezultat[i];
				}
				delete [] matrice_initiala;
				delete [] matrice_rezultat;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case 27:
				cout<<"Apasati orice tasta pentru a parasi programul!";
				break;
			default:
				cout<<"Apasati 1,2,3,4,5,6,7 sau Esc!";
		}
		getch();
	}
	while(optiune!=27);


	return 0;
}

