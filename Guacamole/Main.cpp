#include <bits/stdc++.h>
using namespace std;
int movs[9][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{0,0}};
int f,c,t;
long long int mayor=LONG_MIN;
int inicial[102][102];
int repetir[102][102];
long long int memo[102][102][502];
long long int puntos[102][102];

void lectura(){
    cin>>f>>c>>t;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            cin>>inicial[i][j];
        }
    }
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            cin>>repetir[i][j];
        }
    }
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            cin>>puntos[i][j];
        }
    }
}

void inicializacion(){
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            for(int z=1;z<=t;z++){
                memo[i][j][z]=LONG_MIN;
            }
        }
    }
}

long long int dp(int fila,int columna,int seg){
    if(fila>f or fila<1 or columna>c or columna<1) return INT_MIN;
    if(seg>t) return 0;
    if((seg>inicial[fila][columna] and (seg-inicial[fila][columna])%repetir[fila][columna]==0) or (seg==inicial[fila][columna])){
        if(memo[fila][columna][seg]==LONG_MIN){
            long long int posible=LONG_MIN;
            for(int i=0;i<9;i++){
                posible=max(posible,dp(fila+movs[i][0],columna+movs[i][1],seg+1)+puntos[fila][columna]);
            }
            if(posible!=LONG_MIN) memo[fila][columna][seg]=posible;
        }
    }else if(memo[fila][columna][seg]==LONG_MIN){
        long long int posible=LONG_MIN;
        for(int i=0;i<9;i++){
            posible=max(posible,dp(fila+movs[i][0],columna+movs[i][1],seg+1));
        }
        if(posible!=LONG_MIN) memo[fila][columna][seg]=posible;
    }
    return memo[fila][columna][seg];
}


void recorrido(){
    long long int aux;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            aux=dp(i,j,1);
            if(aux>mayor)mayor=aux;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    inicializacion();
    recorrido();
    cout<<mayor<<'\n';

    return 0;
}
/// xD