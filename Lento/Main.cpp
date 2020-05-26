#include <bits/stdc++.h>
using namespace std;
 //Compiler version g++ 6.3.0
int n;
vector<long long int>pares;
vector<long long int>impares;

void lectura(){
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		long long int color;
 		cin>>color;
 		if(color%2==0){
 			pares.push_back(color);
 		}else{
 			impares.push_back(color);
 		}
 	}
}

bool ganar_imposible(){
	if(impares.size()>=1) return false;
	return true;
}

long long int maximo(){
	long long int suma=0;
	sort(impares.begin(),impares.end());
	for(int i=0;i<pares.size();i++){
		suma+=pares[i];
	}
	for(int i=0;i<impares.size();i++){
		suma+=impares[i];
	}
	if(suma%2==0) suma-=impares[0];
	return suma;
}

 int main()
 {
 	lectura();
 	if(ganar_imposible()) cout<<0<<'\n';
 	else cout<<maximo()<<'\n';
 	
 	return 0;
 }
/// xD
/***
3
5 6 7

5
1 3 5 7 9

10
1 2 3 4 5 6 7 8 9 10
**/