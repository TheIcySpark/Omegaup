#include <bits/stdc++.h>
using namespace std;
long long int mayor,p,n,i,k,j;
long long int cubiculo[100002];

bool util(long long int m){
    long long int per=p-1;
    i=1; j=2;
    while(i<=n and per>=1 and j<=n){
        if((cubiculo[j]-cubiculo[i])>=m){
            per--; i=j;
        }else{
            j++;
        }
    }
    if(per==0) return true;
    else return false;
}

long long int buscar(long long int ini,long long int fin){
    long long int m=(ini+fin)/2;
    bool b;
    b=util(m);
    if(ini>fin){
        return mayor;
    }
    if(b==true){
        mayor=m;
        return buscar(m+1,fin);
    }else{
        return buscar(ini,m-1);
    }
}

int main()
{
    cin>>n>>p;
    for(i=1;i<=n;i++){
        cin>>cubiculo[i];
    }
    sort(cubiculo+1,cubiculo+n+1);
    k=buscar(0,100000000);
    cout<<k<<'\n';

    return 0;
}