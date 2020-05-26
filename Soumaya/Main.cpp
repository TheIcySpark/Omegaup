#include <bits/stdc++.h>
using namespace std;
struct limites{
    int alto,bajo,izq,der;
};

struct nodo{
    int f,c;
};
int fig;
int movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int f,c;
int figura[1502][1502];
char pintado[1502][1502];
bool visitados[1502][1502];
queue<nodo>cola;
limites lim;

void lectura(){
    cin>>f>>c;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            cin>>pintado[i][j];
        }
    }
}

void pintar_bien(int fila,int columna){
    lim.alto=fila; lim.bajo=fila;
    lim.izq=columna; lim.der=columna;
    nodo actual,copia;
    actual.f=fila; actual.c=columna;
    cola.push(actual);
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
        for(int i=0;i<4;i++){
            copia=actual;
            copia.f+=movs[i][0];
            copia.c+=movs[i][1];
            if(copia.f>=1 and copia.f<=f and copia.c>=1 and copia.c<=c){
                if(pintado[copia.f][copia.c]=='0'){
                    if(copia.f<=lim.alto and copia.f>=lim.bajo and copia.c<=lim.der and copia.c>=lim.izq){
                        pintado[copia.f][copia.c]='1';
                        figura[copia.f][copia.c]=fig;
                        visitados[copia.f][copia.c]=1;
                        cola.push(copia);
                    }
                }else{
                    if(!visitados[copia.f][copia.c] or (figura[copia.f][copia.c]!=fig and figura[copia.f][copia.c]!=0)){
                        if(copia.f>lim.alto) lim.alto=copia.f;
                        if(copia.f<lim.bajo) lim.bajo=copia.f;
                        if(copia.c>lim.der) lim.der=copia.c;
                        if(copia.c<lim.izq) lim.izq=copia.c;
                        figura[copia.f][copia.c]=fig;
                        visitados[copia.f][copia.c]=1;
                        cola.push(copia);
                    }
                }
            }
        }
    }
}

void recorrido(){
    fig=0;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            if(pintado[i][j]=='1' and !visitados[i][j]){
                fig++;
                pintar_bien(i,j);
            }
        }
    }
}

void mostrar(){
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            cout<<pintado[i][j];
        }
        cout<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    recorrido();
    mostrar();

    return 0;
}
/// xD