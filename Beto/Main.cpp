#include <bits/stdc++.h>
using namespace std;
struct nodo{
    long long int conexion,distancia;
};
vector<vector<nodo> > lista(100002);
long long int n,m,x,y;
int posible[100002];

void leer(long long int j,int ciudad){
    long long int aux;
    for(long long int i=1;i<=j;i++){
        cin>>aux;
        posible[aux]=ciudad;
    }
}

long long int buscar(){
    long long int menor=INT_MAX;
    for(long long int i=0;i<n;i++){
        if(posible[i]==1){
            for(long long int j=0;j<lista[i].size();j++){
                if(posible[lista[i][j].conexion]==2){
                    if(lista[i][j].distancia<menor) menor=lista[i][j].distancia;
                }
            }
        }
    }
    return menor;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long int a,b,dis;
    cin>>n>>m>>x>>y;
    leer(x,1); leer(y,2);
    for(long long int i=1;i<=m;i++){
        cin>>a>>b>>dis;
        lista[a].push_back({b,dis});
        lista[b].push_back({a,dis});
    }
    cout<<buscar()<<'\n';

    return 0;
}
/// xD
/***
5 4 3 2
0 1 2
3 4
3 2 20
2 4 10
0 2 10
1 2 5
r= 10

6 5 3 3
0 1 2
3 4 5
5 4 1
4 3 1
3 2 8
3 1 9
3 0 10
r= 8

3 1 1 1
0
1
0 1 10
r= 10

**/