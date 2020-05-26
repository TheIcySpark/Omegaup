#include <bits/stdc++.h>
using namespace std;
int n,k,i,ef,ini,fin,maef;
int es[50002];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    i=1;
    while(i<=n){
        cin>>es[i];
        i++;
    }
    ef=0;
    ini=1;
    fin=k;
    maef=-10000;
    while (ini<= n-k+1 ){
        ef=es[fin]-es[ini];
        if (ef>maef){
            maef=ef;
        }
        fin++;
        ini++;
    }
    cout<<maef;
    return 0;
}
