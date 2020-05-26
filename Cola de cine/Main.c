#include <stdio.h>

int main()
{
    int actual=0 ,tiempo=0, maximo=0, llegada=0;
    while(llegada!=-1){
        scanf("%d",&llegada);
        if(llegada>-1){
            tiempo+=llegada;
            actual+=llegada;
        }
        if(actual>0){
            if(actual>maximo) maximo=actual;
            actual--;
        }
    }
    printf("%d\n%d",tiempo,maximo);

    return 0;
}
/// xD