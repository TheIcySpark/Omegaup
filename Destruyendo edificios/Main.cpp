/// decoder
#include<bits/stdc++.h>
using namespace std;
int n;
long long int mayor;
long long int edi[1000002];
int posible[1000002];
stack<int>pila;
void lectura(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>edi[i];
}
void calcular(){
	int i=n;
	mayor=0;
	while(i>=1){
		posible[i]=1;
		while(!pila.empty() and edi[i]<=edi[pila.top()]){
			posible[i]+=posible[pila.top()];
			posible[pila.top()]+=(pila.top()-(i+1));
			if(edi[pila.top()]*posible[pila.top()]>mayor) mayor=edi[pila.top()]*posible[pila.top()];
			pila.pop();
		}
		pila.push(i);
		i--;
	}
	while(!pila.empty()){
		posible[pila.top()]+=pila.top()-1;
		if(edi[pila.top()]*posible[pila.top()]>mayor) mayor=edi[pila.top()]*posible[pila.top()];
		pila.pop();
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	lectura();
	calcular();
	cout<<mayor<<'\n';
}

/// xD
/***
***/