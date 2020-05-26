#include <bits/stdc++.h>

using namespace std;
int cuantos,i,minimo,j,estado;
char uno,siguiente;
string Cosa = "0";
int main()
{
    cin >> cuantos;
    for(i=1; i<=cuantos; i++){
        cin >> uno;
        Cosa+=uno;
    }
    for(i=cuantos; i>2; i--,minimo++){
        siguiente = Cosa[i-1];
        if(Cosa[i] == '1'){
            if(siguiente == '1' ){
                j=i;
                while(Cosa[j] == '1'){
                    Cosa[j]= '0';
                    j--;
                }
                Cosa[j] = '1';
            } else {
                Cosa[i] = '0';
            }
            minimo++;
        }
    }
    if(Cosa[0]== '1'){
        minimo+=2;
    } else if(Cosa[1]=='1'){
        if(Cosa[2]=='1'){
            minimo+=2;
        }else {
            minimo++;
        }
    }
    cout << minimo << endl;
    return 0;
}