#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    
    cout<<"Se considera un vector de numere cu n elemente. Sa se determine ce nr. apare cel mai des si de cate ori."<<endl<<endl;
    
    int n,i,j,v[100],t[100],k,c;
    
    cout<<"n= ";
    cin>>n;
    
    cout<<endl<<"Introduceti elementele sirului: "<<endl<<endl;
    
    for(i=0;i<n;i++)
                    {
                    cout<<"v["<<i+1<<"]= ";
                    cin>>v[i];
                    }
                  
    for(i=0;i<n;i++)
                    t[i]=0;
    
    for(i=0;i<n;i++)
                    if(t[i]==0)
                               {
                               t[i]=t[i]+1;          
                               for(j=i+1;j<n;j++)
                                               if(v[i]==v[j])
                                                             {
                                                             t[i]=t[i]+1;
                                                             t[j]=1;
                                                             }  
                               }                                                     

    k=0;                                                         
    c=t[0];
    for(i=1;i<n;i++)
                    if(t[i]>c)
                              {
                              k=i;
                              c=t[i];
                              }
    
    cout<<endl<<v[k]<<" apare de "<<c<<" ori!"<<endl<<endl;
                    
            
    system("PAUSE");
    return EXIT_SUCCESS;
}
