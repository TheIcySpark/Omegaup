#include <bits/stdc++.h>
using namespace std;
//Compiler version g++ 6.3.0
int ini,mayper,n;
int vol[52];
int memo[50002][52];
void lectura(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>vol[i];
	}
	cin>>ini>>mayper;
}

int f(int suma,int i){
	if(suma>mayper or suma<0) return -1;
	else if(i>n) return suma;
	else{
		if(memo[suma][i]==0){
			memo[suma][i]=max(f(suma-vol[i],i+1),f(suma+vol[i],i+1));
		}
		return memo[suma][i];
	}
}

int main()
{
	lectura();
	cout<<f(ini,1)<<'\n';
			
	return 0;
}
/// xD
/***
**/