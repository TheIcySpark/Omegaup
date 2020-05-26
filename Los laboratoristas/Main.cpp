#include<bits/stdc++.h>
using namespace std;
int n,q,inicio,final,m;
long long int lista[1000002];
void aumentar(long long int &dato){
	if(dato==-1) m=(m+1)%n;
	else{
		m--;
		if(m<0) m=n-1;
	}
}
void quitar(long long int &dato){
	n--;
	if(dato==1){
		final--;
		if(m!=0) m--;
	}else{
		inicio++;
		m=m%n;
	}
}
void binaria(long long int &dato){
	if(lista[inicio]>dato or lista[final]<dato){
		cout<<"No Laurencio"<<'\n';
		return;
	}
	long long int ini=inicio,fin=final,mit,res;
	while(ini<=fin){
		mit=(ini+fin)/2;
		if(lista[mit]==dato){
			mit-=(inicio-1);
			res=(mit+m)%n;
			if(res==0) res=n;
			cout<<res<<'\n';
			return;
		}else if(lista[mit]<dato){
			ini=mit+1;
		}else{
			fin=mit-1;
		}
	}
}
void lectura(){
	char operacion;
	long long int dato;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lista[i];
	}
	cin>>q;
	inicio=1; final=n; m=0;
	for(int i=1;i<=q;i++){
		cin>>operacion>>dato;
		if(operacion=='M') aumentar(dato);
		else if(operacion=='Q') quitar(dato);
		else binaria(dato);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	lectura();
	
}

/// xD
/***
6 7 33 38 41 97 100 6 M -1 L 38 Q 1 M 1 L 41 L 100
***/