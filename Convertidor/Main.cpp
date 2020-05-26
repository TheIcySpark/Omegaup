#include<bits/stdc++.h>
using namespace std;
unsigned long long int memo[20];
int i;
unsigned long long int decimal,anterior,cantidad,elevar;
unsigned long long int letra;

string decimal_a_cadena(){
	anterior=0;
	string cadena;
	i=0;
	cadena="";
	cantidad=1;
	cin>>decimal;
	while((cantidad*26)+anterior<decimal){
		cantidad*=26;
		memo[i]=anterior;
		anterior+=cantidad;
		i++;
	}
	i--;
    while(cantidad>=26){
        int j;
        for(j=1;j<=26;j++){
            if(cantidad*j+anterior>=decimal) break;
        }
        letra=j+64;
        decimal-=(cantidad*j);
        cadena+=letra;
        cantidad/=26;
        anterior=memo[i];
        i--;
	}
	cadena+=decimal+64;
	return cadena;
}

unsigned long long int cadena_a_decimal(){
	string cadena;
	elevar=26; decimal=0;
	cin>>cadena;
	i=cadena.size()-2;
	decimal=cadena[i+1]-64;
	while(i>=0){
		decimal+=(cadena[i]-64)*elevar;
		elevar*=26;
		i--;
	}
	return decimal;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	bool caso;
	cin>>caso;
	if(caso==0){
		cout<<decimal_a_cadena()<<'\n';
	}else{
		cout<<cadena_a_decimal()<<'\n';
	}

}

/// xD
/***
0
11750141470300382166

0
18278

0
728

0
2580398988131886038

***/