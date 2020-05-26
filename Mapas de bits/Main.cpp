#include <bits/stdc++.h>
using namespace std;
int f,c;
char trans;
int mapa[2002][2002];
bool des[2002][2002];

void profundisar(int izq,int der,int alto,int bajo){
    char operacion;
    cin>>operacion;
    if(operacion=='1' or operacion=='0'){
        operacion-=48;
        int i,j;
        for(i=alto;i<=bajo;i++){
            for(j=izq;j<=der;j++){
                mapa[i][j]=operacion;
            }
        }
        return;
    }
    if(izq==der){
        profundisar(izq,der,alto,(alto+bajo)/2);
        profundisar(izq,der,(alto+bajo)/2+1,bajo);
        return;
    }
    if(alto==bajo){
        profundisar(izq,(izq+der)/2,alto,bajo);
        profundisar((izq+der)/2+1,der,alto,bajo);
        return;
    }
    profundisar(izq,(izq+der)/2,alto,(alto+bajo)/2);
    profundisar((izq+der)/2+1,der,alto,(alto+bajo)/2);
    profundisar(izq,(izq+der)/2,(alto+bajo)/2+1,bajo);
    profundisar((izq+der)/2+1,der,(alto+bajo)/2+1,bajo);
}

void lectura(){
    cin>>trans>>f>>c;
    if(trans=='B'){
        for(int i=1;i<=f;i++){
            for(int j=1;j<=c;j++){
                char numero;
                cin>>numero;
                mapa[i][j]=mapa[i][j-1]+(numero-48);
            }
        }
    }else profundisar(1,c,1,f);
}

void dividir_vence(int izq,int der,int alto,int bajo){
    if(izq==der){
        if(alto==bajo){
            cout<<mapa[alto][izq]-mapa[alto][izq-1];
            return;
        }
        int comparar=mapa[alto][izq]-mapa[alto][izq-1];
        for(int i=alto+1;i<=bajo;i++){
            if(mapa[i][izq]-mapa[i][izq-1]!=comparar){
                cout<<'D';
                dividir_vence(izq,der,alto,(alto+bajo)/2);
                dividir_vence(izq,der,(alto+bajo)/2+1,bajo);
                return;
            }
        }
        cout<<mapa[alto][izq]-mapa[alto][izq-1];
        return;
    }
    if(alto==bajo){
        int comparar=mapa[alto][izq]-mapa[alto][izq-1];
        if(comparar==1) comparar=der-izq+1;
        if(mapa[alto][der]-mapa[alto][izq-1]!=comparar){
            cout<<'D';
            dividir_vence(izq,(izq+der)/2,alto,bajo);
            dividir_vence((izq+der)/2+1,der,alto,bajo);
            return;
        }
        cout<<mapa[alto][izq]-mapa[alto][izq-1];
        return;
    }
    bool dividimos=false;
    int comparar=mapa[alto][izq]-mapa[alto][izq-1];
    if(comparar==1) comparar=der-izq+1;
    for(int i=alto;i<=bajo;i++){
        if(mapa[i][der]-mapa[i][izq-1]!=comparar){
            dividimos=true;
            cout<<'D';
            dividir_vence(izq,(izq+der)/2,alto,(alto+bajo)/2);
            dividir_vence((izq+der)/2+1,der,alto,(alto+bajo)/2);
            dividir_vence(izq,(izq+der)/2,(alto+bajo)/2+1,bajo);
            dividir_vence((izq+der)/2+1,der,(alto+bajo)/2+1,bajo);
            break;
        }
    }
    if(!dividimos) cout<<mapa[alto][izq]-mapa[alto][izq-1];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    if(trans=='B'){
        cout<<'D'<<" "<<f<<" "<<c<<'\n';
        dividir_vence(1,c,1,f);
        cout<<'\n';
    }else{
        cout<<'B'<<" "<<f<<" "<<c<<'\n';
        for(int i=1;i<=f;i++){
            for(int j=1;j<=c;j++){
                cout<<mapa[i][j];
            }
        }
        cout<<'\n';
    }

    return 0;
}
/// xD
/***
***/