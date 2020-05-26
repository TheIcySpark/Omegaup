#include <bits/stdc++.h>
using namespace std;
long i,N,avance,mayor,ant,cont;
int A[1000002],ext[1000002],exti[1000002];
stack<int>pila,pilai;
queue<int>cola;

void lectura(){
    cin>>N;
    for(i=1;i<=N;i++){
        cin>>A[i];
    }
}

void derecha(){
    pila.push(N);
    ext[N]=1;
    for(i=N-1;i>=1;i--){
        avance=1;
        while(! pila.empty() and A[pila.top()]%A[i]==0){
            avance+=ext[pila.top()];
            pila.pop();
        }
        ext[i]=avance;
        pila.push(i);
    }
}

void izquierda(){
    pilai.push(1);
    exti[1]=1;
    for(i=2;i<=N;i++){
        avance=1;
        while(! pilai.empty() and A[pilai.top()]%A[i]==0){
            avance+=exti[pilai.top()];
            pilai.pop();
        }
        exti[i]=avance;
        pilai.push(i);
    }
}

void operaciones(){
    mayor=-1;
    for(i=1;i<=N;i++){
        if(ext[i]+exti[i]==mayor){
            cola.push(i);
        }else if(ext[i]+exti[i]>mayor){
            while(! cola.empty()) cola.pop();
            cola.push(i);
            mayor=ext[i]+exti[i];
        }
    }
}

void impresion(){
    ant=0;
    i=0; cont=1;
    while(!cola.empty()){
        if(ant!=(cola.front()-(exti[cola.front()]-1))){
            i++;
            ext[i]=(cola.front()-(exti[cola.front()]-1));
        }
        ant=(cola.front()-(exti[cola.front()]-1));
        cola.pop();
    }
    cout<<i<<" "<<(mayor-2)<<'\n';
    while(cont<=i){
        cout<<(ext[cont]-(exti[ext[cont]]-1))<<" ";
        cont++;
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    derecha();
    izquierda();
    operaciones();
    impresion();

    return 0;
}
/// xD