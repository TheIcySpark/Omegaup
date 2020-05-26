#include <stdio.h>

int main()
{
    int n,edad,i,mayor=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&edad);
        if(edad>mayor) mayor=edad;
    }
    printf("%d\n",mayor);

    return 0;
}
/// xD