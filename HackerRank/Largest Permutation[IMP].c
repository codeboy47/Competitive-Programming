#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    long long int n,x,k,i=0,j,y,t=0,l=-100000,a[100000];

    cin>>n;

    cin>>k;

    for(i=0;i<n;i++){
        cin>>a[i];
        index[a[i]] = i;
    }

    i=0,y=0,j=0,x = 0;

    for (int i = 0; i < n && k > 0; i++) {  // we are using index array
        if (a[i] == n - i) {
            continue;
        }
        a[index[n - i]] = a[i];
        index[a[i]] = index[n - i];
        a[i] = n - i;
        index[n - i] = i;
        k--;
    }

    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
   return 0;
}

/*-------------------------------------------
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
//long long int n,k;
long long int n,k,i=0,j,y,t=0,l=-100000,a[100000];

scanf("%d",&n);

scanf("%d",&k);

for(i=0;i<n;i++){

    scanf("%d",&a[i]);
}
i=0,y=0,j=0;
    while(i<k){
        for(j=i;j<n;j++){
            if(l < a[j]){
                l = a[j];
                y = j;
                //printf("%d ",y);
            }
        }
        if(i > n-1) break;
        if(i == y){
            k++;
        }
        t = a[y];
        a[y] = a[i];
        a[i] = t;
        l = -100000;
        i++;
    }
 // printf("       %d %d",k,i);
for(i=0;i<n;i++){

    printf("%d ",a[i]);
}
   return 0;
}


/////////////------------------------------


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//long long int n,k;
long long int n,x,k,i=0,j,y,t=0,l=-100000,a[100000];

cin>>n;

cin>>k;

for(i=0;i<n;i++){

    cin>>a[i];
}

i=0,y=0,j=0,x = 0;
    while(i<k && j<n){
        if(l < a[j]){
            l = a[j];
            y = j;
        }
        j++;
        if(j >= n){
            if(i == y){
                k++;
            }
            t = a[y];
            a[y] = a[i];
            a[i] = t;
            l = -100000;
            j = ++i;
        }
        if(i == k){
            break;
        }
    }

for(i=0;i<n;i++){
    cout<<a[i]<<" ";
}
   return 0;
}
*/
