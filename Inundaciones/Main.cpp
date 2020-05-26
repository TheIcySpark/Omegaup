#include <bits/stdc++.h>
using namespace std;
 //Compiler version g++ 6.3.0
 struct coordenada{
 	int r,c;
 };
int r,c;
int mapa[102][102];
bool visitados[102][102];
bool mismo[102][102];

coordenada direccion(coordenada copia){
	if(mapa[copia.r][copia.c]==0) copia.r--;
	else if(mapa[copia.r][copia.c]==1) copia.c++;
	else if(mapa[copia.r][copia.c]==2) copia.r++;
	else if(mapa[copia.r][copia.c]==3) copia.c--;
	return copia;
}

void lectura_mapeo(){
	coordenada inicial;
	cin>>r>>c>>inicial.r>>inicial.c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>mapa[i][j];
		}
	}
	coordenada copia=inicial;
	visitados[copia.r][copia.c]=mismo[copia.r][copia.c]=1;
	while(mapa[copia.r][copia.c]!=-1){
		copia=direccion(copia);
		visitados[copia.r][copia.c]=mismo[copia.r][copia.c]=1;
	}
}	


bool revisar(coordenada copia){
	if(mismo[copia.r][copia.c]) return true;
	else if(visitados[copia.r][copia.c]) return false;
	visitados[copia.r][copia.c]=1;
	coordenada aux;
	aux=direccion(copia);
	if(revisar(aux)){
		mismo[copia.r][copia.c]=1;
		return true;
	}
	return false;
}

void mapeo(){
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(!visitados[i][j]){
				coordenada copia;
				copia.r=i; copia.c=j;
				revisar(copia);
			}
		}
	}
}

void mostrar(){
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cout<<mismo[i][j]<<" ";
		}
		cout<<'\n';
	}
}

 int main()
 {
 	lectura_mapeo();
 	mapeo();
 	mostrar();
 	return 0;
 }
/// xD
/***
**/