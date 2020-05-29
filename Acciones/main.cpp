#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long int accion[34],maxSuma=0,objetivo,maxCercano;
vector<vector<long long int> >a(34), b(34);

long long int MaxValido(long long int a,long long int b){
    if(a>objetivo and b>objetivo) return 0;
    if(a>objetivo or b>objetivo) return min(a,b);
    return max(a,b);
}

long long int Sumatoria(int ini,int fin){
    long long int s=0;
    for(int i=ini;i<=fin;i++){
        s+=accion[i];
    }
    return s;
}

void Lectura(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>accion[i];
        maxSuma+=accion[i];
    }
    objetivo=maxSuma/2;
    sort(accion+1,accion+n+1);
}

void GenerarPosibles(long long int s,int pos, int pasos,int limite,vector<vector<long long int> > &v){
    if(pasos>=n/2) return;
    if(s<=objetivo) v[pasos].push_back(s);
    else return;
    for(int i=pos;i<=limite;i++) GenerarPosibles(s+accion[i], i+1, pasos+1,limite, v);
}

void Ordenar(vector<vector<long long int> > &v){
    for(int i=1;i<n;i++){
        if(!v[i].empty()) sort(v[i].begin(),v[i].end());
    }
}

void Binaria(){
    int ini,fin,m;
    for(int i=1;i<n/2;i++){
        for(int j=0;j<a[i].size();j++){
            if(b[n/2-i].empty()) break;
            ini=0; fin=b[n/2-i].size()-1;
            while(ini<fin){
                m=(ini+fin)/2+1;
                if(a[i][j]+b[n/2-i][m]<=objetivo) ini=m;
                else fin=m-1;
            }
            //cout<<a[i][j]+b[n/2-i][ini]<<endl;
            maxCercano=MaxValido(maxCercano, a[i][j]+b[n/2-i][ini]);
        }
    }
}

int main() {
    Lectura();
    maxCercano=MaxValido(Sumatoria(1,n/2), Sumatoria(n/2, n));
    for(int i=1;i<=n/2;i++) GenerarPosibles(accion[i], i+1, 1,n/2, a);
    for(int i=n/2+1;i<=n;i++) GenerarPosibles(accion[i], i+1, 1, n, b);
    Ordenar(a);
    Ordenar(b);
    Binaria();
    cout<<(maxSuma-maxCercano)-maxCercano<<'\n';

    return 0;
}
/// xD Meet in the middle
/**
6
1 7 20 25 37 50
out: 2
8
1 7 20 25 37 50 70 90
out: 4
**/