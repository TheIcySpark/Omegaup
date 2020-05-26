#include <bits/stdc++.h>
using namespace std;
int ren,col,r,c;
int matriz[1002][1002];
int submatriz[1002][1002];
bool k[1002][1002];
void lectura(){
    cin>>ren>>col;
    for(int i=1;i<=ren;i++){
        for(int j=1;j<=col;j++){
            cin>>matriz[i][j];
        }
    }
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>submatriz[i][j];
        }
    }
}

bool revisar(int r1,int c1){
    int copia=c1;
    for(int i=1;i<=r;i++){
        c1=copia;
        for(int j=1;j<=c;j++){
            if(matriz[r1][c1]!=submatriz[i][j]) return false;
            c1++;
        }
        r1++;
    }
    return true;
}
void marcar(int r1,int c1){
    for(int i=r1;i<=r+r1-1;i++){
        for(int j=c1;j<=c+c1-1;j++){
            k[i][j]=1;
        }
    }
}

void cuantas(){
    int r1,c1,r2,c2;
    r1=1; r2=r;
    while(r2<=ren){
        c2=c; c1=1;
        while(c2<=col){
            if(matriz[r1][c1]==submatriz[1][1]){
                if(revisar(r1,c1)){
                    marcar(r1,c1);
                }
            }
            c2++; c1++;
        }
        r2++; r1++;
    }
}

void mostrar(){
    for(int i=1;i<=ren;i++){
        for(int j=1;j<=col;j++){
            cout<<k[i][j]<<" ";
        }
        cout<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    cuantas();
    mostrar();

    return 0;
}
/// xD
/***
5 5
1 2 3 4 5
6 7 8 1 2
3 4 1 2 1
1 2 3 1 2
7 1 2 1 2
1 2
1 2
**/