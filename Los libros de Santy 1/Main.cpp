#include<bits/stdc++.h>
using namespace std;
long long int libro[1000002];
int n,q;
void preguntas(){
	int ini,fin,m;
	long long int lib;
	for(int i=1;i<=q;i++){
		cin>>lib;
		ini=0; fin=n-1;
		while(ini<=fin){
			m=(ini+fin)/2;
			if(libro[m]>lib) fin=m-1;
			else if(libro[m]<lib) ini=m+1;
			else{
				cout<<m<<" ";
				break;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>libro[i];
	preguntas();
}

/// xD
/***
***/