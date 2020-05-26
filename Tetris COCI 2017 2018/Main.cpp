#include <bits/stdc++.h>
using namespace std;
struct figura{
    int f1,f2,f3,f4,f5;
};
char mapa[12][12];
bool marcados[12][12];
int n,m;
figura tetris;
bool fig1(int i,int j){
    if(mapa[i][j+1]==mapa[i][j] and mapa[i+1][j]==mapa[i][j] and mapa[i+1][j+1]==mapa[i][j]){
        marcados[i][j+1]=true; marcados[i+1][j]=true; marcados[i+1][j+1]=true;
        return true;
    }
    return false;
}
bool fig2(int i,int j){
    if(mapa[i+1][j]==mapa[i][j] and mapa[i+2][j]==mapa[i][j] and mapa[i+3][j]==mapa[i][j]){
        marcados[i+1][j]=true; marcados[i+2][j]=true; marcados[i+3][j]=true;
        return true;
    }
    if(mapa[i][j+1]==mapa[i][j] and mapa[i][j+2]==mapa[i][j] and mapa[i][j+3]==mapa[i][j]){
        marcados[i][j+1]=true; marcados[i][j+2]=true; marcados[i][j+3]=true;
        return true;
    }
        return false;
}
bool fig3(int i,int j){
    if(mapa[i][j+1]==mapa[i][j] and mapa[i+1][j]==mapa[i][j] and mapa[i+1][j-1]==mapa[i][j]){
        marcados[i][j+1]=true; marcados[i+1][j]=true; marcados[i+1][j-1]=true;
        return true;
    }
    if(mapa[i+1][j]==mapa[i][j] and mapa[i+1][j+1]==mapa[i][j] and mapa[i+2][j+1]==mapa[i][j]){
        marcados[i+1][j]=true; marcados[i+1][j+1]=true; marcados[i+2][j+1]=true;
        return true;
    }
        return false;
}
bool fig4(int i,int j){
    if(mapa[i][j+1]==mapa[i][j] and mapa[i+1][j+1]==mapa[i][j] and mapa[i+1][j+2]==mapa[i][j]){
        marcados[i][j+1]=true; marcados[i+1][j+1]=true; marcados[i+1][j+2]=true;
        return true;
    }
    if(mapa[i+1][j]==mapa[i][j] and mapa[i+1][j-1]==mapa[i][j] and mapa[i+2][j-1]==mapa[i][j]){
        marcados[i+1][j]=true; marcados[i+1][j-1]=true; marcados[i+2][j-1]=true;
        return true;
    }
        return false;
}
void buscar(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mapa[i][j]!='.' and marcados[i][j]!=true){
                marcados[i][j]=true;
                if(fig1(i,j)) tetris.f1++;
                else if(fig2(i,j)) tetris.f2++;
                else if(fig3(i,j)) tetris.f3++;
                else if(fig4(i,j)) tetris.f4++;
                else tetris.f5++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mapa[i][j];
        }
    }
    buscar();
    cout<<tetris.f1<<'\n'<<tetris.f2<<'\n'<<tetris.f3<<'\n'<<tetris.f4<<'\n'<<tetris.f5/4<<'\n';

    return 0;
}
/// xD
/***
5 5
aabb.
aabb.
cccc.
aa.bb
aabb.

3 8
abbbcddd
aabcc.d.
a...c...
**/