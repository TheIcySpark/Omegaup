#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string cadena;
    stack<char>pila;
    bool balance;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cadena;
        balance=true;
        for(int j=0;j<cadena.size();j++){
            if(cadena[j]=='(' or cadena[j]=='[' or cadena[j]=='{') pila.push(cadena[j]);
            else{
                if(!pila.empty()){
                    if(cadena[j]==')' and pila.top()=='(') pila.pop();
                    else if(cadena[j]==']' and pila.top()=='[') pila.pop();
                    else if(cadena[j]=='}' and pila.top()=='{') pila.pop();
                    else{
                        balance=false;
                        break;
                    }
                }else{
                    balance=false;
                    break;
                }
            }
        }
        if(balance and pila.empty()) cout<<"SI"<<'\n';
        else cout<<"NO"<<'\n';
        while(!pila.empty()) pila.pop();
    }

    return 0;
}
/// xD