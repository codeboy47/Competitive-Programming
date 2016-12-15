#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main() {
int n,i=0,j=0,x,y,c=0,re=0;

int a[100000];

scanf("%d",&n);

for(i=0;i<n;i++){

    scanf("%d",&a[i]);
}
for(i=0;i<n;i++){

 //   printf("%d %d",a[i],n);
}
i=0;
qsort(a, n, sizeof(int), cmpfunc);
while(i<n){
	if((a[j] <= a[i]) && (a[i] <= (a[j]+4))){
    	i++;
    	re = 1;
    	//printf("%d %d ",a[i],i);
    }if((a[j]+4) < a[i]){
    	c++;
    	j =i;
    }
}
printf("%d",c+1);

return 0;
}
