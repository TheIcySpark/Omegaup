#include <bits/stdc++.h>
using namespace std;
struct estado{
    int f,c;
    int gaso;
};
estado ini,actual,nuevo;
string mapa[12];
int visitados[12][12];
queue<estado>cola;
int i,j,gasolina,validos;
void leer(){
    string lectura;
    ini.gaso=0;
    i=0;
    while(lectura!="#"){
        i++;
        cin>>lectura;
        mapa[i]=" ";
        mapa[i]+=lectura;
        j=0;
        while(j<lectura.length()){
            if(mapa[i][j]=='S'){
                ini.f=i; ini.c=j;
            }
            j++;
        }
    }
    cin>>gasolina;
    cola.push(ini);
    visitados[ini.f][ini.c]=7;
}
void arriba(){
    nuevo.f--;
    if(visitados[nuevo.f][nuevo.c]!=7 and (mapa[nuevo.f][nuevo.c]=='+' or mapa[nuevo.f][nuevo.c]=='|')){
        visitados[nuevo.f][nuevo.c]=7;
        validos++;
        cola.push(nuevo);
    }
}
void derecha(){
    nuevo.c++;
    if(visitados[nuevo.f][nuevo.c]!=7 and (mapa[nuevo.f][nuevo.c]=='+' or mapa[nuevo.f][nuevo.c]=='-')){
        visitados[nuevo.f][nuevo.c]=7;
        validos++;
        cola.push(nuevo);
    }
}
void abajo(){
    nuevo.f++;
    if(visitados[nuevo.f][nuevo.c]!=7 and (mapa[nuevo.f][nuevo.c]=='+' or mapa[nuevo.f][nuevo.c]=='|')){
        visitados[nuevo.f][nuevo.c]=7;
        validos++;
        cola.push(nuevo);
    }
}
void izquierda(){
    nuevo.c--;
    if(visitados[nuevo.f][nuevo.c]!=7 and (mapa[nuevo.f][nuevo.c]=='+' or mapa[nuevo.f][nuevo.c]=='-')){
        visitados[nuevo.f][nuevo.c]=7;
        validos++;
        cola.push(nuevo);
    }
}
void busqueda(){
    actual.gaso++;
    nuevo=actual;
    if(actual.gaso<=gasolina){
        if(mapa[nuevo.f][nuevo.c]=='S' or mapa[nuevo.f][nuevo.c]=='+'){
            nuevo=actual; arriba();
            nuevo=actual; derecha();
            nuevo=actual; abajo();
            nuevo=actual; izquierda();
        }else if(mapa[nuevo.f][nuevo.c]=='-'){
            nuevo=actual; derecha();
            nuevo=actual; izquierda();
        }else if(mapa[nuevo.f][nuevo.c]=='|'){
            nuevo=actual; arriba();
            nuevo=actual; abajo();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    leer();
    validos=1;
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
        busqueda();
    }
    cout<<validos<<'\n';

    return 0;
}
/// xD