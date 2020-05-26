#include <bits/stdc++.h>
using namespace std;
int memo[1002][1002];
string buscar,palabra;
int dp(int i,int j){
    if(i<0 or j<0) return 0;
    if(memo[i][j]==-1){
        for(int aux=j;aux>=0;aux--){
            if(palabra[aux]==buscar[i]){
                return memo[i][j]=max(dp(i-1,j),dp(i-1,aux-1)+1);
            }
        }
        return memo[i][j]=dp(i-1,j);
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
    cin>>buscar;
    cin>>palabra;
  	inicializar();
  	cout<<dp(buscar.size()-1,palabra.size()-1)<<'\n';
    return 0;
}
/// xD
/***
**/