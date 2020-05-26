#include <bits/stdc++.h>
using namespace std;
long long int n,m,k,cont,fila,columna,c,f,a,b;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    columna=1;
    fila=1;
    c=0; f=0; a=0; f=0;
    while(columna<=m){
        columna+=k;
        c++;
    }
    columna-=k; columna++;
    while(columna<=m){
        columna++;
        b+=c;
    }
    while(fila<=n){
        fila+=k;
        f++;
    }
    fila-=k; fila++;
    while(fila<=n){
        fila++;
        a+=f;
    }
    f+=a; c+=b;
    cont=f*c;
    cout<<cont<<'\n';

    return 0;
}
/// xD