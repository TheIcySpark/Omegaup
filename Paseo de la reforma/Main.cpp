#include <bits/stdc++.h>
using namespace std;
int n;

int lectura(){
    cin>>n;
    int actual,sig,mayor,posible;
    mayor=1;
    posible=1;
    cin>>actual;
    for(int i=2;i<=n;i++){
        cin>>sig;
        if(sig<actual) posible++;
        else{
            if(posible>mayor) mayor=posible;
            posible=1;
        }
        actual=sig;
    }
    if(posible>mayor) mayor=posible;
    return mayor;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout<<lectura()<<'\n';


    return 0;
}
/// xD