// Lab03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <math.h>

void clrscr()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void fibonacci_TermenulN()
{
	//Termenul n din sirul lui Fibonacci
	int n = 0, pos = 0, fib1 = 0, fib2 = 0, tmp = 0;

	clrscr();
	printf("Programul afiseaza termenul n al sirului Fibonacci (n > 2).\n\n");
	printf("n: ");
	scanf("%d", &n);

	if(n > 2)
	{
		fib1 = 1;
		fib2 = 1;
		pos = 2;
		
		while(pos < n)
		{
			tmp = fib1;
			fib1 = fib2;
			fib2 = fib1 + tmp;
			pos = pos + 1;
		}

		printf("Al %d-lea numar din sirul Fibonacci e: %d.\n", n, fib2);
	}
	else
	{
		printf("Numarul selectat nu e mai mare decat 2.\n");
	}

	printf("Apasa orice tasta...");
	getch();
	clrscr();
}

void fibonacci_NApartine()
{
	//Daca n apartine sau nu sirului Fibonacci
	int n = 0, fib1 = 0, fib2 = 0, tmp = 0;

	clrscr();
	printf("Programul determina daca n apartine sirului lui Fibonacci (n > 2).\n\n");
	printf("n: ");
	scanf("%d", &n);

	if(n > 2)
	{
		fib1 = 1;
		fib2 = 1;
		
		while(fib2 < n)
		{
			tmp = fib1;
			fib1 = fib2;
			fib2 = fib1 + tmp;
		}

		if(fib2 == n)
		{
			printf("%d apartine sirului Fibonacci.\n", n);
		}
		else
		{
			printf("%d este un numar oarecare.\n", n);
		}
	}
	else
	{
		printf("Numarul selectat nu e mai mare decat 2.\n");
	}

	printf("Apasa orice tasta...");
	getch();
	clrscr();
}

void fibonacci_panaLaN()
{
	//Toate valorile sirului Fibonacci pana la n
	int n = 0, fib1 = 0, fib2 = 0, tmp = 0;

	clrscr();
	printf("Programul afiseaza toate valorile sirului lui Fibonacci pana la n.(n > 2).\n\n");
	printf("n: ");
	scanf("%d", &n);

	if(n > 2)
	{
		fib1 = 1;
		fib2 = 1;
		printf("1 ");
		
		do
		{
			printf("%d ", fib2);

			tmp = fib1;
			fib1 = fib2;
			fib2 = fib1 + tmp;
		}
		while(fib2 <= n);
		printf("\n");
	}
	else
	{
		printf("Numarul selectat nu e mai mare decat 2.\n");
	}

	printf("Apasa orice tasta...");
	getch();
	clrscr();
}

void numerePrimePanaLaN()
{
	//Toate numerele prime <= cu n
	int n, numarTestat;
	bool ePrim = false;

	clrscr();
	printf("Programul afiseaza toate numerele prime <= n.(n > 2).\n\n");
	printf("n: ");
	scanf("%d", &n);

	if(n > 2)
	{
		printf("2 ");

		for(numarTestat = 3; numarTestat <= n; numarTestat+=2)
		{
			ePrim = true;
			for(int i = 3; i <= sqrt((float)numarTestat); i+=2)
			{
				if(numarTestat % i == 0)
				{
					ePrim = false;
					break;
				}
			}

			if(ePrim)
			{
				printf("%d ", numarTestat);
			}
		}

		printf("\n");
	}
	else
	{
		printf("Numarul selectat nu e mai mare decat 2.\n");
	}

	printf("Apasa orice tasta...");
	getch();
	clrscr();
}

