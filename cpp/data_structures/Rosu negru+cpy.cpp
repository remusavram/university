#include <iostream>
#include<string>

using namespace std;


 struct arb{
     int info;
     char culoare;
     arb *st,*dr,*tata;
};



arb* LeftRotate(arb*rad, arb* x) {
  arb* y;
  arb* nil=NULL;
  y=x->dr;
  x->dr=y->st;
  if (y->st != nil)
  y->st->tata=x;
  y->tata=x->tata;
  if( x == x->tata->st)
    x->tata->st=y;
  else
    x->tata->dr=y;
  y->st=x;
  x->dr=y;
}




arb* RightRotate(arb* rad, arb* y) {
  arb* x;
  arb* nil=rad->nil;
  x=y->st;
  y->st=x->dr;
  if (nil != x->dr)
  x->dr->tata=y;
  x->tata=y->tata;
  if( y == y->tata->st)
    y->tata->st=x;
  else
    y->tata->dr=x;
  x->dr=y;
  y->tata=x;

}


 arb *Refacere(arb *T,arb*z){
    arb *y;
    while(z->tata->culoare=='R'){
        if(z->tata==z->tata->tata->st){
            y=z->tata->tata->st;
            if(y->culoare=='R'){
                z->tata->culoare='N';
                y->culoare='N';
                z->tata->tata->culoare='R';
			}
            else{
                if(z=z->tata->dr){
                    z=z->tata;
                    LeftRotate(T,z);
                }
                strcpy(z->tata->culoare,'N');
                strcpy(z->tata->tata->culoare,'R');
                RightRotate(T,z);
            }
            }
          else{
            if(z->tata==z->tata->tata->dr){
            y=z->tata->tata->dr;
            if(y->culoare=='R'){
                strcpy(z->tata->culoare,'N');
                y->culoare='N';
                strcpy(z->tata->tata->culoare,'R');
			}
            else{
                if(z=z->tata->st){
                    z=z->tata;
                    RightRotate(T,z);
                }
                strcpy(z->tata->culoare,'N');
                strcpy(z->tata->tata->culoare,'R');
                LeftRotate(T,z);
                        }
            
          }
        }

    }
    strcpy(T->rad->culoare,'N');
 }


arb *inserare(arb*T,arb*x){
    arb *y,*rad;
    arb *nil;
    y=T->nil;
    x=T->rad;
    while(x!=T->nil){
        y=x;
        if(z->info<x->info)
            x=x->st;
        else
            x=x->dr;
    }
    z->tata=y;
    if(y=T->nil){
        T->rad=z;
    else
        if(z->info<y->info)
            y->st=z;
        else
            y->dr=z;
    }
    z=>st=T->nil;
    z->dr=T->nil;
    z->culoare='R';
    Refacere(T,z);
}


arb* Successor(arb* T,arb* x) {
  arb* y;
  arb* nil=T->nil;
  arb* rad=T->rad;
  if (nil != (y = x->dr))
    while(y->st != nil)
      y=y->st;
    return y;
  else {
    y=x->tata;
    while(x == y->dr) {
      x=y;
      y=y->tata;
    }
    if (y == rad)
        return nil;
    return y;
  }
}


arb* Predecessor(arb*T, arb* x) {
  arb* y;
  arb* nil=T->nil;
  arb* rad=T->rad;

  if (nil != (y = x->st)) {
    while(y->dr != nil)
      y=y->right;
    return y;
  else {
    y=x->tata;
    while(x == y->st) {
      if (y == rad)
        return nil;
      x=y;
      y=y->tata;
    }
    return y;
  }
}

arb *repara(arb *T,arb *x){
    arb*rad,*u;
    while(x!=T->rad && x->culoare=='N')
        if(x==x->tata->st){
            u=x->tata->dr;
            if(u->culoare=='R'){
                strcpy(u->culoare,'N');
                x->tata->culoare='R';
                LeftRotate(T,x->tata);
                u=x->tata->dr;
            }
            if(u->st->culoare=='N' && u->dr->culoare=='N'){
                u->culoare='R';
                x=x->tata;
            }
            else{
                if(u->dr->culoare=='N'){
                  u->st->culoare=='N';
                  u->culoare='R';
                  RightRotate(T,u);
                  u=x->tata->dr;
                }
                u->culoare=x->tata->culoare;
                x->tata->culoare='N';
                u->dr->culoare='N';
                LeftRotate(T,x->tata);
                x=T->rad;
            }
           }
           else{
               if(x==x->tata->dr){
            u=x->tata->st;
            if(u->culoare='R'){
                u->culoare='N';
                x->tata->culoare='R';
                RightRotate(T,x->tata);
                u=x->tata->st;
            }
            if(u->dr->culoare=='N' && u->st->culoare=='N'){
                u->culoare='R';
                x=x->tata;
            }
            else{
                if(u->st->culoare=='N'){
                  u->dr->culoare=='N';
                  u->culoare='R';
                  LeftRotate(T,u);
                  u=x->tata->st;
                }
                u->culoare=x->tata->culoare;
                x->tata->culoare='N';
                u->st->culoare='N';
                RighrRotate(T,x->tata);
                x=T->rad;
            }
           }
           }

    x->culoare='N';

}



arb *stergere(arb *T,arb*z){
    arb *nil,*y;
    if(z->st==nil || z->dr==nil)
        z=y;
    else
        y=Succesor(T,z);
    if(y->st!=nil)
        x=y->st;
    else
        x=y->dr;
    if(x!=nil)
        x->tata=y->tata;
    if(y->tata=nil)
        T->rad=x;
    else
        if(y==y->tata->st)
            x=y->tata->st;
        else
            x=y->tata->dr;
    if(z->info<y->info)
        z->info=y->info;
    if(y->culoare=='N')
            Repara(T,x);
}


void afisare(arb* T, arb* x) {
  arb* nil=T->nil;
  arb* rad=T->rad;
  if (x != T->nil) {
    afisare(T,x->st);
    cout<<"info=";
    cout<<T->x->info;
    cout<<"l->key=";
    if( x->st == nil)
        cout<<"NULL";
    else
        cout<<T->x->st->info;
    cout<<"r->key=";
    if( x->dr == nil)
        cout<<"NULL";
    else
        cout<<T->x->dr->info;
    cout<<"p->key=";
    if( x->tata == rad)
        cout<<"NULL";
    else
        cout<T->x->tata->info);
    cout<<"red";
    afisare(T,x->dr);
  }
}



int main()
{
    arb *rad,*T,*y,*x,*z,*nil;
    int n,m,s,p,ss;
    cout<<"introduceti numarul de elemente: ";
    cin>>n;
    cout<<endl;
    cout<<"introduceti elementele: ";
    for(int i=0;i<n;i++){
        cin>>m;
        inserare(T,m);
    }
    cout<<"arborele RN este: ";
    afisare(t,x);
    cout<<"Predecesorul nodului"<<p<<"este: ";
    cin>>p;
    Predecesor(T,p);

    cout<<"Succesorul nodului"<<s<<"este: ";
    cin>>s;
    Predecesor(T,s);

    cout<<"Nodul pe care doriti sa-l stergeti este: ";
    cin>>ss;
    stergere(t,ss);
    cout<<"arborele RN dupa stergere este: ":
    afisare(t,x);


    return 0;
}
