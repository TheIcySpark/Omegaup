#include <bits/stdc++.h>
using namespace std;
long long int n,m,dividir,resto,maxi,mini,aux;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    dividir=n/m;
    dividir--;
    if(n%m!=0){
        resto=n%m;
    }
    mini=dividir*(dividir+1)/2;
    mini=mini*(m-resto);
    dividir++;
    aux=dividir*(dividir+1)/2;
    aux=aux*(resto);
    mini=mini+aux;

    dividir=n-m;
    maxi=dividir*(dividir+1)/2;
    cout<<mini<<" "<<maxi<<'\n';

    return 0;
}