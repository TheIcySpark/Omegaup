#include<bits/stdc++.h>
using namespace std;
struct amis{
	int a,b;
	const bool operator<(const amis &otro)const{
		if(a==otro.a) return b<otro.b;
		else return a<otro.a;
	}
};
amis amistad[100002];
int n,m,may;
void lectura(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int a,b;
		cin>>a>>b;
		amistad[i].a=min(a,b);
		amistad[i].b=max(a,b);
	}
	sort(amistad+1,amistad+m+1);
}
void busqueda(int izq,int der,int cont){
	if(cont>may) may=cont;
	if(izq<1 or der>n) return;
	int ini=1,fin=m,mit;
	while(ini<=fin){
		mit=(ini+fin)/2;
		if(amistad[mit].a==izq){
			if(amistad[mit].b==der){
				return busqueda(izq-1,der+1,cont+2);
			}
			if(amistad[mit].b<der)ini=mit+1;
			else fin=mit-1;
		}else{
			if(amistad[mit].a<izq) ini=mit+1;
			else fin=mit-1;
		}
	}
}
int calculo(){
	may=1;
	int izq,der;
	for(int i=1;i<=m;i++){
		if(amistad[i].b-amistad[i].a==1){
			izq=amistad[i].a;
			der=amistad[i].b;
			busqueda(izq-1,der+1,2);
		}else if(amistad[i].b-amistad[i].a==2){
			izq=amistad[i].a;
			der=amistad[i].b;
			busqueda(izq-1,der+1,3);
		}
	}
	return may;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	lectura();
	cout<<calculo()<<'\n';
}

/// xD
/***
5 4 2 3 4 1 3 5 2 4

6 6
1 6
3 4
2 5
1 4
1 5
***/