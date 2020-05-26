#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int dato[102];

double par(){
    return ((dato[n/2]+dato[n/2+1]))/2;
}
double impar(){
    return dato[n/2+1];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    double media;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dato[i];
    }
    sort(dato+1,dato+n+1);
    if(n%2==0){
        media=(dato[n/2]+dato[n/2+1]);
        media/=2;
    }else{
        media=impar();
    }
    cout<<setprecision(1)<<fixed<<media<<'\n';

    return 0;
}
/// xD
/***
5
2 5 1 7 3
**/