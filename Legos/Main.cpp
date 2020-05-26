#include <bits/stdc++.h>
using namespace std;
struct st{
    long long int a;
    long long int b;
};
long long int n,i,veces;
long long int datos[300002];
st mayor[300002],menor[300002];
st belleza;
stack<long long int>pila;

void dermayor(){
    i=n;
    while(i>=1){
        mayor[i].a=1;
        while(!pila.empty() and datos[i]>=datos[pila.top()]){
            mayor[i].a+=mayor[pila.top()].a;
            pila.pop();
        }
        pila.push(i);
        i--;
    }
}

void izqmayor(){
    while(! pila.empty()) pila.pop();
    i=1;
    while(i<=n){
        mayor[i].b=1;
        while(!pila.empty() and datos[i]>datos[pila.top()]){
            mayor[i].b+=mayor[pila.top()].b;
            pila.pop();
        }
        pila.push(i);
        i++;
    }
}

void dermenor(){
    while(! pila.empty()) pila.pop();
    i=n;
    while(i>=1){
        menor[i].a=1;
        while(!pila.empty() and datos[i]<=datos[pila.top()]){
            menor[i].a+=menor[pila.top()].a;
            pila.pop();
        }
        pila.push(i);
        i--;
    }
}

void izqmenor(){
    while(! pila.empty()) pila.pop();
    i=1;
    while(i<=n){
        menor[i].b=1;
        while(!pila.empty() and datos[i]<datos[pila.top()]){
            menor[i].b+=menor[pila.top()].b;
            pila.pop();
        }
        pila.push(i);
        i++;
    }
}

void sumamayor(){
    for(i=1;i<=n;i++){
        veces=((mayor[i].a*mayor[i].b)-1);
        belleza.a+=(datos[i]*veces);
    }
}

void sumamenor(){
    for(i=1;i<=n;i++){
        veces=((menor[i].a*menor[i].b)-1);
        belleza.b+=(datos[i]*veces);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>datos[i];
    }
    dermayor();
    dermenor();
    izqmayor();
    izqmenor();
    belleza.a=0; belleza.b=0;
    sumamayor();
    sumamenor();
    cout<<belleza.a-belleza.b<<'\n';

    return 0;
}
/// xD
/// 5 1 2 3 2 1