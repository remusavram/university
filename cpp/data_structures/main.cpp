
#include<iostream.h>

using namespace std;



struct arb{
    char *value;
    int nr;
    int ordin;
    int maxChei;
    int h;
    int nrKeys;
    arb *NIL;
    arb **keys;
    arb **fii;
    arb *rad;

};




int insertKey1(arb *&newKey){

    int i, poz, cmp = 1;
    char *newVal = newKey->value;
    for(poz=0; poz<nrKeys && (cmp = strcmp(keys[poz]->value, newVal)) < 0; poz++)
        if(poz == maxChei+1){
            cout<<"Eroare cheia: "<<newVal<<" nu a putut fi inserata !\n";
            return -1;
        }
    //  cheia exista deja
    if(cmp == 0){
        keys[poz]->nr += newKey->nr;
        delete newKey;  //  daca cheie noua exista sub alta forma
        newKey = NULL;  //  trebuie stearsa
        return poz;
    }
    //  trebuie mutate toate elementele cu o pozitie sa facem loc la cheia noua
    for(i=nrKeys; i>poz; i--){
        keys[i] = keys[i-1];
        fii[i+1] = fii[i];
    }
    keys[poz] = newKey;
    nrKeys++;
    return poz;

}


int insertKey2(arb *&newKey, arb*left, arb*right){
    int poz = insertKey1(newKey);
    fii[poz] = left;
    fii[poz+1] = right;
    return poz;
}

int insertKey3(char *value){
    arb*newKey = new arb[value];
    return insertKey1(newKey);
}

int insertKey4(char *value, arb*left, arb*right){
    BKey *newKey = new BKey(value);
    return insertKey2(newKey, left, right);
}

int eraseKey1(char *value, arb*&left, arb *&right){
    left = right = NULL;
    int i, poz, cmp = 1;
    for(poz=0; poz<nrKeys && (cmp = strcmp(keys[poz]->value, value)) < 0; poz++);
    if(poz == nrKeys)
        return -1;
    //  cheia a fost gasita
    if(cmp == 0){
        left = fii[poz];
        right = fii[poz+1];
        delete keys[poz];
        for(i=poz; i<nrKeys-1; i++){
            keys[i] = keys[i+1];
            fii[i] = fii[i+1];
        }
        fii[i] = fii[i+1];
        nrKeys--;
        return poz;
    }
    //  cheia nu a fost gasita
    return -1;
}

int eraseKey2(char *value){
    arb *left, *right;
    return eraseKey1(value, left, right);
}


int eraseKey3(int poz, arb *&left, arb*&right){
    if(poz < 0 || poz >= nrKeys){
        cout<<"Eroare stergere indexlul chei nu este corect: "<<poz<<" !!!\n";
        return -1;
    }
    left = fii[poz];
    right = fii[poz+1];
    delete keys[poz];
    int i;
    for(i=poz; i<nrKeys-1; i++){
        keys[i] = keys[i+1];
        fii[i] = fii[i+1];
    }
    fii[i] = fii[i+1];
    nrKeys--;
    return poz;
}
int eraseKey4(int poz){
    arb *left, *right;
    return eraseKey3(poz, left, right);
}

arb *removeKey1(int poz, arb*&left, arb*&right{
    if(poz < 0 || poz >= nrKeys){
        cout<<"Eroare stergere indexlul chei nu este corect: "<<poz<<" !!!\n";
        return NULL;
    }
    left = fii[poz];
    right = fii[poz+1];
    arb *rezult = keys[poz];
    int i;
    for(i=poz; i<nrKeys-1; i++){
        keys[i] = keys[i+1];
        fii[i] = fii[i+1];
    }
    fii[i] = fii[i+1];
    nrKeys--;
    return rezult;
}

arb * removeKey2(int poz){
    arb *left, *right;
    return removeKey1(poz, left, right);
}

bool  split(arb *&outLeft, arb*&outRight, arb *&outMid){
    outLeft = outRight = NULL;
    outMid = NULL;
    if(nrKeys != maxChei + 1){
        cout<<"Eroare pagina nu poate fi impartita, are: "<<nrKeys<<" chei !!!\n";
        return false;
    }
     int i;
    //  right
    outRight = new arb;
    for(i=0; i<ordin; i++){
        outRight->keys[i] = keys[ordin + 1 + i];
        outRight->fii[i] = fii[ordin + 1 + i];
    }
    outRight->fii[ordin] = fii[maxChei+1];
    outRight->nrKeys = ordin;
    outRight->h = h;
    //  left
    nrKeys = ordin;
    //  mid
    outMid = new arb;
    outMid->nrKeys = 1;
    outMid->h = h+1;
    outMid->keys[0] = keys[ordin];
    outMid->fii[0] = outLeft;
    outMid->fii[1] = outRight;
    return true;
}

bool merge(arb *&page){
    int totalKeys = nrKeys + page->nrKeys;
    if(totalKeys > maxChei + 1){
        cout<<"Eroare, paginile nu pot fi unite, au prea multe noduri: "<<totalKeys<<" in total\n";
        return false;
    }
    int poz;
    if(page->nrKeys == 1){
        poz = insertKey(page->keys[0]);
        fii[poz] = page->fii[0];
        fii[poz+1] = page->fii[1];
    }
    else
        if(nrKeys == 1)
            poz = page->insertKey(keys[0]);
        page->fii[poz] = fii[0];
        page->fii[poz+1] = fii[1];
        //  copiem tot continut
        int i;
        for(i=0; i<page->nrKeys; i++){
            keys[i] = page->keys[i];
            fii[i] = page->fii[i];
        }
        fii[i] = page->fii[i];
        nrKeys = page->nrKeys;
        h = page->h;
    }
    else{
        if(totalKeys > maxChei)
        {
            cout<<"Eroare la unire pagini, ambele pagini au mai mult de 1 cheie si nr total de chei este mai mare decat cel maxim !!!\n";
            return false;
        }
        int nrKeysPage = page->nrKeys;
        int i;
        if(strcmp(keys[nrKeys-1]->value, page->keys[nrKeysPage-1]->value) < 0){
            for(i=0; i<nrKeysPage; i++){
                keys[nrKeys+i] = page->keys[i];
                fii[nrKeys+i] = page->fii[i];
            }
            fii[nrKeys+i] = page->fii[i];
            nrKeys = totalKeys;
        }
        else{
            cout<<"Eroare la unire pagini, pagina a doua trebui sa aiba cheile mai mari decat prima !!!\n";
            return false;
        }
    }
    delete page;
    page = NULL;
    return true;
}

