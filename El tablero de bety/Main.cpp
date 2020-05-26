#include <bits/stdc++.h>
using namespace std;
int up,down,iz,de,operacion,i,k,f,c,j,cont,a,b;
int tablero[102][102],copia[102][102];

void leer_operaciones(){
    for(i=1;i<=k;i++){
        cin>>operacion;
        if(operacion==1) up++;
        if(operacion==2) down++;
        if(operacion==3) iz++;
        if(operacion==4) de++;
    }
    up=up%f;
    down=down%f;
    iz=iz%c;
    de=de%c;
}

void leer_tablero(){
    for(i=1;i<=f;i++){
        for(j=1;j<=c;j++){
            cin>>tablero[i][j];
            copia[i][j]=tablero[i][j];
        }
    }
}

void cambio(){
    if(up-down>0 or down-up>0){
        if(up>down){
            up=up-down%f;
            i=1+up;
            cont=i;
            for(a=1;i<=f;i++,a++){
                for(j=1,b=1;j<=c;j++,b++){
                    copia[a][b]=tablero[i][j];
                }
            }
            for(i=1;i<=cont;i++,a++){
                for(j=1,b=1;j<=c;j++,b++){
                    copia[a][b]=tablero[i][j];
                }
            }
        }else{
            if(down-up>0){
                down-=up%f;
                i=f-down+1;
                for(a=1;i<=f;i++,a++){
                    for(j=1,b=1;j<=c;j++,b++){
                        copia[a][b]=tablero[i][j];
                    }
                }
                for(i=1;i<=f-down;i++,a++){
                    for(j=1,b=1;j<=c;j++,b++){
                        copia[a][b]=tablero[i][j];
                    }
                }
            }
        }
    }
    for(i=1;i<=f;i++){
        for(j=1;j<=c;j++){
            tablero[i][j]=copia[i][j];
        }
    }
    if(iz-de>0 or de-iz>0){
        if(iz>de){
            iz-=de%c;
            i=iz+1;
            for(b=1;i<=c;i++,b++){
                for(a=1,j=1;j<=f;j++,a++){
                    copia[a][b]=tablero[j][i];
                }
            }
            for(i=1;i<=iz;i++,b++){
                for(a=1,j=1;j<=f;j++,a++){
                    copia[a][b]=tablero[j][i];
                }
            }
        }else{
            if(de-iz>0){
                de-=iz%c;
                i=c-de+1;
                for(b=1;i<=c;i++,b++){
                    for(a=1,j=1;j<=f;j++,a++){
                        copia[a][b]=tablero[j][i];
                    }
                }
                i=1;
                for(;i<c-de+1;i++,b++){
                    for(a=1,j=1;j<=f;j++,a++){
                        copia[a][b]=tablero[j][i];
                    }
                }
            }
        }
    }
    for(i=1;i<=f;i++){
        for(j=1;j<=c;j++){
            cout<<copia[i][j]<<" ";
        }
        cout<<'\n';
    }
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>f>>c>>k;
    leer_operaciones();
    leer_tablero();
    cambio();

    return 0;
}
/// XD
/***
3 3 4
1 2 3 4
1 2 3
4 5 6
7 8 9
***/