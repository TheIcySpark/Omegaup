#include <bits/stdc++.h>
using namespace std;
char ad,chido;
long long int n1,n2,divi,suma,largo,cont,inicio,codigo[10000002],fin,i;
string l1,l2;

void lectura(){
    cin>>ad;
    cin>>n1;
    getline(cin,l1);
    getline(cin,l1);
    cin>>ad;
    cin>>n2;
    getline(cin,l2);
    getline(cin,l2);
}

void cadena1(){
    largo=l1.length();
    divi=largo/n1;
    largo--;
    cont=0; inicio=0; suma=0;
    while(suma!=largo+n1){
        if(cont==divi){
            inicio++;
            suma=inicio;
            cont=0;
        }
        if(l1[suma]>96){
            codigo[inicio]+=l1[suma]-96;
        }else{
            codigo[inicio]+=l1[suma]-64;
        }
        codigo[inicio]%=10;
        cont++;
        suma+=n1;
    }
    fin=((codigo[0]+1)*(codigo[1]+1));
    for(i=2;i<=largo+1;i++){
        fin*=(codigo[i]+1);
        fin=fin%10;
    }
    fin=fin%10;
    cout<<fin+1;
}

void cadena2(){
    largo=l2.length();
    divi=largo/n2;
    largo--;
    cont=0; inicio=0; suma=0; codigo[inicio]=0;
    while(suma!=largo+n2){
        if(cont==divi){
            inicio++;
            codigo[inicio]=0;
            suma=inicio;
            cont=0;
        }
        if(l2[suma]>96){
            codigo[inicio]+=l2[suma]-96;
        }else{
            codigo[inicio]+=l2[suma]-64;
        }
        codigo[inicio]%=10;
        cont++;
        suma+=n2;
    }
    fin=((codigo[0]+1)*(codigo[1]+1));
    for(i=2;i<=largo+1;i++){
        fin*=(codigo[i]+1);
        fin=fin%10;
    }
    fin=fin%10;
    chido=fin+65;
    cout<<"-"<<chido<<'\n';
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    cadena1();
    cadena2();
    return 0;
}
/// xD
/***
! 4
IBIUIIItIIJI
! 4
IIBIUIIItIIJ

! 2
zZ
! 2
Zz
***/