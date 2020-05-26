#include <bits/stdc++.h>
using namespace std;
int i,n,p,tarea,cont;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>p;
    cont=0;
    for(i=1;i<=n;i++){
        cin>>tarea;
        if(tarea>p and cont==0) cont=n-i+1;
    }
    cout<<cont<<'\n';

    return 0;
}