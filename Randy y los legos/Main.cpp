#include <bits/stdc++.h>
using namespace std;
struct coo{
    int f,c;
};
int aux[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char mapa[2002][2002];
bool marcados[2002][2002];
int f,c;
int f1,f2,f3,f4,f5,f6;
queue<coo>cola;

void lectura(){
    cin>>f>>c;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++) {
            cin>>mapa[i][j];
            if(mapa[i][j]=='.') marcados[i][j]=true;
        }
    }
}

void identificar(int &y,int &x){
    int inter2,inter3,inter4;
    int cuantos;
    inter2=inter3=inter4=0;
    char letra=mapa[y][x];
    coo actual,copia;
    actual.f=y; actual.c=x;
    cola.push(actual);
    marcados[actual.f][actual.c]=true;
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
        for(int i=0;i<4;i++){
            copia=actual;
            copia.f+=aux[i][0];
            copia.c+=aux[i][1];
            if(!marcados[copia.f][copia.c] and mapa[copia.f][copia.c]==letra){
                cola.push(copia);
                marcados[copia.f][copia.c]=true;
            }
        }
        if((mapa[actual.f][actual.c+1]==letra or mapa[actual.f][actual.c-1]==letra)
        and (mapa[actual.f+1][actual.c]==letra or mapa[actual.f-1][actual.c]==letra)){
            cuantos=0;
            if(mapa[actual.f][actual.c+1]==letra) cuantos++;
            if(mapa[actual.f][actual.c-1]==letra) cuantos++;
            if(mapa[actual.f+1][actual.c]==letra) cuantos++;
            if(mapa[actual.f-1][actual.c]==letra) cuantos++;
            if(cuantos==2) inter2++;
            else if(cuantos==3) inter3++;
            else inter4++;
        }
    }
    if(inter2==1 and inter3==0 and inter4==0) f1++;
    else if(inter2==0 and inter3==1 and inter4==0) f2++;
    else if(inter2==0 and inter3==0 and inter4==1) f3++;
    else if(inter2==1 and inter3==1 and inter4==0) f4++;
    else if(inter2==2 and inter3==0 and inter4==0) f5++;
    else f6++;
}

void busqueda(){
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            if(!marcados[i][j]){
                identificar(i,j);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    f1=f2=f3=f4=f5=f6=0;
    busqueda();
    cout<<f1<<'\n';
    cout<<f2<<'\n';
    cout<<f3<<'\n';
    cout<<f4<<'\n';
    cout<<f5<<'\n';
    cout<<f6<<'\n';
    return 0;
}
/// xD