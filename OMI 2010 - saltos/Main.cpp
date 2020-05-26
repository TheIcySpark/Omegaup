#include<bits/stdc++.h>
using namespace std;
long long int f,c,fi,ci,a,d,fa,ca,fc,cc;
void comunes(){
	cc=0; fc=0;
	for(int i=1;i<=f*c and (cc==0 or fc==0);i++){
		fa=((a*i)+fi)%f;
		if(fa==0) fa=f;
		ca=((d*i)+ci)%c;
		if(ca==0) ca=c;
		if(ca==ci and cc==0) cc=i;
		if(fa==fi and fc==0) fc=i;
	}
}

long long int minimo(){
	ca=cc; fa=fc;
	if(cc>fc){
		while(cc%fc!=0){
			cc+=ca;
		}
		return cc;
	}else if(fc>cc){
		while(fc%cc!=0){
			fc+=fa;
		}
		return fc;
	}else{
		return cc;
	}
}

int main(){
	long long int x;
	cin>>f>>c
	>>a>>d
	>>fi>>ci;
	comunes();
	cout<<minimo()<<'\n';
};

/// xD
/***
***/