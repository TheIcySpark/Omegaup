#include <bits/stdc++.h>
using namespace std;
//Compiler version g++ 6.3.0
struct nodo{
	int x,y,z;
	double t;
};
int n,xf,yf,zf,tmax;
string mapa[102][102][102];
bool visitados[102][102][102];
queue<nodo>cola;
void lectura(){
	cin>>n>>tmax;
	cin>>xf>>yf>>zf;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int l=0;l<n;l++){
				cin>>mapa[i][j][l];
			}
		}
	}
	visitados[0][0][0]=1;
	cola.push({0,0,0,0});
}

void direccion(nodo &r,int i){
	if(mapa[r.x][r.y][r.z][i]=='E') r.x++;
	else if(mapa[r.x][r.y][r.z][i]=='O') r.x--;
	else if(mapa[r.x][r.y][r.z][i]=='N') r.y++;
	else if(mapa[r.x][r.y][r.z][i]=='S') r.y--;
	else if(mapa[r.x][r.y][r.z][i]=='U') r.z++;
	else if(mapa[r.x][r.y][r.z][i]=='D') r.z--;
}

bool valido(nodo &r){
	if(r.x>=0 and r.x<n and r.y>=0 and r.y<n and r.z>=0 and r.z<n 
	and !visitados[r.x][r.y][r.z]){
		visitados[r.x][r.y][r.z]=1;
		return true;
	}
	return false;
}

double busqueda(){
	nodo actual,copia;
	while(!cola.empty()){
		actual=cola.front(); cola.pop();
		if(actual.x==xf and actual.y==yf and actual.z==zf) return actual.t;
		if(actual.t<tmax){
			actual.t+=0.5;
			for(int i=0;i<=mapa[actual.x][actual.y][actual.z].length();i++){
				copia=actual;
				direccion(copia,i);
				if(valido(copia)){
					cola.push(copia);
				}
			}
		}
	}
	return-1;
}

int main()
{
	lectura();
	double r;
	r=busqueda();
	if(r==-1){
		cout<<"Impossibru"<<'\n';
	}else{
		cout<<r<<'\n';
	}
			
	return 0;
}
/// xD
/***
3 5
0 1 2
NE
NS
N
NE
NS
D
U
DE
E
NE
NS
E
NE
NS
NO
O
UES
S
NO
NS
N
NO
NS
N
O
U
N
**/