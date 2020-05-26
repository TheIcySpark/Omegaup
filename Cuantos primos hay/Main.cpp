#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,cont,j;
    cont=1;
    cin>>n;
    if(n<2){
        cout<<"No existen numeros primos en la cantidad ingresada."<<'\n';
        return 0;
    }
    for(int i=3;i<=n;i++){
        j=2;
        while(j<=sqrt(i) and i%j!=0) j++;
        if(j>sqrt(i)) cont++;
    }
    cout<<cont<<'\n';


    return 0;
}
/// xD
/***
**/