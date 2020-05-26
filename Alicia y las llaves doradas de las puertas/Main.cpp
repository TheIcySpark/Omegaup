#include <bits/stdc++.h>
using namespace std;
int chapas,llaves;
int tamano[100002];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int dato;
    cin>>chapas;
    for(int i=1;i<=chapas;i++){
        cin>>dato;
        tamano[dato]=i;
    }
    cin>>llaves;
    for(int i=1;i<=llaves;i++){
        cin>>dato;
        cout<<tamano[dato]<<" ";
    }
    cout<<'\n';

    return 0;
}
/// xD