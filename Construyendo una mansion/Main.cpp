#include<bits/stdc++.h>
using namespace std;
stack<int>pila;
int n,m,mayor;
int cuadri[1002][1002];
int posible[1002][1002];
void lectura(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char letra;
			cin>>letra;
			if(letra=='R'){
				cuadri[i][j]=0;
			}else{
				cuadri[i][j]=cuadri[i-1][j]+1;
			}
		}
	}
}
int calculo(){
	int i=n;
	int j;
	mayor=0;
	while(i>=1){
		j=m;
		while(j>=1){
			posible[i][j]=1;
			while(!pila.empty() and cuadri[i][j]<=cuadri[i][pila.top()]){
				posible[i][j]+=posible[i][pila.top()];
				posible[i][pila.top()]+=(pila.top()-(j+1));
				if(posible[i][pila.top()]*cuadri[i][pila.top()]>mayor){
					mayor=posible[i][pila.top()]*cuadri[i][pila.top()];
				}
				pila.pop();
			}
			pila.push(j);
			j--;
		}
		while(!pila.empty()){
			posible[i][pila.top()]+=pila.top()-1;
			if(posible[i][pila.top()]*cuadri[i][pila.top()]>mayor){
				mayor=posible[i][pila.top()]*cuadri[i][pila.top()];
			}
			pila.pop();
		}
		i--;
	}
	return mayor;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	lectura();
	cout<<calculo()<<'\n';
}

/// xD
/***
5 5
L L L R R
R L L R R
R R R L R
L L L R L
***/