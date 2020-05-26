#include <bits/stdc++.h>
using namespace std;
int visitado[3002];
int casos,n;

void lectura(){
    bool alegre;
    int diferencia;
    int a,b;
    cin>>casos;
    for(int k=1;k<=casos;k++){
        cin>>n;
        cin>>a;
        alegre=true;
        for(int i=2;i<=n;i++){
            cin>>b;
            diferencia=abs(a-b);
            if(alegre){
                if(diferencia>=n or diferencia<1 or diferencia>=3000) alegre=false;
                else{
                    if(visitado[diferencia]!=k) visitado[diferencia]=k;
                    else alegre=false;
                }
            }
            a=b;
        }
        if(alegre) cout<<"Alegre"<<'\n';
        else cout<<"No alegre"<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();


    return 0;
}
/// xD
/**
**/