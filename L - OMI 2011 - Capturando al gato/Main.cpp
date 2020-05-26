#include <bits/stdc++.h>
using namespace std;
int N;
long long int D;
long long int dis[5002];

void Lectura(){
    cin>>N;
    D=0;
    for(int i=1;i<=N;i++){
        cin>>dis[i];
        D+=dis[i];
    }
}

bool Posible(int salto){
    int recorrido,suma,j,contador;
    recorrido=N-(D/salto);
    for(int i=1;i<=recorrido+1;i++){
        contador=1;
        suma=0;
        j=i+1;
        while(suma<salto){
            if(j>N) j=1;
            suma+=dis[j];
            if(suma==salto){
                suma=0;
                contador++;
                if(contador==D/salto) return true;
            }
            j++;
        }
    }
    return false;
}

int Calculo(){
    for(int i=N;i>1;i--){
        if(D%i==0 and Posible(D/i)) return i;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    Lectura();
    cout<<Calculo()<<'\n';

    return 0;
}
/// xD
/**
8
3 1 3 4 7 2 4 4
**/