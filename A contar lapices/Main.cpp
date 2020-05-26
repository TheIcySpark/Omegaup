#include <bits/stdc++.h>
using namespace std;
int l[100002];
int n,k,i,c;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    i=1;
    c=0;
    while(i<=n){
        cin>>l[i];
        if(l[i]==k){
            c=c+1;
        }
        i++;
    }
    cout<<c;

    return 0;
}
