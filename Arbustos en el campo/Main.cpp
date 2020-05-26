#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;
int arbusto[1003];
int memo[1003][1003][2];
int n,ini,posInicial;

void Read(){
    cin>>n>>ini;
    for(int i=1;i<=n;i++) cin>>arbusto[i];
    n++;
    arbusto[n]=ini;
    sort(arbusto+1,arbusto+n+1);
}

int binaria(int k){
    int ini,fin,m;
    ini=1; fin=n;
    while(ini<=fin){
        m=(ini+fin)/2;
        if(arbusto[m]<k) ini=m+1;
        else if(arbusto[m]>k) fin=m-1;
        else return m;
    }
}

int memorizar(int izq,int der,int pos,int i){
    int ramaIzq,ramaDer;
    if(izq==0) ramaIzq=INT_MAX;
    else{
        ramaIzq=(arbusto[pos]-arbusto[izq])*i+memo[izq-1][der][0];
    }
    if(der==n+1) ramaDer=INT_MAX;
    else{
        ramaDer=(arbusto[der]-arbusto[pos])*i+memo[izq][der+1][1];
    }
    //cout<<izq<<" "<<der<<" "<<pos<<" "<<ramaIzq<<" "<<ramaDer<<endl;
    return min(ramaIzq,ramaDer);
}

int f(){
    int izq,der;
    for(int i=1;i<=n;i++){
        der=max(posInicial+1,n-i+1);
        izq=max(i-(n-der+1),0);
        while(der<=n+1){
            memo[izq][der][0]=memorizar(izq,der,izq+1,i);
            memo[izq][der][1]=memorizar(izq,der,der-1,i);
            izq++; der++;
        }
    }
    cout<<memo[posInicial-1][posInicial+1][0]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    Read();
    posInicial=binaria(ini);
    f();

    return 0;
}
/// xD
/**
5 7
1 4 6 8 12
**/