#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{
	float media_aritmetica_nr_intregi,media_aritmetica_nr_reale,i;
	i=8;
	media_aritmetica_nr_intregi=(sizeof(char)+sizeof(unsigned char)+sizeof(short unsigned)+sizeof(short)+sizeof(int)+sizeof(unsigned int)+sizeof(long)+sizeof(unsigned long))/i;
	printf("Media aritmetica a numerelor intregi este: %5.2f\n",media_aritmetica_nr_intregi);
	
	i=3;
	media_aritmetica_nr_reale=(sizeof(float)+sizeof(double)+sizeof(long double))/i;
	printf("Media aritmetica a numerelor reale este: %5.2f\n",media_aritmetica_nr_reale);
	
	return 0;

}
