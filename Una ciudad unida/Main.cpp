#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >lista(100002);
bool marcados[1000002];
int n,m;

int contar(int dato){
    int actual,cont=1;
    queue<int>cola;
    cola.push(dato);
    marcados[dato]=true;
    while(! cola.empty()){
        actual=cola.front(); cola.pop();
        for(int i=0;i<lista[actual].size();i++){
            if(marcados[lista[actual][i]]==false){
                cont++;
                cola.push(lista[actual][i]);
                marcados[lista[actual][i]]=true;
            }
        }
    }
    int aux;
    aux=(n-cont);
    cont*=aux;
    return cont;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,cont;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        lista[a].push_back(b);
        lista[b].push_back(a);
    }
    cont=0;
    for(int i=1;i<=n;i++){
        if(marcados[i]==false) cont+=contar(i);
    }
    cout<<(cont/2)<<'\n';

    return 0;
}
/// xD
/***
5 3
1 2
2 4
3 5
r=6

6 3
1 2
3 4
5 6
r=12
**/