#include <bits/stdc++.h>
using namespace std;
struct nodo{
    int y1,x1,y2,x2,p;
};
int n;
queue<nodo>cola;
char mapa[42][42];
bool visitados[42][42][42][42];

void lectura(){
    nodo inicial;
    inicial.y1=0;
    inicial.p=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mapa[i][j];
            if(mapa[i][j]=='B'){
                if(inicial.y1==0){
                    inicial.y1=i; inicial.x1=j;
                }else{
                    inicial.y2=i; inicial.x2=j;
                }
                mapa[i][j]='.';
            }
        }
    }
    visitados[inicial.y1][inicial.x1][inicial.y2][inicial.x2]=1;
    cola.push(inicial);
}

bool fin(nodo r){
    if((mapa[r.y1][r.x1]=='A') or (mapa[r.y2][r.x2]=='A')) return true;
    return false;
}

bool vertical1(nodo r){
    if(mapa[r.y1+1][r.x1]!='#' and mapa[r.y1-1][r.x1]!='#'){
        if((r.y1+1==r.y2 and r.x1==r.x2) or (r.y1-1==r.y2 and r.x1==r.x2)){
            return false;
        }
        return true;
    }
    return false;
}

bool horizontal1(nodo r){
    if(mapa[r.y1][r.x1+1]!='#' and mapa[r.y1][r.x1-1]!='#'){
        if((r.y1==r.y2 and r.x1+1==r.x2) or (r.y1==r.y2 and r.x1-1==r.x2)){
            return false;
        }
        return true;
    }
    return false;
}

bool vertical2(nodo r){
    if(mapa[r.y2+1][r.x2]!='#' and mapa[r.y2-1][r.x2]!='#'){
        if((r.y1==r.y2+1 and r.x1==r.x2) or (r.y1==r.y2-1 and r.x1==r.x2)){
            return false;
        }
        return true;
    }
    return false;
}

bool horizontal2(nodo r){
    if(mapa[r.y2][r.x2+1]!='#' and mapa[r.y2][r.x2-1]!='#'){
        if((r.y1==r.y2 and r.x1==r.x2+1) or (r.y1==r.y2 and r.x1==r.x2-1)){
            return false;
        }
        return true;
    }
    return false;
}

bool valido(nodo r){
    if(!visitados[r.y1][r.x1][r.y2][r.x2]){
        visitados[r.y1][r.x1][r.y2][r.x2]=1;
        return true;
    }
    return false;
}

void arriba(int &cambio,int x,nodo &r){
    while(mapa[cambio][x]!='#'){
        if(r.y1==r.y2 and r.x1==r.x2) break;
        cambio--;
        if(mapa[cambio][x]=='A') return;
    }
    cambio++;
}

void abajo(int &cambio,int x,nodo &r){
    while(mapa[cambio][x]!='#'){
        if(r.y1==r.y2 and r.x1==r.x2) break;
        cambio++;
        if(mapa[cambio][x]=='A') return;
    }
    cambio--;
    ///cout<<"abajo "<<r.y1<<" "<<r.x1<<" "<<r.y2<<" "<<r.x2<<endl;
}

void derecha(int y,int &cambio,nodo &r){
    while(mapa[y][cambio]!='#'){
        if(r.y1==r.y2 and r.x1==r.x2) break;
        cambio++;
        if(mapa[y][cambio]=='A') return;
    }
    cambio--;
}

void izquierda(int y,int &cambio,nodo &r){
    while(mapa[y][cambio]!='#'){
        if(r.y1==r.y2 and r.x1==r.x2)break;
        cambio--;
        if(mapa[y][cambio]=='A') return;
    }
    cambio++;
    ///cout<<"izquierda "<<r.y1<<" "<<r.x1<<" "<<r.y2<<" "<<r.x2<<endl;
}

int busqueda(){
    nodo actual,copia;
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
        ///cout<<actual.y1<<" "<<actual.x1<<" "<<actual.y2<<" "<<actual.x2<<"    "<<actual.p<<endl;
        if(fin(actual))return actual.p;
        actual.p++;
        copia=actual;
        if(vertical1(copia)){
            arriba(copia.y1,copia.x1,copia);
            if(valido(copia)){
                cola.push(copia);
            }
            copia=actual;
            abajo(copia.y1,copia.x1,copia);
            if(valido(copia)){
                cola.push(copia);
            }
        }
        copia=actual;
        if(vertical2(copia)){
            arriba(copia.y2,copia.x2,copia);
            if(valido(copia)){
                cola.push(copia);
            }
            copia=actual;
            abajo(copia.y2,copia.x2,copia);
            if(valido(copia)){
                cola.push(copia);
            }
        }

        copia=actual;
        if(horizontal1(copia)){
            derecha(copia.y1,copia.x1,copia);
            if(valido(copia)){
                cola.push(copia);
            }
            copia=actual;
            izquierda(copia.y1,copia.x1,copia);
            if(valido(copia)){
                cola.push(copia);
            }
        }
        copia=actual;
        if(horizontal2(copia)){
            derecha(copia.y2,copia.x2,copia);
            if(valido(copia)){
                cola.push(copia);
            }
            copia=actual;
            izquierda(copia.y2,copia.x2,copia);
            if(valido(copia)){
                cola.push(copia);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    cout<<busqueda()<<'\n';


    return 0;
}
/// xD
/***
**/