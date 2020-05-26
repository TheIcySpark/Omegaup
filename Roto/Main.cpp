#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    queue<char>aux;
    string texto;
    int i,j,fin,tam;
    getline(cin,texto);
    i=texto.size();
    tam=texto.size();
    while(i>=0){
            if(i==0 and texto[i]!='[' and texto[i]!=']'){
                j=i;
                while(texto[j]!='[' and texto[j]!=']' and j<tam){
                aux.push(texto[j]);
                j++;
            }
        }
        if(texto[i]=='['){
            j=i+1;
            while(texto[j]!='[' and texto[j]!=']' and j<tam){
                aux.push(texto[j]);
                j++;
            }
        }
        i--;
    }
    i=0;
    fin=texto.size();
    while(i<fin){
        if(texto[i]==']'){
            j=i+1;
            while(texto[j]!='[' and texto[j]!=']' and j<tam){
                aux.push(texto[j]);
                j++;
            }
        }
        i++;
    }
    while(not aux.empty()){
        cout<<aux.front();
        aux.pop();
    }
    return 0;
}
/// XD