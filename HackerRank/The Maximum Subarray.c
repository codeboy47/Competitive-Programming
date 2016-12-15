#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int counter=0,i,j,a[100000],t,n,sum=0,l=-100000;
    scanf("%d", &t);

    for(j=0; j<t; j++) {
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        for(i=0;i<n;i++){
            if(a[i] > l && a[i] < 0){
                l = a[i];
            }
        }
        for(i=0;i<n;i++){
          if(a[i] >= 0){
              sum = sum + a[i];
              counter++;
          }
        }
        if(counter == n){
            l = 0;
        }
        printf("%d %d\n",sum+l,sum);
        sum = 0;
        l = -100000;
    }

    return 0;
}
