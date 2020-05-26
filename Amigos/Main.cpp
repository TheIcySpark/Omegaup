#include <bits/stdc++.h>
using namespace std;

struct b{
   map<string,int>amigos;
   int n[1002][1002];
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    b a;
    int n,i,j,p,aux1,aux2,r[10002];
    string nombre,n1,n2;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>nombre;
        a.amigos[nombre]=i;
    }
    i=1;
    while(i<=n){
        j=1;
        while(j<=n){
            cin>>a.n[i][j];
            j++;
        }
        i++;
    }
    cin>>p;
    i=1;
    while(i<=p){
        cin>>n1;
        cin>>n2;
        aux1=a.amigos[n1];
        aux2=a.amigos[n2];
        r[i]=a.n[aux1][aux2];
        i++;
    }
    i=1;
    while(i<=p){
        cout<<r[i]<<endl;
        i++;
    }

    return 0;
}