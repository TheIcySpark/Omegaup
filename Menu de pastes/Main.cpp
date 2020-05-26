#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unsigned long long int F,C,P;

unsigned long long int Resultado(unsigned long long int k){
  unsigned long long int f,c;
  if(k%C>0){
    f=k/C+1;
    c=k%C;
  }else{
    f=k/C;
    c=C;
  }
  c=C-c;
  return f+(F*c);
}

void Pedido(){
unsigned long long int k;
  cin>>C>>F>>P;
  for(int i=1;i<=P;i++){
    cin>>k;
    cout<<Resultado(k)<<" ";
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  Pedido();

}
/// xD