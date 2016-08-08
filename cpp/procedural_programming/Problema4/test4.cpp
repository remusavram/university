// test4.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "malloc.h"
#include "math.h"


int verificare(int **a,int n)
{
	int *s1,*s2,i,j;

	s1=(int*)calloc(n,sizeof(int));
	s2=(int*)calloc(n,sizeof(int));

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			s1[i]=s1[i]+a[i][j];
			s2[i]=s2[i]+a[j][i];
		}

	for(i=0;i<n;i++)
	{
		s1[i]=s1[i]-a[i][i];
		s2[i]=s2[i]-a[i][i];
	}

	for(i=0;i<n;i++)
		if ((s1[i]>a[i][i])||(s2[i]>a[i][i]))
			return 0;

	return 1;

}


int modifica(int **a,int n)
{
	
	int *s1,*s2,i,j,t;

	s1=(int*)calloc(n,sizeof(int));
	s2=(int*)calloc(n,sizeof(int));

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j)
			{
				s1[i]=s1[i]+a[i][j];
				s2[i]=s2[i]+a[j][i];
			}


	for(i=0;i<n;i++)
	{
		if(s1[i]>s2[i])
			t=s1[i];
		else
			t=s2[i];
		
		if(a[i][i]<t)
			a[i][i]=t;
	}

return 0;

}



int main(int argc, char* argv[])
{

	int **a,i,j,n;

	FILE *f=fopen("fis.in","rt");

	fscanf(f,"%d",&n);

	a=(int**)calloc(n,sizeof(int*));

	for (i=0;i<n;i++)
		a[i]=(int*)calloc(n,sizeof(int));

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			fscanf(f,"%d",&a[i][j]);
	
	fclose(f);

	if (verificare(a,n)==0)
		modifica(a,n);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}



	FILE *g=fopen("fis.out","wt");
	
	for(i=0;i<n;i++)
	{
		fprintf(g,"\n");
		for(j=0;j<n;j++)
			fprintf(g,"%d ",a[i][j]);
	}


	return 0;
}

