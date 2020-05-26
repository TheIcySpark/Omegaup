#include <bits/stdc++.h>
using namespace std;
int n,mayor;
int memo[102][102];
string buscar,palabra,mostrar;
int dp(int i,int j){
    if(i>buscar.size()-1 or j>buscar.size()-1) return 0;
    if(memo[i][j]==-1){
        for(int aux=j;aux<=palabra.size()-1;aux++){
            if(palabra[aux]==buscar[i]){
                return memo[i][j]=max(dp(i+1,j),dp(i+1,aux+1)+1);
            }
        }
        return memo[i][j]=dp(i+1,j);
    }
    return memo[i][j];
}
void inicializar(){
    for(int i=0;i<=buscar.size();i++){
        for(int j=0;j<=palabra.size();j++) memo[i][j]=-1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int posible;
    mayor=-1;
    cin>>buscar;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>palabra;
        inicializar();
        posible=dp(0,0);
        if(posible>mayor){
            mayor=posible;
            mostrar=palabra;
        }else if(posible==mayor){
            if(palabra.size()<mostrar.size()) mostrar=palabra;
        }
    }
    cout<<mostrar<<'\n';

    return 0;
}
/// xD
/***
**/