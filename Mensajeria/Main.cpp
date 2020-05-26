#include <bits/stdc++.h>
using namespace std;
long long int n,i,k,men,suma,may=0;
bool instalado=false;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    cin>>n>>k;
    suma=0;
    for(i=1;i<=n;i++){
        cin>>men;
      	if(men>may)may=men;
        if(men>k){
            suma+=k;
          	instalado=true;
        }else{
            suma+=men;
        }
    }
  	if(instalado==false){
      	suma-=men;
      	suma+=k;
    }
    cout<<suma<<'\n';

    return 0;
}