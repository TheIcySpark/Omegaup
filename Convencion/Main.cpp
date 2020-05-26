#include <bits/stdc++.h>
using namespace std;
struct amig{
    int a,b;
    const bool operator<(const amig &otro)const{
        if(a==otro.a){
            return b>otro.b;
        }else{
            return a>otro.a;
        }
    }
};
int n,m,ini,fin,i,suma,may,a,b;
int t[1000002];
amig amigos[200002];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>a>>b;
        amigos[i].a=max(a,b);
        amigos[i].b=min(a,b);
    }
    sort(amigos+1,amigos+m+1);
    for(i=0;i<n;i++){
        t[i]=i-1;
    }
    for(i=1;i<=m;i++){
        if(t[amigos[i].a]==amigos[i].b){
            t[amigos[i].a]--;
        }
    }
    ini=0; fin=1; may=0;suma=0;
    while(fin<n){
        if(t[fin]<ini){
            fin++;
           suma=fin-ini;
        }else{
            suma=fin-ini;
            ini=t[fin]+1;
        }
        if(suma>may){
            may=suma;
        }
    }
    cout<<may;
    return 0;
}