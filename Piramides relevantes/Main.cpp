#include <bits/stdc++.h>
using namespace std;
struct pir{
    int altura,relevancia;
};
stack<int>pila;
pir piramide[1000002];
int maximo[1000002];
int n;
void lectura(){
    cin>>n;
    for(int i=1;i<=n;i++){
         cin>>piramide[i].altura>>piramide[i].relevancia;
         maximo[i]=piramide[i].relevancia;
    }
}

void alcanze(int ini,int fin,int dir){
    pila.push(ini);
    for(int i=ini;i!=fin;i+=dir){
        while(!pila.empty()){
            if(piramide[i].altura>piramide[pila.top()].altura){
                maximo[i]=max(maximo[i],maximo[pila.top()]);
                pila.pop();
            }else{
                maximo[i]=max(maximo[i],piramide[pila.top()].relevancia);
                break;
            }
        }
        pila.push(i);
    }
    if(dir==-1) return;
    else{
        while(!pila.empty()) pila.pop();
    }
}

void imprimir(){
    for(int i=1;i<=n;i++) cout<<maximo[i]<<" ";
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    alcanze(1,n+1,1);
    alcanze(n,0,-1);
    imprimir();

    return 0;
}
/// xD
/**
**/