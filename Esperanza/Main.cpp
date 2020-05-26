#include <bits/stdc++.h>
using namespace std;
struct pos{
    int f,c;
    const bool operator<(const pos &otro)const{
        if(f==otro.f) return c<otro.c;
        else return f<otro.f;
    }
};
bool rev=false;
int n,cuant;
pos ruta[1000002];
pos inv[3000002];
bool reversa(char &a,char &b){
    if((a=='U' and b=='D') or (a=='R' and b=='L') or (a=='D' and b=='U') or (a=='L' and b=='R')) return true;
    else return false;
}
bool busqueda(pos &actual){
    int ini,fin,m;
    ini=1; fin=cuant;
    while(ini<=fin){
        m=(ini+fin)/2;
        if(inv[m].f==actual.f){
            if(inv[m].c==actual.c) return true;
            else if(inv[m].c<actual.c) ini=m+1;
            else fin=m-1;
        }else if(inv[m].f<actual.f) ini=m+1;
        else fin=m-1;
    }
    return false;
}

bool mejor_ruta(){
    for(int i=1;i<=n+1;i++){
        if(busqueda(ruta[i])) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ruta[1].f=1; ruta[1].c=1;
    ruta[2]=ruta[1];
    char ant;
    cin>>n;
    cin>>ant;
    if(ant=='U'){
        inv[1].f=1; inv[1].c=2;
        inv[2].f=0; inv[2].c=1;
        inv[3].f=1; inv[3].c=0;
        ruta[2].f++;
    }else if(ant=='R'){
        inv[1].f=0; inv[1].c=1;
        inv[2].f=1; inv[2].c=0;
        inv[3].f=2; inv[3].c=1;
        ruta[2].c++;
    }else if(ant=='D'){
        inv[1].f=1; inv[1].c=0;
        inv[2].f=2; inv[2].c=1;
        inv[3].f=1; inv[3].c=2;
        ruta[2].f--;
    }else{
        inv[1].f=2; inv[1].c=1;
        inv[2].f=1; inv[2].c=2;
        inv[3].f=0; inv[3].c=1;
        ruta[2].c--;
    }
    cuant=3;
    for(int i=2;i<=n;i++){
        char sig;
        cin>>sig;
        ruta[i+1]=ruta[i];
        if(sig=='U') ruta[i+1].f++;
        else if(sig=='R') ruta[i+1].c++;
        else if(sig=='D') ruta[i+1].f--;
        else ruta[i+1].c--;
        if(reversa(ant,sig)) rev=true;
        inv[cuant+1]=ruta[i];
        if(ant!='D' and sig!='U'){
            cuant++; inv[cuant].f++; inv[cuant+1]=ruta[i];
        }
        if(ant!='L' and sig!='R'){
            cuant++; inv[cuant].c++; inv[cuant+1]=ruta[i];
        }
        if(ant!='U' and sig!='D'){
            cuant++; inv[cuant].f--; inv[cuant+1]=ruta[i];
        }
        if(ant!='R' and sig!='L'){
            cuant++; inv[cuant].c--; inv[cuant+1]=ruta[i];
        }
        ant=sig;
    }
    sort(inv+1,inv+cuant+1);
    if(!rev and mejor_ruta()) cout<<'S'<<'\n';
    else cout<<'N'<<'\n';

    return 0;
}
/// xD
/***
**/