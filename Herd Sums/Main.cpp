#include <bits/stdc++.h>
using namespace std;
long n,s,s2,i;
int contador;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    s2=1;
    i=1;
    s=0;
    contador=0;
    while(i<=n){
        s=s+s2;
        if(s==n){
            contador=contador+1;
            i=i+1;
            s2=i;
            s=0;
        }else{
            if(s>n){
                s=0;
                i=i+1;
                s2=i;
            }else{
                s2=s2+1;
            }
        }
    }cout<<contador;


    return 0;
}
