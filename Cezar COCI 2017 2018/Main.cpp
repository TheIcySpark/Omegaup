#include <bits/stdc++.h>
using namespace std;
int n,valor;
int cartas[15];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int puntos=0;
    int menores,mayores;
    cin>>n;
    for(int i=2;i<=11;i++) cartas[i]=4;
    cartas[10]*=4;
    for(int i=1;i<=n;i++){
        cin>>valor;
        cartas[valor]--;
        puntos+=valor;
    }
    puntos=(21-puntos);
    menores=0; mayores=0;
    for(int i=2;i<=puntos;i++){
        menores+=cartas[i];
    }
    for(int i=puntos+1;i<=11;i++){
        mayores+=cartas[i];
    }
    if(menores>mayores) cout<<"VUCI"<<'\n';
    else cout<<"DOSTA"<<'\n';


    return 0;
}
/// xD
/***
**/