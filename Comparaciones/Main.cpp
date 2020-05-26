#include <bits/stdc++.h>
using namespace std;
long a,b;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b;
    if(a<b){
        cout<<"menor";
    }
    if(a>b){
        cout<<"mayor";
    }
    if(a==b){
        cout<<"iguales";
    }
    return 0;
}