arb *minPage(arb *rad){
    if(rad == NULL)
        return NULL;
    if(rad->h == 0)
        return rad;
    return minPage(rad->fii[0]);
}

arb*maxPage(arb *rad){
    if(rad == NULL)
        return NULL;
    if(rad->h == 0)
        return rad;
    return maxPage(rad->fii[rad->nrKeys]);
}

bool findKey(arb *father, arb *rad, char *value, arb *& outFather, int &outPos){
    if(rad == NULL)
        return false;
    //  trebuie sa parcurgem fii
    int poz, cmp;
    for(poz=0; poz<rad->nrKeys && (cmp = strcmp(rad->keys[poz]->value, value)) < 0; poz++);
    //  cheia a fost gasita
    if(cmp == 0){
        outPos = poz;
        outFather = father;
        return true;
    }
    else{
        //  cheia nu a fost gasita
        if(poz == rad->nrKeys){        {
            //  e in dreapta
            if(findKey(rad, rad->fii[poz+1], value, outFather, outPos))
                return true;
        }
        else{
            //  e in stanga
            if(findKey(rad, rad->fii[poz], value, outFather, outPos))
                return true;
        }
    }
    return false;
}

void info(char *value){
    arb *father;
    arb* page = rad;
    int poz;
    if(!findKey(NULL, rad, value, father, poz))
        cout<<"cheia nu exista!\n";
    else{
        if(father == NULL)
            cout<<"este radacina";
        else{
            page = father->fii[poz];
            if(poz>0)
                cout<<"cheia "<<father->keys[poz-1]->value<<" este tata stang\n";
            if(poz<father->nrKeys)
                cout<<"cheia "<<father->keys[poz]->value<<" este tatal drept\n";
        }
        cout<<"inaltimea "<<page->h<<"\n";
    }
}

void info(){
    if(rad == NULL){
        cout<<"arbore gol\n";
        return;
    }
    cout<<"inaltimea "<<rad->h<<"\n";
    arb *min = minPage(rad);
    arb *max = maxPage(rad);
    cout<<"cheie minima "<<min->keys[0]->value<<"\n";
    cout<<"cheia maxima "<<max->keys[max->nrKeys-1]->value<<"\n";
}


void main()

    arb* rad;
    char opt;
        do{
        cout<<"V - face vid arborele\n";
        cout<<"C - cauta o cheie, afisand info\n";
        cout<<"A - adauga o cheie\n";
        cout<<"S - suprima o cheie\n";
        cout<<"L - afiseaza cheile arborelui in ordine crescatoare\n";
        cout<<"P - afiseaza arborele pe pagini\n";
        cout<<"D - afiseaza adancimea arborelui, cheia cea mai mica si cea mai mare\n";
        cout<<"X - terminare\n";
        cout<<"optiunea: ";
        cin>>opt;
        switch(opt){
        case 'v':
            erase();
            cout<<"arborele este gol\n";
            break;
        case 'c':
            cout<<"Cheia cautata: ";
            cin>>buf;
            nfo(buf);
            break;
        case 'a':
            cout<<"Cheie noua: ";
            cin>>buf;
            add(buf);
            break;
        case 's':
            cout<<"Cheia de sters: ";
            cin>>buf;
            erase(buf);
            break;
        case 'l':
            inord();
            break;

        case 'd':
            info();
            break;

        case 'x':
            break;
        }
    while(opt != 'x');
    return 0;
}
