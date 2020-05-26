#include <bits/stdc++.h>
using namespace std;
int f,c,fi,co;
int tablero[202][202];
int filas[1002];
int columnas[1002];

void lectura(){
    cin>>f>>c;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            cin>>tablero[i][j];
        }
    }
}

void sumatoria(){
    int pos,neg;
    for(int i=1;i<=f;i++){
        pos=0;
        neg=0;
        for(int j=1;j<=c;j++){
            if(tablero[i][j]>0) pos+=tablero[i][j];
            else neg+=tablero[i][j];
        }
        tablero[i][c+2]=pos; tablero[i][c+3]=neg;
    }
    pos=0;
    neg=0;
    for(int i=1;i<=c;i++){
        pos=0;
        neg=0;
        for(int j=1;j<=f;j++){
            if(tablero[j][i]>0) pos+=tablero[j][i];
            else neg+=tablero[j][i];
        }
        tablero[f+2][i]=pos; tablero[f+3][i]=neg;
    }
}

void cambio_columnas(int &cual_fila){
    for(int j=1;j<=c;j++){
        if(tablero[cual_fila][j]>=0){
            tablero[f+2][j]-=tablero[cual_fila][j];
            tablero[cual_fila][j]*=-1;
            tablero[f+3][j]+=tablero[cual_fila][j];
        }else{
            tablero[f+3][j]-=tablero[cual_fila][j];
            tablero[cual_fila][j]*=-1;
            tablero[f+2][j]+=tablero[cual_fila][j];
        }
    }
}

void cambio_filas(int &cual_columna){
    for(int i=1;i<=f;i++){
        if(tablero[i][cual_columna]>=0){
            tablero[i][c+2]-=tablero[i][cual_columna];
            tablero[i][cual_columna]*=-1;
            tablero[i][c+3]+=tablero[i][cual_columna];
        }else{
            tablero[i][c+2]-=tablero[i][cual_columna];
            tablero[i][cual_columna]*=-1;
            tablero[i][c+3]+=tablero[i][cual_columna];
        }
    }
}

void acomodo(){
    bool perfecto=false;
    fi=0; co=0;
    while(!perfecto){
        perfecto=true;
        for(int i=1;i<=f;i++){
            if(tablero[i][c+2]<abs(tablero[i][c+3])){
                fi++;
                filas[fi]=i;
                swap(tablero[i][c+2],tablero[i][c+3]);
                tablero[i][c+2]*=-1;
                tablero[i][c+3]*=-1;
                cambio_columnas(i);
            }
        }
        for(int j=1;j<=c;j++){
            if(tablero[f+2][j]<abs(tablero[f+3][j])){
                ///cout<<tablero[f+2][j]<<" "<<abs(tablero[f+3][j])<<endl;
                perfecto=false;
                co++;
                columnas[co]=j;
                swap(tablero[f+2][j],tablero[f+3][j]);
                tablero[f+2][j]*=-1;
                tablero[f+3][j]*=-1;
                cambio_filas(j);
            }
        }
    }
}

void mostrar(){
    cout<<fi<<" ";
    for(int i=1;i<=fi;i++){
        cout<<filas[i]<<" ";
    }
    cout<<'\n';
    cout<<co<<" ";
    for(int i=1;i<=co;i++){
        cout<<columnas[i]<<" ";
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    sumatoria();
    acomodo();
    mostrar();

    return 0;
}
/// xD