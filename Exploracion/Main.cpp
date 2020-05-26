#include<bits/stdc++.h>
using namespace std;
long long int t;
int n,centro;
int punto[50003];
void lectura(){
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		cin>>punto[i];
	}
	n++;
	sort(punto+1,punto+n+1);
}
int binaria(){
	int i;
	for(i=1;punto[i]!=0;i++){
	}
	return i;
}
int cuantas(){
	int x=0;
	int izq=centro-1;
	int der=centro+1;
	int cont=0;
	while(t>=1 and (der<=n or izq>=1)){
		if((abs(punto[izq])<punto[der] and izq>=1) or der>n){
			t-=abs(x-punto[izq]);
			x=punto[izq];
			izq--;
		}else{
			t-=abs(punto[der]-x);
			x=punto[der];
			der++;
		}
		cont++;
	}
	if(t<0) return cont-1;
	else return cont;
}

int main(){
	lectura();
	centro=binaria();
	cout<<cuantas()<<'\n';
}

/// xD
/***
25 5
10
-3
8
-7
1
***/