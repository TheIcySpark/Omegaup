#include<bits/stdc++.h>
using namespace std;
int necesarias,n,cont,desp,menor,ini,fin;
bool cuenta[30002];
void lectura(){
	cin>>necesarias>>n;
	for(int i=1;i<=n;i++){
		cin>>cuenta[i];
	}
}
int encuentra(){
	int i;
	for(i=1;cont<necesarias;i++){
		if(cuenta[i]==0) cont++;
		else desp++;
	}
	menor=desp;
	return i-1;
}
int recorrido(){
	ini=1;
	fin=encuentra();
	while(ini<=n){
		if(cuenta[ini]==0) cont--;
		else desp--;
		while(cont<necesarias){
			fin++;
			if(fin>n) fin=1;
			if(cuenta[fin]==0) cont++;
			else desp++;
		}
		if(desp<menor) menor=desp;
		ini++;
	}
	return menor;
}

int main(){
	lectura();
	desp=0; cont=0;
	cout<<recorrido()<<'\n';
}

/// xD
/***
***/