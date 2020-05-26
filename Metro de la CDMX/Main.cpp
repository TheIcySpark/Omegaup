#include <bits/stdc++.h>
using namespace std;
char posible;
int P,D,Q;
bool visitados_global[100002];
bool visitados_temporal[100002];
bool ciclo[100002];
vector< vector<int> >nodo(100002);

bool revision(int i){
    if(visitados_temporal[i]) return true;
    if(nodo[i].size()==0) return false;
    if(visitados_global[i]) return ciclo[i];
    visitados_global[i]=true;
    visitados_temporal[i]=true;
    bool aux=false;
    for(int j=0;j<nodo[i].size();j++){
        if(revision(nodo[i][j])){
            aux=true;
        }
    }
    visitados_temporal[i]=false;
    return ciclo[i]=aux;
}

void calculos(){
    for(int i=1;i<=P;i++){
        if(nodo[i].size()==0){
            visitados_global[i]=true;
        }else if(!visitados_global[i]){
            revision(i);
        }
    }
}

void lectura(){
    cin>>P>>D>>Q;
    for(int i=1;i<=D;i++){
        int cual,cuantas,abre;
        cin>>cual>>cuantas;
        for(int j=1;j<=cuantas;j++){
            cin>>abre;
            nodo[cual].push_back(abre);
        }
    }
    calculos();
    for(int i=1;i<=Q;i++){
        posible='S';
        int cuantas,cual;
        cin>>cuantas;
        for(int j=1;j<=cuantas;j++){
            cin>>cual;
            if(ciclo[cual]) posible='N';
        }
        cout<<posible<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();

    return 0;
}
/// xD
/***
10 5 4
1 2 2 6
2 1 3
3 1 4
4 1 3
6 2 7 8

3
6 7 8

1
1

2
2 5

1
6

**/