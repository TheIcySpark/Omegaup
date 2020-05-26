#include<bits/stdc++.h>
using namespace std;
int n;
int dato1,dato2;
long long int d2[1000002];
long long int d1[1000002];
void lectura(){
	cin>>n;
	for(int i=1;i<=n;i++){
        int dato;
        cin>>dato;
        if(i%2==0){
            dato2++;
            d2[dato2]=dato;
        }else{
            dato1++;
            d1[dato1]=dato;
        }
    }
    sort(d1+1,d1+dato1+1);
    sort(d2+1,d2+dato2+1);
}
bool posible(){
    int i=1;
    while(i<=dato2){
        if(d1[i]>d2[i]) return false;
        if(d2[i]>d1[i+1] and i+1<=dato1) return false;
        i++;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    if(posible()) cout<<":D"<<'\n';
    else cout<<"D:"<<'\n';
    return 0;
}
///
/***
10
10 9 8 7 6 5 4 3 2 1
6
5 6 8 4 3 4
***/