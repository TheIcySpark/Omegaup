#include <stdio.h>

int main()
{
    long long int i,n,alt,anc;
    long long int suma=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld%lld",&alt,&anc);
        suma+=alt*anc;
    }
    printf("%lld",suma);
    return 0;
}