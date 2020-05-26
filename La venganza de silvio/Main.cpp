#include <bits/stdc++.h>
using namespace std;
string cadena;
long long int m,n,i,resultado,elevar;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>cadena;
    elevar=n; i=cadena.length()-1;
    resultado=1;
    if(m==1) resultado=0;
    while(i>=0){
        if(cadena[i]=='1'){
            resultado=((resultado%m)*(elevar%m))%m;
        }
        elevar=((elevar%m)*(elevar%m))%m;
        i--;
    }
    cout<<resultado<<'\n';

    return 0;
}