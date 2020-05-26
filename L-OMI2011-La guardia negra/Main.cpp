#include <bits/stdc++.h>
using namespace std;
long long int prec[1002][1002];

long long int alcance(int f,int c,int d){
    long long int ret=0;
    int resta=1;
    int fila=f-d;
    int columna=c;
    while(fila!=f){
        ret+=(prec[fila][columna]-prec[fila][columna-resta]);
        columna++; resta+=2; fila++;
    }
    fila=f+d;
    resta=1;
    columna=c;
    while(fila!=f){
        ret+=(prec[fila][columna]-prec[fila][columna-resta]);
        columna++; resta+=2; fila--;
    }
    return ret;
}

long long int muertos(int f,int c,int d){
    long long int suma=0;
    int resta=d+1;
    suma+=(prec[f][c+d]-prec[f][c-resta]);
    suma+=alcance(f,c,d);
    return suma;
}

void lectura_calculo(){
    int f,c,p;
    cin>>f>>c;
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            int num;
            cin>>num;
            prec[i][j]=prec[i][j-1]+num;
        }
    }
    cin>>p;
    for(int i=1;i<=p;i++){
        int fm,cm,dm;
        cin>>fm>>cm>>dm;
        cout<<muertos(fm,cm,dm)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura_calculo();

    return 0;
}
/// xD
/***
7 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1
5 3 1
**/