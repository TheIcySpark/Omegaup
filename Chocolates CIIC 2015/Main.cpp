#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int chocolate[100002];
void lectura(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>chocolate[i];
}
bool posible(long long int &m){
    long long int suma=0;
    int i=1;
    while(i<=n and suma>=0){
        suma+=chocolate[i]; suma-=m;
        i++;

    }
    if(suma>=0) return true;
    else return false;
}

long long int binaria(){
    long long int ini,fin,m;
    ini=0; fin=1000000002;
    while(ini!=fin){
        m=(ini+fin)/2 + 1;
        if(posible(m)){
            ini=m;
        }else{
            fin=m-1;
        }
    }
    return ini;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    cout<<binaria()<<'\n';

    return 0;
}
/// xD
/***
**/