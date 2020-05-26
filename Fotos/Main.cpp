#include <bits/stdc++.h>
using namespace std;
struct zona{
    long long int f,c;
};
zona interes[22];
long long int f,c,r,i,j,zi,a,cont,suma,menor;
long long int fotos[250002];
char mapa[502][502];

void lectura(){
    cin>>f>>c>>r;
    zi=0;
    for(i=1;i<=f;i++){
        for(j=1;j<=c;j++){
            cin>>mapa[i][j];
            if(mapa[i][j]=='*'){
                zi++;
                interes[zi].f=i;
                interes[zi].c=j;
            }
        }
    }
}

void relleno(){
    cont=1;
    for(i=1;i<=f;i++){
        for(j=1;j<=c;j++){
            for(a=1;a<=zi;a++){
                fotos[cont]+=1000-((max(i,interes[a].f)-min(i,interes[a].f))+(max(j,interes[a].c)-min(j,interes[a].c)));
            }
            cont++;
        }
        i++;
        if(i>f) break;
        for(j=c;j>=1;j--){
            for(a=1;a<=zi;a++){
                fotos[cont]+=1000-((max(i,interes[a].f)-min(i,interes[a].f))+(max(j,interes[a].c)-min(j,interes[a].c)));
            }
            cont++;
        }
    }
}

bool rango(long long int m){
    long long int rollos;
    rollos=r;
    suma=0; i=1;
    while(i<=cont and rollos>=1){
        if(suma+fotos[i]<=m){
            suma+=fotos[i];
            i++;
        }else{
            rollos--; suma=0;
        }
    }
    if(rollos>=1) return true;
    else return false;
}

long long int binaria(long long int ini,long long int fin){
    long long int m;
    bool ra;
    m=(ini+fin)/2;
    ra=rango(m);
    if(ini>fin){
        return menor;
    }
    if(ra==true){
        menor=m;
        return binaria(ini,m-1);
    }else{
        return binaria(m+1,fin);
    }
}

long long int caso1(){
    for(i=1;i<=cont;i++){
        suma+=fotos[i];
    }
    return suma;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    relleno();
    cont--;
    if(r==1) cout<<caso1()<<'\n';
    else cout<<binaria(1,5500000000000000000)<<'\n';

    return 0;
}