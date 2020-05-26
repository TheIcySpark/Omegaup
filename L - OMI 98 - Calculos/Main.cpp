#include <bits/stdc++.h>
using namespace std;
int pasos[10001];
int visitados[10001];
int actual, nuevo;
queue<int>cola;
int a,b,n;

int main()
{
    cin>>a>>b>>n;
    actual=1;
    cola.push(actual);
    visitados[actual]=1;
    pasos[actual]=0;
    while(! cola.empty()){
        actual=cola.front();
        cola.pop();
        if(actual==n){
            cout<<pasos[actual];
            break;
        }
        nuevo=actual*a;
        if(nuevo>9999){
            nuevo=1;
        }
        if(visitados[nuevo]!=1){
            cola.push(nuevo);
            visitados[nuevo]=1;
            pasos[nuevo]=pasos[actual]+1;
        }
        nuevo=actual/b;
        if(visitados[nuevo]!=1){
            cola.push(nuevo);
            visitados[nuevo]=1;
            pasos[nuevo]=pasos[actual]+1;
        }
    }

    return 0;
}