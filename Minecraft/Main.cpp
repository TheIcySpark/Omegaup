#include <bits/stdc++.h>
using namespace std;
struct minecraft{
    int i,j,tiempo;
    const bool operator<(const minecraft &otro)const{
        return tiempo>otro.tiempo;
    }
};
char mapa[502][502];
int visitados[502][502];
int n,m,i,j;
minecraft ini,fin,actual;
priority_queue<minecraft> cola;

void lectura(){
    cin>>n>>m;
    cin>>ini.i>>ini.j;
    cin>>fin.i>>fin.j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>mapa[i][j];
        }
    }
    ini.tiempo=0;
}
void marcar(minecraft nuevo){
    visitados[nuevo.i][nuevo.j]=2;
    if(mapa[nuevo.i][nuevo.j]=='.') nuevo.tiempo++;
    else{
        nuevo.tiempo+=(mapa[nuevo.i][nuevo.j]-47);
    }
    cola.push(nuevo);
}
void mov1(minecraft nuevo){
    nuevo.j-=1;
    if(visitados[nuevo.i][nuevo.j]!=2 and mapa[nuevo.i][nuevo.j]!='#' and nuevo.i>=1 and nuevo.j>=1
       and nuevo.i<=n and nuevo.j<=m){
        marcar(nuevo);
    }
}
void mov2(minecraft nuevo){
    nuevo.j+=1;
    if(visitados[nuevo.i][nuevo.j]!=2 and mapa[nuevo.i][nuevo.j]!='#' and nuevo.i>=1 and nuevo.j>=1
       and nuevo.i<=n and nuevo.j<=m){
        marcar(nuevo);
    }
}
void mov3(minecraft nuevo){
    nuevo.i-=1;
    if(visitados[nuevo.i][nuevo.j]!=2 and mapa[nuevo.i][nuevo.j]!='#' and nuevo.i>=1 and nuevo.j>=1
       and nuevo.i<=n and nuevo.j<=m){
        marcar(nuevo);
    }
}
void mov4(minecraft nuevo){
    nuevo.i+=1;
    if(visitados[nuevo.i][nuevo.j]!=2 and mapa[nuevo.i][nuevo.j]!='#' and nuevo.i>=1 and nuevo.j>=1
       and nuevo.i<=n and nuevo.j<=m){
        marcar(nuevo);
    }
}
void busqueda(){
    cola.push(ini);
    mapa[ini.i][ini.j]=2;
    while(! cola.empty()){
        actual=cola.top(); cola.pop();
        if(actual.i==fin.i and actual.j==fin.j){
            cout<<actual.tiempo<<'\n';
            break;
        }
        mov1(actual);
        mov2(actual);
        mov3(actual);
        mov4(actual);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    busqueda();

    return 0;
}
/// xD