#include <stdio.h>

void main()
{

	int n1=10,n2;
	float x=5.71,f;
	char s[10];
	printf("Un nr. intreg: %d si un nr. real: %f\n",n1,x);
	scanf("%d%f%s",&n2,&f,&s);
	printf("Am citit: %d ,%5.2f ,%s ",n2,f,s);
}