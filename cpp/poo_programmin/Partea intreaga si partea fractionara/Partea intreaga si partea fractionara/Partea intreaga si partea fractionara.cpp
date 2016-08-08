#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;
                                                                                
int main()                                                                  
{                                                                               
   double nr, fr, intreg;                                                              
                                                                                
   nr = 3.14;                                                                 
   fr = modf(nr, &intreg);                                                             
  
   cout<<"x = "<<nr;
   cout<<endl;
   cout<<"Partea intreaga = "<<intreg;
   cout<<endl;
   cout<<"Partea fractionara = "<<fr;
   cout<<endl; 
   getch();

} 