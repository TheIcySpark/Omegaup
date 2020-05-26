#include <stdio.h>

int main()
{
    int i,juan=0,pedro=0,valor;
    for(i=1;i<=3;i++){
        scanf("%d",&valor);
        juan+=valor;
    }
    for(i=1;i<=2;i++){
        scanf("%d",&valor);
        pedro+=valor;
    }
    if(juan>pedro) printf("Juan\n");
    else printf("Pedro\n");

    return 0;
}
/// xD