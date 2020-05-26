#include <bits/stdc++.h>
using namespace std;
struct nodo{
    int yl,xl,ym,xm,p;
};
int movs[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool visitados[52][52][52][52];
int n;
char mapa[52][52];
queue<nodo>cola;
void lectura(){
    nodo inicial;
    inicial.p=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mapa[i][j];
            if(mapa[i][j]=='M'){
                inicial.ym=i;
                inicial.xm=j;
            }
            if(mapa[i][j]=='L'){
                inicial.yl=i;
                inicial.xl=j;
            }
        }
    }
    cola.push(inicial);
    visitados[inicial.ym][inicial.xm][inicial.yl][inicial.xl]=1;
}

bool terminamos(nodo r){
    if(mapa[r.ym][r.xm]=='S' and mapa[r.yl][r.xl]=='S') return true;
    return false;
}

bool valido(nodo r){
    if(mapa[r.ym][r.xm]!='#' and mapa[r.yl][r.xl]!='#' and !visitados[r.ym][r.xm][r.yl][r.xl]){
        if((mapa[r.ym][r.xm]=='*' or mapa[r.yl][r.xl]=='*') and (mapa[r.ym][r.xm]!='B' and mapa[r.yl][r.xl]!='B')){
            return false;
        }
        return true;
    }
    return false;
}

int busqueda(){
    nodo actual,copia;
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
        ///cout<<actual.ym<<" "<<actual.xm<<" "<<actual.yl<<" "<<actual.xl<<endl;
        if(terminamos(actual)){
            return actual.p;
        }
        for(int i=0;i<4;i++){
            copia=actual;
            copia.ym+=movs[i][0];
            copia.xm+=movs[i][1];
            if(valido(copia)){
                copia.p++;
                visitados[copia.ym][copia.xm][copia.yl][copia.xl]=1;
                cola.push(copia);
            }
        }
        for(int i=0;i<4;i++){
            copia=actual;
            copia.yl+=movs[i][0];
            copia.xl+=movs[i][1];
            if(valido(copia)){
                copia.p++;
                visitados[copia.ym][copia.xm][copia.yl][copia.xl]=1;
                cola.push(copia);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    cout<<busqueda()<<'\n';

    return 0;
}
/// xD
/***
6
######
#S...#
#....#
#....#
#..ML#
######
**/