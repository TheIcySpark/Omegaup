#include <bits/stdc++.h>
using namespace std;
long long int ini,fin,m,suma,a,c,resta,mayor;

bool donde(){
    long long int aux=m; resta=0;
    while(aux>=10){
        resta+=(aux%10);
        aux/=10;
    }
    resta+=aux;
    if(m-resta>=c) return true;
    else return false;
}

long long int busqueada(){
    ini=1; fin=a; suma=0;
    mayor=0;
    while(fin>=ini){
        m=(ini+fin)/2;
        if(donde()==true){
            fin=m-1;
            mayor=a-(m-1);
        }else{
            ini=m+1;
        }
    }
    return mayor;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>c;
    cout<<busqueada()<<'\n';

    return 0;
}
/// xD