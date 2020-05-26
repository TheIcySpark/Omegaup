#include <bits/stdc++.h>
using namespace std;
//Compiler version g++ 6.3.0
int m[102][102];
int mapa[102][102];
int f,c;

void inicializar(){
	for(int i=1;i<=f;i++){
		m[i][c+1]=10000;
	}
	for(int j=1;j<=c;j++){
		m[f+1][j]=10000;
	}
}

int busqueda(){
	for(int j=c;j>=1;j--){
		for(int i=f;i>=1;i--){
			if(m[i+1][j]!=10000 or m[i][j+1]!=10000){
				m[i][j]=min(m[i+1][j],m[i][j+1])+mapa[i][j];
			}else{
				m[i][j]=mapa[i][j];
			}
			///cout<<i<<" "<<j<<" "<<m[i][j]<<endl;
		}
	}
	return m[1][1];
}

int main()
{
	cin>>f>>c;
	for(int i=1;i<=f;i++){
		for(int j=1;j<=c;j++){
			cin>>mapa[i][j];
		}
	}
	inicializar();
	cout<<busqueda()<<'\n';
 			
	return 0;
}
/// xD
/***
**/