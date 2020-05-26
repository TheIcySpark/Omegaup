#include<bits/stdc++.h>
using namespace std;
string n1,n2;
int calcular(){
	int i=0;
	int cont=0;
	while(i<n2.size() or i<n1.size()){
		if(n2[i]<48) n2[i]=0;
		else n2[i]-=48;
		if(n1[i]<48) n1[i]=0;
		else n1[i]-=48;
		i++;
	}
	i=0;
	while(i<n2.size() or i<n1.size()){
		if(n1[i]+n2[i]>9){
			cont++;
			n1[i+1]++;
		}
		i++;
	}
	return cont;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n1;
	cin>>n2;
	reverse(n1.begin(),n1.end());
	reverse(n2.begin(),n2.end());
	cout<<calcular()<<'\n';
}

/// xD
/***
***/