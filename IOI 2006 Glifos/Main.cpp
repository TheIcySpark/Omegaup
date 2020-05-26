#include <bits/stdc++.h>
using namespace std;
struct letras{
    int v,l;
};
vector<letras> cubeta(123);
int g,n,i,cont,referencia,ini;
char palabras[3000002];
char p;

void lectura(){
    cin>>g>>n;
    for(i=1;i<=g;i++){
        cin>>p;
        cubeta[p].v++; cubeta[p].l++;
    }
    referencia=g;
    for(i=1;i<=g;i++){
        cin>>palabras[i];
        if(cubeta[palabras[i]].l>=1){
            cubeta[palabras[i]].v--;
            if(cubeta[palabras[i]].v>=0) referencia--;
        }
    }
}

void calculo(){
    if(referencia==0) cont++;
    ini=1;
    for(;i<=n;i++){
        cin>>palabras[i];
        if(cubeta[palabras[ini]].l> cubeta[palabras[ini]].v){
            cubeta[palabras[ini]].v++;
            if(cubeta[palabras[ini]].v>=1) referencia++;
        }
        if(cubeta[palabras[i]].l>=1){
            cubeta[palabras[i]].v--;
            if(cubeta[palabras[i]].v>=0) referencia--;
        }
        if(referencia==0) cont++;
        ini++;
    }
    cout<<cont<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    calculo();

    return 0;
}
/// XD
/***
3 12
ABC
ABCDADBAABAC

3 5
ABC
AABAC
***/