#include <bits/stdc++.h>
using namespace std;
int n,i,cont,ni,res,ini,fin,xd;

struct nodo{
    int IZQ;
    int DER;
    int valor;
    int nivel;
    int columna;
    const bool operator<(const nodo &otro)const{
        if(nivel==otro.nivel){
            return columna<otro.columna;
        }else{
            return nivel<otro.nivel;
        }
    }
};

struct ar{
    nodo dato[1002];
    int disponible;
    void crea(int v){
        disponible=1;
        dato[1].valor=v;
        dato[1].IZQ=-1;
        dato[1].DER=-1;
    }
    void hijoder(int p,int v){
        disponible++;
        dato[disponible].valor=v;
        dato[disponible].DER=-1;
        dato[disponible].IZQ=-1;
        for(xd=1;xd<=1002;xd++){
            if(p==dato[xd].valor)break;
        }
        p=xd;
        dato[p].DER=disponible;
    }
    void hijoizq(int p,int v){
        disponible++;
        dato[disponible].valor=v;
        dato[disponible].DER=-1;
        dato[disponible].IZQ=-1;
        for(xd=1;xd<=1002;xd++){
            if(p==dato[xd].valor)break;
        }
        p=xd;
        dato[p].IZQ=disponible;
    }
};
ar arbol;
nodo lectura;

void revalorar(int i){
    if(i!=-1){
        ni++;
        revalorar(arbol.dato[i].IZQ);
        arbol.dato[i].columna=cont;
        arbol.dato[i].nivel=ni;
        revalorar(arbol.dato[i].DER);
        ni--;
    }else{
        cont++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    cin>>lectura.valor>>lectura.IZQ>>lectura.DER;
    arbol.crea(lectura.valor);
    if(lectura.IZQ!=-1) arbol.hijoizq(lectura.valor,lectura.IZQ);
    if(lectura.DER!=-1) arbol.hijoder(lectura.valor,lectura.DER);
    for(i=2;i<=n;i++){
        cin>>lectura.valor>>lectura.IZQ>>lectura.DER;
        if(lectura.IZQ!=-1) arbol.hijoizq(lectura.valor,lectura.IZQ);
        if(lectura.DER!=-1) arbol.hijoder(lectura.valor,lectura.DER);
    }
    revalorar(1);
    sort(arbol.dato+1,arbol.dato+n+1);
    res=0;
    for(i=1;i<=n;i++){
        ini=i;
        while(arbol.dato[i+1].nivel==arbol.dato[ini].nivel) i++;
        fin=i;
        if(((arbol.dato[fin].columna-arbol.dato[ini].columna)+1)>res){
            res=((arbol.dato[fin].columna-arbol.dato[ini].columna)+1);
            ni=arbol.dato[ini].nivel;
        }
    }
    cout<<ni<<" "<<res<<'\n';

    return 0;
}
/// xD
/**
19
1 2 3
2 4 5
4 6 7
3 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 19
18 -1 -1
19 -1 -1
**/