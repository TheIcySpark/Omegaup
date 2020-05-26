#include <bits/stdc++.h>
using namespace std;

bool primo(long long int n){
    for(long long int com=2;com<=sqrt(n);com++){
        if(n%com==0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long int a,b;
    cin>>a>>b;
    for(long long int i=a;i<=b;i++){
        if(primo(i)) cout<<i<<" ";
    }
    cout<<'\n';

    return 0;
}
/// xD