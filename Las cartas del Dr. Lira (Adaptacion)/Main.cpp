#include <bits/stdc++.h>
using namespace std;
int i,n,carta,m0,m1,cont0,cont1,menor;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    cont0=0; cont1=0;
    m0=0; m1=1;
    for(i=1;i<=n;i++){
        cin>>carta;
        if(carta!=m0) cont0++;
        if(carta!=m1) cont1++;
        m0++; m1++;
        if(m0>1) m0=0;
        if(m1>1) m1=0;
    }
    menor=min(cont0,cont1);
    cout<<menor<<'\n';

    return 0;
}
/// XD