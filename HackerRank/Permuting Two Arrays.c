#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main() {

    int a[100000],b[100000],i,j,flag,q,n,rel;
    scanf("%d", &q);

    for(j=0; j<q; j++) {
        scanf("%d", &n);
        scanf("%d", &rel);
        for(i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        for(i=0; i<n; i++) {
            scanf("%d", &b[i]);
        }

        qsort(a, n, sizeof(int), cmpfunc);
        qsort(b, n, sizeof(int), cmpfunc);

        for(i=0;i<n;i++){
            if(a[i] + b[n-i-1] >= rel){
                flag = 1;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}
