#include <bits/stdc++.h>
using namespace std;
//Compiler version g++ 6.3.0
struct nodo{
	int y,x,p;
};
int movs[12][2];
int y,x,m,yf,xf;
queue<nodo>cola;
bool visitados[1002][1002];

void lectura(){
	cin>>y>>x>>m;
	nodo inicial;
	cin>>inicial.y>>inicial.x;
	inicial.p=0;
	cola.push(inicial);
	visitados[inicial.y][inicial.x]=1;
	cin>>yf>>xf;
	for(int i=0;i<m;i++){
		cin>>movs[i][0];
		cin>>movs[i][1];
	}
}

bool valido(nodo a){
	if(a.y>=1 and a.y<=y and a.x>=1 and a.x<=x and !visitados[a.y][a.x]){
		return true;
	}
	return false;
}

int busqueda(){
	nodo actual,copia;
	while(! cola.empty()){
		actual=cola.front(); cola.pop();
		if(actual.y==yf and actual.x==xf){
			return actual.p;
		}
		for(int i=0;i<m;i++){
			copia=actual;
			copia.y+=movs[i][0];
			copia.x+=movs[i][1];
			if(valido(copia)){
				copia.p++;
				visitados[copia.y][copia.x]=1;
				cola.push(copia);
			}
		}
	}
	return -1;
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