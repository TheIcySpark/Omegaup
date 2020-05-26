#include <bits/stdc++.h>
using namespace std;
int n,m;
long long int suma;
int grafico[1000002];
bool lista[1000002];
int izq[1000002];
int der[1000002];

void lectura(){
    int dato;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>grafico[i];
    }
    for(int i=1;i<=m;i++){
        cin>>dato;
        lista[dato]=1;
    }
}

void lados(){
    for(int i=1;i<=n;i++){
        if(grafico[i]>0){
             grafico[0]=grafico[i];
             break;
        }
    }
    for(int i=n;i>=1;i--){
        if(grafico[i]>0){
            grafico[n+1]=grafico[i];
            break;
        }
    }
}

void barrido(){
    for(int i=1;i<=1000000;i++){
        if(lista[i]==1) izq[i]=i;
        else izq[i]=izq[i-1];
    }
    for(int i=1000000;i>=1;i--){
        if(lista[i]==1) der[i]=i;
        else der[i]=der[i+1];
    }
}

void recorrido(){
    for(int i=1;i<=n;i++){
        if(grafico[i]==0){
            int a,b,aux,agregar,opizq,opder;
            a=grafico[i-1];
            for(int j=i;grafico[j]==0;j++) b=grafico[j+1];
            aux=max(a,b);
            a=min(a,b); b=aux;
            if(izq[b]>=a){
                agregar=izq[b];
            }else{
                if(izq[a-1]>0) opizq=izq[a-1];
                else opizq=INT_MAX;
                if(der[b+1]>0) opder=der[b+1];
                else opder=INT_MAX;
                if(abs((a-1)-opizq)<abs(opder-(b+1))) agregar=opizq;
                else agregar=opder;
            }
            while(grafico[i]==0){
                grafico[i]=agregar;
                i++;
            }
        }
    }
}

void imprimir(){
    suma=0;
    for(int i=2;i<=n;i++) suma+=abs(grafico[i]-grafico[i-1]);
    cout<<suma<<'\n';
    for(int i=1;i<=n;i++){
        cout<<grafico[i]<<" ";
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    lados();
    barrido();
    recorrido();
    imprimir();

    return 0;
}
/// xD
/***
8 2 1 7 0 1 0 4 0 15 9 18


**/