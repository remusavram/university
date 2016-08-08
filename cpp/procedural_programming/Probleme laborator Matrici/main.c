#include "malloc.h"
#include "math.h"
#include "stdio.h"
#include "conio.h"



void spati()

{
	printf("\n\n\n\n\n\n");
	
}



void diagonala_principala()
	
{

	//Suma elementelor de pe diagonala principala.


	int s=0,i,j,n,a[100][100];

	spati();
	printf("Dati nr. de lini/coloane a matrici: ");
	scanf("%d",&n);
	printf("\n");

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			printf("a[%d,%d]= ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}

	for (i=0;i<n;i++)
		s=s+a[i][i];
		
	printf("\nMatricea introdusa este:\n\n");
			
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%4d ",a[i][j]);
		printf("\n");
	}

	printf("\n");
	printf("Suma elementelor de pe diagonala principala este: %d\n",s);
	printf("\n\n");
	
	spati();
	printf("Apasati orice tasta... ");
	getch();

}



void sub_diagonala_principala()

{
	
	//Suma elementelor de sub diagonalei principale.


	int s=0,i,j,n,a[100][100];

	spati();
	printf("Dati nr. de lini/coloane a matrici: ");
	scanf("%d",&n);
	printf("\n");

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			printf("a[%d,%d]= ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}

	for(i=0;i<n;i++)
		for (j=0;j<i;j++)
			s=a[i][j]+s;

	printf("\nMatricea introdusa este:\n\n");
			
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%4d ",a[i][j]);
		printf("\n");
	}

	printf("\n");
	printf("Suma elementelor de sub diagonalei principale este: %d\n",s);
	printf("\n\n");
	
	spati();
	printf("Apasati orice tasta... ");
	getch();
	
}



void deasupra_diagonalei_principale()

{
	
	//Suma elementelor de deasupra diagonalei principale.

	int s=0,i,j,n,a[100][100];

	spati();
	printf("Dati nr. de lini/coloane a matrici: ");
	scanf("%d",&n);
	printf("\n");

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			printf("a[%d,%d]= ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}

	for(i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			s=a[i][j]+s;

	printf("\nMatricea introdusa este:\n\n");
			
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%4d ",a[i][j]);
		printf("\n");
	}

	printf("\n");
	printf("Suma elementelor de deasupra diagonalei principale este: %d\n",s);
	printf("\n\n");
	
	spati();
	printf("Apasati orice tasta... ");
	getch();
	
}



void diagonala_secundara()

{
	
	//Suma elementelor de pe diagonala secundara.
	
	int s=0,i,j,n,a[100][100];

	spati();
	printf("Dati nr. de lini/coloane a matrici: ");
	scanf("%d",&n);
	printf("\n");

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			printf("a[%d,%d]= ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}

	for(i=0;i<n;i++)
		s=s+a[i][n-i-1];

	printf("\nMatricea introdusa este:\n\n");
			
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%4d ",a[i][j]);
		printf("\n");
	}

	printf("\n");
	printf("Suma elementelor de pe diagonala secundara este: %d\n",s);
	printf("\n\n");
	
	spati();
	printf("Apasati orice tasta... ");
	getch();
	
}



void sub_diagonala_secundara()

{
	
	//Suma elementelor de sub diagonala secundara.
	
	spati();
	int s=0,i,j,n,a[100][100];

	printf("Dati nr. de lini/coloane a matrici: ");
	scanf("%d",&n);
	printf("\n");

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			printf("a[%d,%d]= ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}

	for(i=0;i<n;i++)
		for(j=n-i;j<n;j++)
			s=s+a[i][j];

	printf("\nMatricea introdusa este:\n\n");
			
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%4d ",a[i][j]);
		printf("\n");
	}

	printf("\n");
	printf("Suma elementelor de sub diagonala secundara este: %d\n",s);
	printf("\n\n");
	
	spati();
	printf("Apasati orice tasta... ");
	getch();
	
}



void deasupra_diagonalei_secundare()

{
	
	//Suma elementelor de deasupra diagonalei secundare.
	
	spati();
	int s=0,i,j,n,a[100][100];

	printf("Dati nr. de lini/coloane a matrici: ");
	scanf("%d",&n);
	printf("\n");

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			printf("a[%d,%d]= ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}

	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			s=s+a[i][j];

	printf("\nMatricea introdusa este:\n\n");
			
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%4d ",a[i][j]);
		printf("\n");
	}

	printf("\n");
	printf("Suma elementelor de deasupra diagonalei secundare este: %d\n",s);
	printf("\n\n");
	
	spati();
	printf("Apasati orice tasta... ");
	getch();
	
}



int main(int argc, char* argv[])

{
	
	char tasta=NULL;
	int optiune=0;
	
	do
	{
		printf("Introduceti o matrice si calculati: \n\n");
		printf("1.Suma elementelor de pe diagonala principala.\n");
		printf("2.Suma elementelor de sub diagonalei principale.\n");
		printf("3.Suma elementelor de deasupra diagonalei principale.\n");
		printf("4.Suma elementelor de pe diagonala secundara.\n");
		printf("5.Suma elementelor de sub diagonala secundara.\n");
		printf("6.Suma elementelor de deasupra diagonalei secundare.\n");
		
		optiune=getch();
		
		switch(optiune)
		{
			case '1':
				diagonala_principala();
				break;
			case '2':
				sub_diagonala_principala();
				break;
			case '3':
				deasupra_diagonalei_principale();
				break;
			case '4':
				diagonala_secundara();
				break;
			case '5':
				sub_diagonala_secundara();
				break;
			case '6':
				deasupra_diagonalei_secundare();
				break;
			default:
				spati();
          		printf("OPTIUNEA ESTE INVALIDA!\n");
          		break;
  		}
	
   spati();	
   printf("Doriti sa reveniti la meniu initial?(d/n)\n") ;   
   spati();
   spati();   
   tasta=getch();  	
  }
  while(tasta=='d' || tasta=='D');
	
	return 0;
	
}