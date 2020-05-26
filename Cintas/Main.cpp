#include<bits/stdc++.h>
using namespace std;
long long int vel,duracion,n;
long long int cinta[1000002];
void lectura(){
	cin>>vel>>duracion;
	if(vel==0) duracion*=3;
	else if(vel==1) duracion=(duracion/2)*3;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>vel>>cinta[i];
		if(vel==0) cinta[i]*=3;
		else if(vel==1) cinta[i]=(cinta[i]/2)*3;
	}
}
int calculo(){
	int i=1, j;
	long long int minutos;
	int cont;
	int menor=INT_MAX;
	while(i<=n){
		j=i;
		minutos=0;
		cont=0;
		while(j<=n and minutos<duracion){
			minutos+=cinta[j];
			j++;
			cont++;
		}
		if(cont<menor and minutos>=duracion) menor=cont;
		i++;
	}
	return menor;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	lectura();
	cout<<calculo()<<'\n';
}

/// xD
/***
1 32
5
1 6
1 20
1 32
1 30
1 30
***/