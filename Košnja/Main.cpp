#include <bits/stdc++.h>
using namespace std;
int k,n,m;
int calculo(){
    int menor=min(n,m);
    menor--;
    return menor*2;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>n>>m;
        cout<<calculo()<<'\n';
    }
    return 0;
}
/// xD
/***
**/