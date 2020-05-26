#include "tesoro.h"
#include "bits/stdc++.h"
using namespace std;
struct coordenada{
    int ini,fin,tesoros;
};
stack<coordenada>pila;
coordenada actual,copia;
int izquierda,derecha,mitad,N,M,K;
int encontrados[1002];

// Main
//	int Preguntar(int i, int j)
//	bool Cavar(int i, int j)

void busqueda_vertical(){
    int ini,fin,preg;
    ini=1; fin=N;
    while(ini<fin){
        mitad=(ini+fin)/2;
        preg=Preguntar(mitad,actual.fin)-encontrados[mitad];
        if(preg==0){
            ini=mitad+1;
        }else{
            fin=mitad;
        }
    }
    Cavar(ini,actual.ini);
    for(int i=ini;i<=N;i++) encontrados[i]++;
}

void busqueda_horizontal(){
    mitad=(actual.ini+actual.fin)/2;
    izquierda=Preguntar(N,mitad)-encontrados[N];
    derecha=abs(izquierda-actual.tesoros);
    if(derecha>0){
        copia=actual;
        copia.ini=mitad+1;
        copia.tesoros=derecha;
        pila.push(copia);
    }
    if(izquierda>0){
        copia=actual;
        copia.fin=mitad;
        copia.tesoros=izquierda;
        pila.push(copia);
    }
}

void BuscaTesoros(int n, int m, int k) {
    N=n; M=m; K=k;
    actual.ini=1; actual.fin=m; actual.tesoros=k;
    if(k>0) pila.push(actual);
    while(!pila.empty()){
        actual=pila.top(); pila.pop();
        if(actual.ini==actual.fin) busqueda_vertical();
        else busqueda_horizontal();
    }
}
/// xD
/**
**/