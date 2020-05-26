#include <bits/stdc++.h>
using namespace std;
int c,i,n,canguros,comida,ini,fin;
int cola[1000002];
char accion;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n;
    ini=1; fin=1;
    while(n>=1){
        cin>>accion;
        if(accion=='N'){
            cin>>canguros; canguros++;
            cola[fin]=canguros; fin++;
        }else if(accion=='A'){
            c-=cola[ini]; ini++;
        }else if(accion=='R'){
            cout<<c<<'\n';
        }else if(accion=='C'){
            cout<<fin-ini<<'\n';
        }
        n--;
    }
    return 0;
}
/// xd