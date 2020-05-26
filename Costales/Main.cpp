#include <bits/stdc++.h>
using namespace std;
int cubeta[1002];
int n,c;
int i;
int ph;
int costales;

int main()
{
    cin>>n;
    i=1;
    while(i<=n){
        cin>>ph;
        if(cubeta[ph]==0){
            costales=costales+1;
        }
        cubeta[ph]=cubeta[ph]+1;
        i=i+1;
    }
    cin>>c;
    i=1;
    while(i<=c){
        cin>>ph;
        if(cubeta[ph]>0){
            costales=costales-1;
        }
        cubeta[ph]=0;
        i=i+1;
    }
    cout<<costales;

    return 0;
}
