#include <bits/stdc++.h>
using namespace std;
int n,k,suma,mayor;
int valor[1000002];

void lectura(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>valor[i];
    for(int i=1;i<=k;i++) suma+=valor[i];
    mayor=suma;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    for(int i=k+1;i<=n;i++){
        suma+=valor[i];
        suma-=valor[i-k];
        if(suma>mayor) mayor=suma;
    }
    cout<<mayor<<'\n';

    return 0;
}
/// xD
/***
**/