#include <iostream>
using namespace std;
long long int N;
long long int pattern[500002];
bool visited[500002];

void Reading(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>pattern[i];
}

long long int GCD(long long int a,long long int b){
    if(a==0) return b;
    else return GCD(b%a,a);
}

long long int Travel(){
    long long int b,div;
    b=1;
    long long int cont,current;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            current=i; cont=0;
            while(!visited[current]){
                visited[current]=true;
                cont++;
                current=pattern[current];
            }
            div=GCD(cont,b);
            b/=div;
            b=b*cont;
        }
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    Reading();
    cout<<Travel()<<'\n';

    return 0;
}
/// xD
/**
15
13 4 5 9 10 7 15 14 3 2 1 11 12 6 8
**/