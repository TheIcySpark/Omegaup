#include <bits/stdc++.h>
using namespace std;

struct nodo{
    int valor;
    int IZQ;
    int DER;
};

struct arbol{
    nodo dato[1000002];
    int raiz;
    int disponible;
    void crea(int v){
        raiz=1;
        disponible=1;
        dato[1].IZQ=-1;
        dato[1].DER=-1;
        dato[1].valor=v;
    }
    void hijoder(int p,int v){
        disponible++;
        dato[disponible].IZQ=-1;
        dato[disponible].DER=-1;
        dato[disponible].valor=v;
        dato[p].DER=disponible;
    }
    void hijoizq(int p,int v){
        disponible++;
        dato[disponible].IZQ=-1;
        dato[disponible].DER=-1;
        dato[disponible].valor=v;
        dato[p].IZQ=disponible;
    }
    int buscar(int i,int v){
        if(v==dato[i].valor) return i;
        if(v>dato[i].valor){
            if(dato[i].DER==-1){
                hijoder(i,v);
                return -1;
            }else{
                return buscar(dato[i].DER,v);
            }
        }else{
            if(dato[i].IZQ==-1){
                hijoizq(i,v);
                return -1;
            }else{
                return buscar(dato[i].IZQ,v);
            }
        }
    }
};

arbol a;

void preorden(int i){
    if(i!=-1){
        cout<<a.dato[i].valor<<" ";
        preorden(a.dato[i].IZQ);
        preorden(a.dato[i].DER);
    }
}

void inorden(int i){
    if(i!=-1){
        inorden(a.dato[i].IZQ);
        cout<<a.dato[i].valor<<" ";
        inorden(a.dato[i].DER);
    }
}

void postorden(int i){
    if(i!=-1){
        postorden(a.dato[i].IZQ);
        postorden(a.dato[i].DER);
        cout<<a.dato[i].valor<<" ";
    }
}

int main()
{
    int eso[100000];
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>eso[i];
    }
    a.crea(eso[n]);
    for(i=n;i>=1;i--){
        a.buscar(1,eso[i]);
    }
    preorden(1);
    return 0;
}
/// xD