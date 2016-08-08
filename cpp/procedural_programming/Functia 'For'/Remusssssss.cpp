#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>

int main(int argc, char* argv[])
{
	int a[20],n,s,p,s2,min,max,i2,i3,q;
	float media_aritmetica;

	printf("nr: ");
	scanf("%d",&n);

	for (int i=0;i<n;i++)
	{
	printf("a[%d]=",i);
	scanf("%d",&a[i]);
	}


	printf("Numerele introduse sunt: ");

	for (int j=0;j<n;j++)
	printf("%d ",a[j]);


	s=0;
	printf("\n");

	for(int k=0;k<n;k++)

		if(a[k]%2==0)
			s=s+a[k];
    printf("Suma numerelor pare este: ");
    printf("%d\n",s);

    for (int l=1;l<n;l++)
        if (max<a[l])
            max=a[l];
    printf("Maximul numerelor este: ");
    printf("%d\n",max);

    p=1;
    for(int q=0;q<n;q++)
        if (a[q]%2==1)
            p=p*a[q];
    printf("Produsul numerelor impare este: ");
    printf("%d\n",p);

    min=a[0];
    for(int w=1;w<n;w++)
        if (min>a[w])
            min=a[w];
    printf("Minimul numerelor este: ");
    printf("%d\n", min);

    s2=0;
    for(int e=0;e<n;e++)
        if (e%2==1 && a[e]%2==0)
            s2=a[e]+s2;
    printf("Suma elementelor pare de pe poziti impare este: ");
    printf("%d\n", s2);


    printf("Pozitiile minime din sir sunt: ");
    for (int r=0;r<n;r++)
        if (a[r]==min)
            printf("%d ",r);

    media_aritmetica=0;
    i2=0;

    for (int t=0;t<n;t++)
    {
        media_aritmetica=media_aritmetica+a[t];
        i2=i2+1;
    }
    media_aritmetica=media_aritmetica/i2;
    printf("\n");
    i3=0;
    printf("Media aritmetica este: ");
    printf("%f\n",media_aritmetica);


    for (int y=0;y<n;y++)
        if (a[y]>media_aritmetica)
            i3=i3+1;
    printf("Numarul elementelor care sunt mai mari ca media aritmetica sunt: ");
    printf("%d\n",i3);


    printf("Elementele din sir inversate sunt: ");


/*for(int u=n-1;u>=0;u--)
  printf("%d ",a[u]);
*/

    int aux;
    for (int o=0;o<n/2;o++)
    {
        aux=a[o];
        a[o]=a[n-o-1];
        a[n-o-1]=aux;
    }
    for (int v=0;v<n;v++)
        printf("%d ",a[v]);
    printf("\n");
    q=getch();
    return 0;

}

