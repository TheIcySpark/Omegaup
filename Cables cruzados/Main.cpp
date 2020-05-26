#include "CablesCruzados.h"
#include "bits/stdc++.h"
using namespace std;
// Main
//	bool RespuestaSublista(int desde, int hasta, int cruces)
int arreglo[1000005];
int trabajo[1000005];

long long int dividir(int ini,int fin){
    if(ini==fin) return 0;
    long long int izq,der;
    izq=dividir(ini,(ini+fin)/2);
    der=dividir((ini+fin)/2+1,fin);
    int IZQ,DER,sig;
    long long int cont;
    cont=0;
    sig=ini;
    IZQ=ini;
    DER=(ini+fin)/2+1;
    while(IZQ<=(ini+fin)/2 and DER<=fin){
        if(arreglo[IZQ]>arreglo[DER]){
            cont+=(ini+fin)/2-IZQ+1;
            trabajo[sig]=arreglo[DER];
            DER++;
        }else{
            trabajo[sig]=arreglo[IZQ];
            IZQ++;
        }
        sig++;
    }
     while(IZQ<=(ini+fin)/2){
        trabajo[sig]=arreglo[IZQ];
        IZQ++;
        sig++;
     }
     while(DER<=fin){
        trabajo[sig]=arreglo[DER];
        DER++;
        sig++;
     }
     for(int i=ini;i<=fin;i++){
        arreglo[i]=trabajo[i];
     }
     cont+=izq+der;
     RespuestaSublista(ini,fin,cont);
     return cont;
}

void ContarCruces(int n, int Lista[]) {
	for(int i=0;i<n;i++) arreglo[i]=Lista[i];
	dividir(0,n-1);
}
/// xD