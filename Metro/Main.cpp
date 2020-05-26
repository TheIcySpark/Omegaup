#include <bits/stdc++.h>
using namespace std;
struct metro{
    int a,b,c;
    const bool operator<(const metro &otro)const{
        return c<otro.c;
    }
};
struct union_find{
    vector<int>padre;
    vector<int>nivel;
    void inicializar(int n){
        padre.resize(n+2);
        nivel.resize(n+2);
        for(int i=1;i<=n;i++){
            padre[i]=i;
            nivel[i]=0;
        }
    }
    int encontrar(int nodo){
        if(padre[nodo]==nodo){
            return nodo;
        }else{
            return padre[nodo]=encontrar(padre[nodo]);
        }
    }
    bool unir(int a,int b){
        a=encontrar(a);
        b=encontrar(b);
        if(a!=b){
            if(nivel[a]>nivel[b]){
                padre[b]=a;
            }else if(nivel[b]>nivel[a]){
                padre[a]=b;
            }else{
                padre[a]=b;
                nivel[b]++;
            }
            return true;
        }
        return false;
    }
};
int n,m;
metro camino[200002];

void lectura(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>camino[i].a>>camino[i].b>>camino[i].c;
    }
    sort(camino+1,camino+m+1);
}

long long int peso_minimo(){
    long long int suma=0;
    int vertices=0;
    union_find arbol;
    arbol.inicializar(n);
    int i=1;
    while(i<=m and vertices<n-1){
        if(arbol.unir(camino[i].a,camino[i].b)){
            vertices++;
            suma+=camino[i].c;
        }
        i++;
    }
    return suma;
}

int main()
 {
    lectura();
    cout<<peso_minimo()<<'\n';

 	return 0;
 }
/// xD
/***
7 12
1 2 3
1 3 4
1 7 100

**/