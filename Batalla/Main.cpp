#include <bits/stdc++.h>
using namespace std;
long long int n,i,j,suma;
long long int isaac[102],lira[102];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>isaac[i];
    }
    for(i=1;i<=n;i++){
        cin>>lira[i];
    }
    sort(isaac+1,isaac+n+1);
    sort(lira+1,lira+n+1);
    i=n; j=n; suma=0;
    while(i>=1){
        if(lira[i]>=isaac[j]){
            i--;
        }else{
            suma+=isaac[j];
            j--; i--;
        }
    }
    cout<<suma<<'\n';

    return 0;
}