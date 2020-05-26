#include<bits/stdc++.h>
using namespace std;
int planta[1000002];
int tiempo[1000002];
stack<int>pila;
int n;
void lectura(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>planta[i];
}
int calculo(){
	int seg;
	int mayor=0;
	for(int i=n;i>=1;i--){
		seg=0;
		while(!pila.empty() and planta[i]>planta[pila.top()]){
			seg++;
			tiempo[i]=max(seg,tiempo[pila.top()]);
			seg=tiempo[i];
			pila.pop();
		}
		if(tiempo[i]>mayor) mayor=tiempo[i];
		pila.push(i);
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
***/