#include <bits/stdc++.h>
using namespace std;
 //Compiler version g++ 6.3.0
 int tablero[1002][1002];
 int n,m,k,v,h;
void lectura(){
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=m;j++){
 			cin>>tablero[i][j];
 		}
 	}
 	cin>>k;
 	for(int i=1;i<=k;i++){
 		char operacion;
 		cin>>operacion;
 		if(operacion=='V') v++;
 		else h++;
 		v%=2; h%=2;
 	}
}

void cambiar(){
	if(v==1){
		int arriba=1; 
		int abajo=n;
		int cambio;
		while(arriba<=n/2){
			cambio=1;
			while(cambio<=m){
				swap(tablero[arriba][cambio],tablero[abajo][cambio]);
				cambio++;
			}
			arriba++;
			abajo--;
		}
	}
	if(h==1){
		int izquierda=1;
		int derecha=m;
		int cambio;
		while(izquierda<=m/2){
			cambio=1;
			while(cambio<=n){
				swap(tablero[cambio][izquierda],tablero[cambio][derecha]);
				cambio++;
			}
			izquierda++;
			derecha--;
		}
	}
}

void mostrar(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<tablero[i][j]<<" ";
		}
		cout<<'\n';
	}
}

 int main()
 {
 	lectura();
 	cambiar();
 	mostrar();
 	
 	return 0;
 }
///xD
/***
3 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
2
V
H
**/