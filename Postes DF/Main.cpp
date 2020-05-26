#include<bits/stdc++.h>
using namespace std;
int n,k;
long long int poste[100002];
void lectura(){
	cin>>k>>n;
	for(int i=1;i<=n;i++) cin>>poste[i];
	sort(poste+1,poste+n+1);
}
long long int calculo(){
	int ini=1;
	int fin=k;
	long long int dis;
	long long int menor=INT_MAX;
	while(fin<=n){
		dis=poste[fin]-poste[ini];
		ini++;
		fin++;
		if(dis<menor) menor=dis;
	}
	return menor;
}

int main(){
	lectura();
	cout<<calculo()<<'\n';
}

/// xD
/***
***/