#include<bits/stdc++.h>
using namespace std;
struct rango{
	long long int ini,fin;
};
rango act[1002];
long long int n,A,P;
void suma(long long int ini,long long int fin){
	long long int suma=0;
	for(int i=1;i<=A;i++){
		if(act[i].fin>=ini and fin>=act[i].ini){
			long long int a,b,dis;
			if(ini<=act[i].ini){
				a=act[i].ini;
				b=min(fin,act[i].fin);
				dis=b-a+1;
				suma+=(dis*(dis+1))/2;
			}else if(act[i].ini<ini){
				a=act[i].ini;
				b=min(fin,act[i].fin);
				dis=b-a+1;
				suma+=(dis*(dis+1))/2;
				b=ini;
				dis=b-a;
				suma-=(dis*(dis+1))/2;
			}
			suma%=10000;
		}
	}
	cout<<suma<<'\n';
}
void lectura(){
	cin>>n;
	cin>>A>>P;
	for(int i=1;i<=A;i++) cin>>act[i].ini>>act[i].fin;
	for(int i=1;i<=P;i++){
		long long int ini,fin;
		cin>>ini>>fin;
		suma(ini,fin);
	} 
}

int main(){
	lectura();

}

/// xD
/***
7 2 2
3 6
4 7
4 6
1 7
***/