void numarCaSumaF()
{
	//f(x)=x cand x<=5; f(x)=f(x-1)*2 cand x>5; afisare n in suma de f(x)
	int n = 0, copieN = 0, numarGasit = 0, ultimulF = 0;
	bool ePrimaData = true;

	clrscr();
	printf("Programul afiseaza un numar n ca suma de f(x) numere...(n > 0)\n\n");
	printf("n: ");
	scanf("%d", &n);

	copieN = n;

	if(n > 0)
	{
		printf("%d = ", n);
		while(copieN > 0)
		{
			ultimulF = 1;
			while(ultimulF <= copieN)
			{
				if(ultimulF < 5)
				{
					ultimulF = ultimulF + 1;
				}
				else
				{
					ultimulF = ultimulF * 2;
				}
				if(ultimulF <= copieN) numarGasit = ultimulF;
			}
			copieN = copieN - numarGasit;
			if(!ePrimaData) printf(" + ");
			printf("%d", numarGasit);
			ePrimaData = false;
		}

		printf("\n");
	}
	else
	{
		printf("Numarul selectat nu e mai mare decat 0.\n");
	}

	printf("Apasa orice tasta...");
	getch();
	clrscr();
}

void fibonacci_numarCaSuma()
{
	//Descompunere n in suma de Fibonacci
	int n = 0, fib1 = 0, fib2 = 0, tmp = 0;
	bool ePrimaData = true;

	clrscr();
	printf("Programul afiseaza n ca suma de numere Fibonacci.(n > 2).\n\n");
	printf("n: ");
	scanf("%d", &n);

	if(n > 2)
	{
		fib1 = 1;
		fib2 = 1;

		printf("%d = ", n);

		while(n > 0)
		{
			fib1 = 1;
			fib2 = 1;
			do
			{
				tmp = fib1;
				fib1 = fib2;
				fib2 = fib1 + tmp;
			}
			while(fib2 <= n);
			if(!ePrimaData) printf(" + ");
			printf("%d", fib1);
			ePrimaData = false;
			n = n - fib1;
		}

		printf("\n");
	}
	else
	{
		printf("Numarul selectat nu e mai mare decat 2.\n");
	}

	printf("Apasa orice tasta...");
	getch();
	clrscr();
}

void termenulNDinSir()
{
	//1223334444... sa se afiseze termenul
	int n = 0;

	clrscr();
	printf("Programul afiseaza al n-lea termen din sirul 122333.....(n > 0).\n\n");
	printf("n: ");
	scanf("%d", &n);

	if(n > 0)
	{
		//n = x(x+1)/2 x(x+1) = 2n x^2+x - 2n = 0; x1 = -1+sqrt(1 + 4n);
		printf("%d\n", (int)ceil((float)(-1 + sqrt((float)(1 + 8*n)))/(float)2));
	}
	else
	{
		printf("Numarul selectat nu e mai mare decat 0.\n");
	}

	printf("Apasa orice tasta...");
	getch();
	clrscr();
}

int _tmain(int argc, _TCHAR* argv[])
{
	int optiune = 0;
	char tasta = 0;

	do
	{
		clrscr();

		printf("\t\t\tMENIU - introduceti numarul optiunii\n\n");
		printf("\t1. Termenul n din sirul lui Fibonacci\n");
		printf("\t2. Daca n apartine sau nu sirului Fibonacci\n");
		printf("\t3. Toate valorile sirului Fibonacci pana la n\n");
		printf("\t4. Toate numerele prime <= cu n\n");
		printf("\t5. f(x)=x cand x<=5; f(x)=f(x-1)*2 cand x>5; afisare n in suma de f(x)\n");
		printf("\t6. Descompunere n in suma de Fibonacci\n");
		printf("\t7. 1223334444... sa se afiseze termenul n\n");

		optiune = getch();

		switch(optiune)
		{
			case '1':
				fibonacci_TermenulN();
				break;
			case '2':
				fibonacci_NApartine();
				break;
			case '3':
				fibonacci_panaLaN();
				break;
			case '4':
				numerePrimePanaLaN();
				break;
			case '5':
				numarCaSumaF();
				break;
			case '6':
				fibonacci_numarCaSuma();
				break;
			case '7':
				termenulNDinSir();
				break;
			default:
				printf("Optiunea nu este valida.\n");
				break;
		}

		clrscr();
		printf("Doriti sa reveniti la ecranul initial?(d/n)\n");
		tasta = getch();
	}
	while(tasta == 'd' || tasta == 'D');

	return 0;
}

