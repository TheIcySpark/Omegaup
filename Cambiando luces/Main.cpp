#include<bits/stdc++.h>
using namespace std;
int n,m;
bool led[502];
void lectura(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int ini,fin,ope;
		cin>>ope>>ini>>fin;
		if(ope==0){
			for(int j=ini;j<=fin;j++){
				if(led[j]==1) led[j]=0;
				else led[j]=1;
			}
		}else{
			int cont=0;
			for(int j=ini;j<=fin;j++) cont+=led[j];
			cout<<cont<<'\n';
		}
	}
}
	
int main(){
	lectura();
	
}

/// xD
/***
4 5 0 1 2 0 2 4 1 2 3 0 2 4 1 1 4
***/