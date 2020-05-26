#include<bits/stdc++.h>
using namespace std;
int q,n;
long long int carro[100002];
void posible(long long int &g){
	int ini=0,fin=n,m;
	while(ini!=fin){
		m=(ini+fin)/2+1;
		if(carro[m]<=g) ini=m;
		else fin=m-1;
	}
	cout<<ini<<" "<<g-carro[ini]<<'\n';
}
void lectura(){
	cin>>q>>n;
	for(int i=1;i<=n;i++){
		cin>>carro[i];
		carro[i]+=carro[i-1];
	}
	for(int i=1;i<=q;i++){
		long long int g;
		cin>>g;
		posible(g);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	lectura();
	
}

/// xD
/***
2 5 1 200 30 345 12 250 576
***/