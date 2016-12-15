#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main() {
    int n, k, i, count,sum=0;
    int answer = 0;

    scanf("%d%d", &n, &k);
    int *prices = (int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++) {
        scanf("%d", &prices[i]);
    }

    qsort(prices, n, sizeof(int), cmpfunc);


    for(i = 0;i < n; i++){
        if(sum <= k){
            sum = sum + prices[i];
            answer++;
        }else{
            break;
        }
    }

    printf("%d\n", answer-1);

    return 0;
}
