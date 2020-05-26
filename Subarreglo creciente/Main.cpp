#include <bits/stdc++.h>
using namespace std;
int n;
long long int a[100002];
void lectura(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
}
int izq(){
    int i,sig,l,mayor,ant;
    bool primero=false;
    mayor=0;
    i=1;
    l=1;
    sig=1;
    while(i<=n){
        if(a[i]<=a[i-1] and primero){
            primero=false;
            if(i-l>mayor) mayor=i-l;
            l=sig;
        }
        if(a[i]<=a[i-1] and !primero){
            primero=true;
            ant=sig;
            sig=i;
            if(a[i-2]+1<a[i]) a[i-1]=a[i-2]+1;
            else if(i-l==1) a[i-1]=1;
            else if(a[i-1]+1<a[i+1]) a[i]=a[i-1]+1;
            else{
                primero=false;
                if(i-l+1>mayor) mayor=i-l+1;
                l=i;
            }
        }
        i++;
    }
    if(i-l>mayor) mayor=i-l;
    if(i-(l-1)>mayor and !primero) mayor=i-(l-1);
    return mayor;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    cout<<izq()<<'\n';

    return 0;
}
/// xD
/***
6
7 2 3 1 5 6
6
1 2 5 4 5 6
**/