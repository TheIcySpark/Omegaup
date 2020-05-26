#include <bits/stdc++.h>
using namespace std;
long long int datos[1000002],maximo,anterior;
long long int n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>datos[i];
    }
    anterior=0; maximo=INT_MIN;
    for(int i=n;i>=1;i--){
        if(datos[i]+anterior>maximo){
            maximo=datos[i]+anterior;
        }
        anterior=max(datos[i],datos[i]+anterior);
    }
    cout<<maximo<<'\n';

    return 0;
}
/// xD