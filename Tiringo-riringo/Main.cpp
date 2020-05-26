#include <iostream>
#include <algorithm>
using namespace std;
struct OrdenarIni{
    long long int a,b;
    const bool operator<(const OrdenarIni &otro)const{
        return a<otro.a;
    }
};
struct OrdenarFin{
    long long int a,b;
    const bool operator<(const OrdenarFin &otro)const{
        return b>otro.b;
    }
};
int N,Q;
OrdenarIni pIni[100002];
OrdenarFin pFin[100002];
void lectura(){
    cin>>N>>Q;
    for(int i=1;i<=N;i++){
        cin>>pIni[i].a>>pIni[i].b;
        pFin[i].a=pIni[i].a;
        pFin[i].b=pIni[i].b;
    }
}

int busqueda(long long int k){
    int ini=1,fin=N+1,m;
    int ret=N;
    while(ini<fin){
        m=(ini+fin)/2;
        if(pIni[m].a>k) fin=m;
        else ini=m+1;
    }
    if(ini<=N) ret=ret-(N-ini+1);
    ini=1; fin=N+1;
    while(ini<fin){
        m=(ini+fin)/2;
        if(pFin[m].b<k) fin=m;
        else ini=m+1;
    }
    if(ini<=N) ret=ret-(N-ini+1);
    return ret;
}

void Calculo(){
    long long int k;
    for(int i=1;i<=Q;i++){
        cin>>k;
        cout<<busqueda(k)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    sort(pIni+1,pIni+N+1);
    sort(pFin+1,pFin+N+1);
    Calculo();

    return 0;
}
/// xD
/**
3 1
0 3
2 4
3 7
-1
**/