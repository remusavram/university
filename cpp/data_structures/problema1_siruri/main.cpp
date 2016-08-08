#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    
    cout<<"Se considera un vector de numere cu n elemente. Sa se determine cate elemente sunt egale cu valoarea minima din sir cu o singura parcurgere a sirului."<<endl<<endl;
    
    int n,v[100],k,i,min;
    
    cout<<"n= ";
    cin>>n;
    cout<<endl<<"Dati elementele vectorului:"<<endl<<endl;
    for(i=0;i<n;i++)
                    {
                    cout<<"v["<<i+1<<"]= ";
                    cin>>v[i];             
                    } 
       
    min=v[0];
    k=1;
    
    for(i=1;i<n;i++)
                   { 
                    if(min>v[i])
                                {
                                min=v[i];
                                k=1;
                                }
                    else if(min==v[i])
                         k=k+1;
                   } 
    if(k==1)
            cout<<endl<<"Un singur element este egal cu valoarea minima"<<endl; 
    else  
            cout<<endl<<k<<" elemente sunt egale cu valoarea minima"<<endl;         
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
