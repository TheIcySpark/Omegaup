#include <bits/stdc++.h>
using namespace std;
long long int a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    if(a<b){
        while(a<b){
            a*=2;
            if(a==b){
                cout<<"felizmil"<<'\n'; return 0;
            }
        }
    }else{
        while(b<a){
            b*=2;
            if(a==b){
                cout<<"felizmil"<<'\n'; return 0;
            }
        }
    }
    cout<<"tristemil"<<'\n';


    return 0;
}
/// xD