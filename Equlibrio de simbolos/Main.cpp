#include <bits/stdc++.h>
using namespace std;
stack<char>pila;
int n;

int rutina(){
    char caracter;
    int r1=INT_MAX,r2=INT_MAX,r3=INT_MAX;
    int cor=0,lla=0,par=0;
    int poscor,poslla,pospar;
    int ret;
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++){
        scanf("%c",&caracter);
        if(caracter=='('){
            pila.push(caracter);
            if(par==0) pospar=i;
            par++;
        }else if(caracter=='['){
            pila.push(caracter);
            if(cor==0) poscor=i;
            cor++;
        }else if(caracter=='{'){
            pila.push(caracter);
            if(lla==0) poslla=i;
            lla++;
        }
        if(caracter==')'){
            par--;
            if(par<0 and r2==INT_MAX) r2=i;
            if(!pila.empty() ){
                if(pila.top()=='(') pila.pop();
                else{
                    if(r3==INT_MAX) r3=i;
                }
            }
        }else if(caracter==']'){
            cor--;
            if(cor<0 and r2==INT_MAX) r2=i;
            if(!pila.empty() ){
                if(pila.top()=='[') pila.pop();
                else{
                    if(r3==INT_MAX) r3=i;
                }
            }
        }else if(caracter=='}'){
            lla--;
            if(lla<0 and r2==INT_MAX) r2=i;
            if(!pila.empty() ){
                if(pila.top()=='{') pila.pop();
                else{
                    if(r3==INT_MAX) r3=i;
                }
            }
        }
    }
    if(par>0)r1=min(r1,pospar);
    if(cor>0)r1=min(r1,poscor);
    if(lla>0) r1=min(r1,poslla);
    if(r1==INT_MAX and r2==INT_MAX and r3==INT_MAX) return 0;
    else{
        ret=min(r1,r2);
        ret=min(ret,r3);
        return ret-1;
    }
}

int main()
{
    printf("%d",rutina());

    return 0;
}
/// xD
/**
19
a(b + c * { d / h )
**/