#include <bits/stdc++.h>
using namespace std;
long long int n,a;
long long int suma,dos=2;
long long int cantidad[1002];

void lectura(){
    cin>>n>>a;
    for(int i=1;i<=n;i++){
        cin>>cantidad[i];
    }
}

long long int recorrido(){
    long long int aux,maximo,minimo,faltantes,no_utiles,k;
    if(a==1){
        no_utiles=0;
        k=1;
    }else no_utiles=INT_MAX;
    for(int i=max(dos,a);i<=n;i++){
        suma-=cantidad[i];
        aux=suma;
        ///cout<<aux<<endl;
        minimo=cantidad[i];
        maximo=cantidad[1];
        faltantes=0;
        int j;
        for(j=i-1;j>=1;j--){
            if(aux==0) break;
            if(aux>=(cantidad[j]-cantidad[j+1])*(i-j)){
                aux-=(cantidad[j]-cantidad[j+1])*(i-j);
                minimo=cantidad[j];
            }else{
                minimo=aux/(i-j);
                aux=0;
                break;
            }
        }
        ///cout<<aux<<endl;
        if(j==0 and aux>0){
            faltantes=aux%i;
        }else{
            for(int help=i;help>=1;help--){
                faltantes+=maximo-max(minimo,cantidad[help]);
            }
        }
        ///cout<<i<<" "<<faltantes<<" "<<maximo<<" "<<minimo<<endl;
        if(faltantes<=no_utiles){
            no_utiles=faltantes;
            k=i;
        }
    }
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    sort(cantidad+1,cantidad+n+1);
    reverse(cantidad+1,cantidad+n+1);
    for(int i=max(a,dos);i<=n;i++){
        suma+=cantidad[i];
    }
    cout<<recorrido()<<'\n';

    return 0;
}
/// xD
/***
5 1
4 4 3 3 3

6 3
12 12 9 8 6 4
**/