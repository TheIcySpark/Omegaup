#include <bits/stdc++.h>
using namespace std;
//Compiler version g++ 6.3.0
int n;
int triangulo[102][102];
int memo[102][102];
void lectura(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>triangulo[i][j];
		}
	}
}

int busqueda(){
	for(int i=n;i>=1;i--){
		for(int j=i;j>=1;j--){
			memo[i][j]=max(memo[i+1][j],memo[i+1][j+1])+triangulo[i][j];
		}
	}
	return memo[1][1];
}

int main()
{
	lectura();
	cout<<busqueda()<<'\n';
 			
	return 0;
}
/// xD
/***
**/