#include <bits/stdc++.h>
using namespace std;
int casos;
priority_queue<char> cola;

void suma_maxima(){
    long long int sacado,mostrar,ceros;
    ceros=1; mostrar=0;
    for(int i=1;i<cola.size()-1;i++) ceros*=10;
    while(!cola.empty()){
        sacado=cola.top(); cola.pop();
        sacado-=48;
        sacado*=ceros;
        ceros/=10;
        mostrar+=sacado;
        if(ceros==0) ceros=1;
    }
    cout<<mostrar<<'\n';
}

void lectura(){
    cin>>casos;
    for(int i=1;i<=casos;i++){
        string numeros;
        cin>>numeros;
        for(int j=0;j<numeros.size();j++) cola.push(numeros[j]);
        suma_maxima();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();

    return 0;
}
/// xD