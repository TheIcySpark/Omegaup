#include <bits/stdc++.h>
using namespace std;
char actual[2002][2002];
char correcto[2002][2002];
char copiaA[8002];
char copiaC[8002];
int tam;
int n;
void lectura(void){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>actual[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>correcto[i][j];
        }
    }
}

void crear(int &ini,int &fin){
    int siguiente=0;
    for(int i=ini;i<=fin;i++){
        siguiente++;
        copiaA[siguiente]=actual[ini][i];
        copiaC[siguiente]=correcto[ini][i];
    }
    for(int i=ini+1;i<=fin;i++){
        siguiente++;
        copiaA[siguiente]=actual[i][fin];
        copiaC[siguiente]=correcto[i][fin];
    }
    for(int i=fin-1;i>=ini;i--){
        siguiente++;
        copiaA[siguiente]=actual[fin][i];
        copiaC[siguiente]=correcto[fin][i];
    }
    for(int i=fin-1;i>=ini+1;i--){
        siguiente++;
        copiaA[siguiente]=actual[i][ini];
        copiaC[siguiente]=correcto[i][ini];
    }
}

int contar(int &ini,int &fin){
    int ret=0,a=1,c=1,ret2=0;
    tam=((fin-ini+1)*(fin-ini+1))-((fin-1-ini)*(fin-1-ini));
    crear(ini,fin);
    while(a<=tam){
        if(copiaA[a]!=copiaC[c]){
            ret++;
            c++;
        }else{
            a++;
            c++;
        }
        if(c>tam) c=1;
    }
    a=tam; c=tam;
    while(a>=1){
        if(copiaA[a]!=copiaC[c]){
            ret2++;
            c--;
        }else{
            a--;
            c--;
        }
        if(c<1) c=tam;
    }
    ret2=min(ret2,tam-ret2);
    ret= min(ret,tam-ret);
    return min(ret,ret2);
}

long long int calcular(void){
    long long int ret=0;
    int ini=1, fin=n;
    while(ini<fin){
        ret+=contar(ini,fin);
        ini++; fin--;
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    cout<<calcular();

    return 0;
}
/// xD
/**
4
abcd
babc
cbab
dcba

babc
cabd
dbac
cbab

4
abcd
babc
cbab
dcba

bcdc
aabb
bbaa
cdcb
**/