#include <bits/stdc++.h>
using namespace std;
string ciudad;
string solution;
int cubeta[256];
int n,m;

void Lectura(){
    cin>>n>>m;
    cin>>ciudad;
}

int buscar(int ini,int fin){
    char menor=ciudad[ini];
    int pos=ini;
    for(int i=ini;i<=fin;i++){
        if(ciudad[i]<=menor){
            menor=ciudad[i];
            pos=i;
        }
    }
    return pos;
}

void Calculo(){
    int ini=0, fin=m-1, pos=-1;
    solution="";
    while(fin<n){
        if(pos<ini){
            pos=buscar(ini,fin);
            solution+=ciudad[pos];
        }else{
            if(ciudad[fin]<ciudad[pos]){
                pos=fin;
                solution+=ciudad[pos];
            }
        }
        cubeta[ciudad[ini]]++;
        ini++; fin++;
    }
    while(ini<n){
      cubeta[ciudad[ini]]++;
      ini++;
    }
}

void Imprimir(){
    char ultimo=solution[0];
    int cuantos=1, tope=solution.size();
    for(int i=1;i<tope;i++){
        if(solution[i]>ultimo){
            ultimo=solution[i];
            cuantos=1;
        }else if(solution[i]==ultimo) cuantos++;
    }
    for(int i='a';i<ultimo;i++){
        for(int j=1;j<=cubeta[i];j++) cout<<char(i);
    }
    for(int i=1;i<=cuantos;i++) cout<<ultimo;
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    Lectura();
    Calculo();
    Imprimir();

    return 0;
}
/// xD