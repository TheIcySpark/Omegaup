#include <bits/stdc++.h>
using namespace std;
int n,cont;
int num[7002];
void lectura(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
}
int calculo(){
    int c,b,a,actual;
    cont=0;
    for(int i=n;i>=2;i--){
        c=i; b=i-1;
        while(num[c]-num[b]==0) b--;
        actual=num[c]-num[b];
        a=b-1;
        while(a>=0){
            if(num[b]-num[a]<actual) a--;
            else if(num[b]-num[a]==actual and a>0){
                cont++;
                a--;
            }else{
                b--;
                actual=num[c]-num[b];
                a=min(a+1, b-1);
            }
        }
    }
    return cont;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    cout<<calculo()<<'\n';

    return 0;
}
/// xD
/***
5
1 2 3 3 3
***/