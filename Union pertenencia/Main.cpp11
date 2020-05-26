#include<iostream>
using namespace std;
struct conjunto{
	int padre[100002];
	conjunto(int n){
		for(int i=0;i<n;i++) padre[i]=i;
	}
	int Root(int x){
		if(padre[x]==x) return x;
		else return padre[x]=Root(padre[x]);
	}
	bool SameFather(int a,int b){
		if(Root(a)==Root(b)) return true;
		else return false;
	}
	void Union(int a,int b){
		int rootA=Root(a);
		int rootB=Root(b);
		padre[rootB]=rootA;
	}
};
int n,k;
void lectura(){
	char t;
	int a,b;
	cin>>n>>k;
	conjunto set(n);
	for(int i=1;i<=k;i++){
		cin>>t>>a>>b;
		if(t=='P') cout<<set.SameFather(a,b)<<'\n';
		else set.Union(a,b);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	lectura();
}

/// xD
/**
***/