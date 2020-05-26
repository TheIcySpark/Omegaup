#include <bits/stdc++.h>
using namespace std;
struct posicion{
    int i,j,distancia;
};
int ruta[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
queue<posicion> cola;
bool visitado[2002][2002];
char mapa[2002][2002];
int F,C;
void lectura(){
    cin>>F>>C;
    posicion agente;
    agente.distancia=0;
    for(int i=1;i<=F;i++){
        for(int j=1;j<=C;j++){
            cin>>mapa[i][j];
            if(mapa[i][j]=='G'){
                visitado[i][j]=true;
                agente.i=i; agente.j=j;
                cola.push(agente);
            }
        }
    }
}

int distanciaOptima(){
    int optimo=0;
    posicion actual,aux;
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
        actual.distancia++;
        for(int i=0;i<4;i++){
            aux=actual;
            aux.i+=ruta[i][0];
            aux.j+=ruta[i][1];
            if(!visitado[aux.i][aux.j] and mapa[aux.i][aux.j]=='.'){
                visitado[aux.i][aux.j]=true;
                cola.push(aux);
                optimo=aux.distancia;
            }
        }
    }
    return optimo;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    for(int i=0;i<=C;i++){
        visitado[0][i]=true;
        visitado[F+1][i]=true;
    }
    for(int i=0;i<=F;i++){
        visitado[i][C+1]=true;
        visitado[i][0]=true;
    }
    cout<<distanciaOptima()<<'\n';

    return 0;
}
/// xD
/**
5 5
G..#.
##.G.
G...#
....#
#####
**/