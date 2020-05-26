#include <bits/stdc++.h>
using namespace std;
int n,izq,der;
int nino[30002];

void lectura(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nino[i];
        if(nino[i]==1) der++;
    }
}

int calculo(){
    int minimo=INT_MAX;
    for(int i=1;i<=n+1;i++){
        if(izq+der<minimo) minimo=izq+der;
        if(nino[i]==1) der--;
        else izq++;
    }
    return minimo;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    der=0; izq=0;
    lectura();
    cout<<calculo()<<'\n';

    return 0;
}
/// xD
/***
**/