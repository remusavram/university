#include <iostream>
#include<string>

using namespace std;


 struct arb{
     int info;
     int culoare;
     /*2-rosu
     3-negru;*/
     arb *st,*dr,*tata;
};



void LeftRotate(arb*rad, arb* x) {
  arb* y;
    y=x->dr;
  x->dr=y->st;
  if (y->st != NULL)
  y->st->tata=x;
  y->tata=x->tata;
  if( x == x->tata->st)
    x->tata->st=y;
  else
    x->tata->dr=y;
  y->st=x;
  x->dr=y;
}




void  RightRotate(arb* rad, arb* y) {
  arb* x;
    x=y->st;
  y->st=x->dr;
  if (NULL != x->dr)
  x->dr->tata=y;
  x->tata=y->tata;
  if( y == y->tata->st)
    y->tata->st=x;
  else
    y->tata->dr=x;
  x->dr=y;
  y->tata=x;

}


void Refacere(arb *T,arb*z){
    arb *y,*rad;
    while(z->tata->culoare==2){
        if(z->tata==z->tata->tata->st){
            y=z->tata->tata->st;
            if(y->culoare==2){
                z->tata->culoare=3;
                y->culoare=3;
                z->tata->tata->culoare=2;
			}
            else{
                if(z=z->tata->dr){
                    z=z->tata;
                    LeftRotate(T,z);
                }
                z->tata->culoare=3;
                z->tata->tata->culoare=2;
                RightRotate(T,z);
            }
            }
          else{
            if(z->tata==z->tata->tata->dr){
            y=z->tata->tata->dr;
            if(y->culoare==2){
                z->tata->culoare,3;
                y->culoare=3;
                z->tata->tata->culoare=2;
			}
            else{
                if(z=z->tata->st){
                    z=z->tata;
                    RightRotate(T,z);
                }
                z->tata->culoare=3;
                z->tata->tata->culoare=2;
                LeftRotate(T,z);
                        }

          }
        }

    }
    T->culoare=3;
    rad=T;
 }


void inserare(arb*T,arb * x){
    arb *y,*rad,*z;
    y=T=NULL;
    x=T=rad;
    while(x!=NULL){
        y=x;
        if(z->info<x->info)
            x=x->st;
        else
            x=x->dr;
    }
    z->tata=y;
    if(y=NULL)
        T=z;
    else
        if(z->info<y->info)
            y->st=z;
        else
            y->dr=z;

    z->st=NULL;
    z->dr=NULL;
    z->culoare=2;
    Refacere(T,z);
}


arb * Succesor(arb* T,arb* x) {
  arb* y,*rad;
  T=NULL;
  T=rad;
  if (NULL != (y = x->dr)){
	  while(y->st != NULL)
      y=y->st;
    return y;
  }
  else {
    y=x->tata;
    while(x == y->dr) {
      x=y;
      y=y->tata;
    }
    if (y == rad)
        return NULL;
    return y;
  }
}


arb * Predecesor(arb*T, arb* x) {
  arb* y,*rad;
  T=NULL;
  T=rad;

  if (NULL != (y = x->st)) {
    while(y->dr != NULL)
      y=y->dr;
    return y;
  }
  else {
    y=x->tata;
    while(x == y->st) {
      if (y == rad)
        return NULL;
      x=y;
      y=y->tata;
    }
    return y;
  }

}
void repara(arb *T,arb *x){
    arb*rad,*u;
    while(x!=T && x->culoare==3)
        if(x==x->tata->st){
            u=x->tata->dr;
            if(u->culoare==2){
                u->culoare=3;
                x->tata->culoare=2;
                LeftRotate(T,x->tata);
                u=x->tata->dr;
            }
            if(u->st->culoare==3 && u->dr->culoare==3){
                u->culoare=2;
                x=x->tata;
            }
            else{
                if(u->dr->culoare==3){
                  u->st->culoare==3;
                  u->culoare=2;
                  RightRotate(T,u);
                  u=x->tata->dr;
                }
                u->culoare=x->tata->culoare;
                x->tata->culoare=3;
                u->dr->culoare=2;
                LeftRotate(T,x->tata);
                x=T;
            }
           }
           else{
               if(x==x->tata->dr){
            u=x->tata->st;
            if(u->culoare=2){
                u->culoare=3;
                x->tata->culoare=2;
                RightRotate(T,x->tata);
                u=x->tata->st;
            }
            if(u->dr->culoare==3 && u->st->culoare==3){
                u->culoare=2;
                x=x->tata;
            }
            else{
                if(u->st->culoare==3){
                  u->dr->culoare==3;
                  u->culoare=2;
                  LeftRotate(T,u);
                  u=x->tata->st;
                }
                u->culoare=x->tata->culoare;
                x->tata->culoare=3;
                u->st->culoare=3;
                RightRotate(T,x->tata);
                x=T;
            }
           }
           }

    x->culoare=3;

}



void stergere(arb *T,arb*z){
    arb *y,*x;
    if(z->st==NULL || z->dr==NULL)
        z=y;
    else
        y=Succesor(T,z);
    if(y->st!=NULL)
        x=y->st;
    else
        x=y->dr;
    if(x!=NULL)
        x->tata=y->tata;
    if(y->tata=NULL)
        T=x;
    else
        if(y==y->tata->st)
            x=y->tata->st;
        else
            x=y->tata->dr;
    if(z->info<y->info)
        z->info=y->info;
    if(y->culoare==3)
            repara(T,x);
}


void afisare(arb* T, arb* x) {
  T=NULL;
  if (x !=NULL) {
    afisare(T,x->st);
    cout<<"info=";
    cout<<T->info;
    cout<<"l->key=";
    if( x->st == NULL)
        cout<<"NULL";
    else
        cout<<T->st->info;
    cout<<"r->key=";
    if( x->dr == NULL)
        cout<<"NULL";
    else
        cout<<T->dr->info;
    cout<<"p->key=";
    if( x->tata == T)
        cout<<"NULL";
    else
        cout<<T->tata->info;
    cout<<"red";
    afisare(T,x->dr);
  }
}



int main()
{
    arb *rad,*T,*y,*x,*z,*nil;
    int n,m;
    int s,p,ss;
    cout<<"introduceti numarul de elemente: ";
    cin>>n;
    cout<<endl;
    cout<<"introduceti elementele: ";
    for(int i=0;i<n;i++){
        cin>>m;
        inserare(T,m);
    }
    cout<<"arborele RN este: ";
    afisare(T,x);
    cout<<"Predecesorul nodului"<<p<<"este: ";
    cin>>p;
    Predecesor(T,p);

    cout<<"Succesorul nodului"<<s<<"este: ";
    cin>>s;
    Succesor(T,s);

    cout<<"Nodul pe care doriti sa-l stergeti este: ";
    cin>>ss;
    stergere(T,ss);
    cout<<"arborele RN dupa stergere este: ";
    afisare(T,x);


    return 0;
}
