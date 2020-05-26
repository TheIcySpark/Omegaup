#include <bits/stdc++.h>
using namespace std;
struct nodo{
    short f,c;
    int costo;
    const bool operator<(const nodo &otro)const{
        return costo>otro.costo;
    }
};
bool primero=false;
priority_queue<nodo>cola;
short mapa[1002][1002];
bool visitado[1002][1002];
int f,c;
int movs[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

void lectura(){
    cin>>f>>c;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            cin>>mapa[i][j];
        }
    }
}

void limites(){
    for(int i=0;i<=f+1;i++){
        visitado[i][0]=true;
        visitado[i][c+1]=true;
    }
    for(int i=0;i<=c+1;i++){
        visitado[0][i]=true;
        visitado[f+1][i]=true;
    }
}

void pintar_primer_mar(int i,int j){
    if(mapa[i][j]<0 and mapa[i][j]!=-101){
        mapa[i][j]=-101;
        for(int aux=0;aux<8;aux++) pintar_primer_mar(i+movs[aux][0],j+movs[aux][1]);
    }
}

int primer_mar(){
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            if(mapa[i][j]<0){
                nodo aux;
                aux.f=i; aux.c=j; aux.costo=0;
                cola.push(aux);
                pintar_primer_mar(i,j);
                return i;
            }
        }
    }
}

void pintar_segundo_mar(int i,int j){
    if(mapa[i][j]!=-102 and mapa[i][j]<0){
        mapa[i][j]=-102;
        for(int aux=0;aux<8;aux++) pintar_segundo_mar(i+movs[aux][0],j+movs[aux][1]);
    }
}

void segundo_mar(int i){
    for(;i<=f;i++){
        for(int j=1;j<=c;j++){
            if(mapa[i][j]<0 and mapa[i][j]>-101){
                pintar_segundo_mar(i,j);
                return;
            }
        }
    }
}

int busqueda(){
    int minimo=INT_MAX;
    nodo actual,copia;
    while(!cola.empty()){
        actual=cola.top(); cola.pop();
        if(mapa[actual.f][actual.c]==-102 and actual.costo<minimo) minimo=actual.costo;
        for(int i=0;i<8;i++){
            copia=actual;
            copia.f+=movs[i][0];
            copia.c+=movs[i][1];
            if(!visitado[copia.f][copia.c]){
                visitado[copia.f][copia.c]=true;
                if(mapa[copia.f][copia.c]>0)copia.costo+=mapa[copia.f][copia.c];
                cola.push(copia);
            }
        }
    }
    return minimo;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    limites();
    segundo_mar(primer_mar());
    cout<<busqueda()<<'\n';

    return 0;
}
/// xD
/***
8 6
1 2 3 -1 -2 -3
1 2 3 -1 -2 -3
1 2 3 -1 -2 -3
1 2 3 4 5 6
1 2 3 4 5 6
-5 -4 -3 4 5 6
1 -4 -3 4 5 6
-5 -4 -3 4 5 6
**/