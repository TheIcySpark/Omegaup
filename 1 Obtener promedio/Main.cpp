#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int dato,n;
    double suma;
    suma=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dato;
        suma+=dato;
    }
    cout<<fixed<<setprecision(2)<<suma/n;

    return 0;
}
/// xD
///  7 200 50 1 1 1 1 4