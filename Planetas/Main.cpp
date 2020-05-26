#include <bits/stdc++.h>
using namespace std;
int planeta[1002];
int n;
queue<double>cola;
void lectura(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>planeta[i];
}

double sumatoria(int ini,int fin,int dir,double pos){
    double suma=0;
    for(int i=ini;i!=fin;i+=dir){
        suma+=double(1/(abs(pos-planeta[i])));
    }
    return suma;
}

void binaria(){
    double ini,fin,mit,der,izq;
    for(int i=1;i<n;i++){
        ini=planeta[i];
        fin=planeta[i+1];
        while(fin-ini>0.000001){
            mit=double((ini+fin)/2);
            der=sumatoria(i+1,n+1,1,mit);
            izq=sumatoria(i,0,-1,mit);
            if(der>izq) fin=mit;
            else ini=mit;
        }
        mit=double((ini+fin)/2);
        cola.push(mit);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    sort(planeta+1,planeta+n+1);
    cout.precision(3);
    cout<<fixed;
    binaria();
    cout<<cola.size()<<'\n';
    while(!cola.empty()){
        cout<<cola.front()<<" "; cola.pop();
    }

    return 0;
}
/// xD
/**
**/