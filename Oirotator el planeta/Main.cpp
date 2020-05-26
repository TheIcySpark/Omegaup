#include <bits/stdc++.h>
using namespace std;
struct nodo{
    int f,c,p;
};
int f,c;
bool mapa[702][702][4];
bool visitados[702][702][4];
queue <nodo> cola;
int movs[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

void lectura(){
    cin>>f>>c;
    for(int i=1;i<f;i++){
        for(int j=1;j<=c;j++){
            string instrucciones;
            cin>>instrucciones;
            for(int aux=0;aux<=instrucciones.size()-1;aux++){
                if(instrucciones[aux]=='N') mapa[i][j][0]=true;
                else if(instrucciones[aux]=='E') mapa[i][j][1]=true;
                else if(instrucciones[aux]=='S') mapa[i][j][2]=true;
                else mapa[i][j][3]=true;
            }
        }
    }
    for(int j=1;j<=c-1;j++){
        string instrucciones;
        cin>>instrucciones;
        for(int aux=0;aux<=instrucciones.size()-1;aux++){
            if(instrucciones[aux]=='N') mapa[f][j][0]=true;
            else if(instrucciones[aux]=='E') mapa[f][j][1]=true;
            else if(instrucciones[aux]=='S') mapa[f][j][2]=true;
            else mapa[f][j][3]=true;
        }
    }
}

void posibles(nodo &actual){
    nodo copia;
    int aux;
    for(int i=0;i<=3;i++){
        copia=actual;
        if(mapa[copia.f][copia.c][i]){
            aux=(i+copia.p)%4;
            copia.f+=movs[aux][0];
            copia.c+=movs[aux][1];
            ///cout<<copia.f<<" "<<copia.c<<" "<<copia.p<<" "<<visitados[copia.f][copia.c][aux]<<endl;
            if(copia.f>=1 and copia.f<=f and copia.c>=1 and copia.c<=c and !visitados[copia.f][copia.c][copia.p%4]){
                visitados[copia.f][copia.c][copia.p%4]=true;
                copia.p++;
                cola.push(copia);
                ///cout<<copia.f<<" "<<copia.c<<" "<<aux<<endl;
            }
        }
    }
    ///cout<<endl;
}

void busqueda(){
    nodo actual;
    visitados[1][1][0]=true;
    actual.f=1; actual.c=1; actual.p=0;
    cola.push(actual);
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
       /// cout<<actual.f<<" "<<actual.c<<" "<<actual.p<<endl<<endl;
        if(actual.f==f and actual.c==c){
            cout<<actual.p<<'\n';
            return;
        }
        posibles(actual);
    }
    cout<<"#OirotatorSinFlechas"<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    busqueda();

    return 0;
}
/// xD
/***
**/