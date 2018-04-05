#include <bits/stdc++.h>
#include<vector>
using namespace std;

// use scanf printf instead of cin cout

int main()
{
    vector<int> arr;
    //int arr[10000000];
    int n,q;
    int f,s,t;
    scanf("%d %d",&n,&q);
    //cin>>n>>q;
    for(int i = 0; i < n; i++){
        int d;
        //cin>>d;
        scanf("%d",&d);
        arr.push_back(d);
    }
    for(int i = 0; i < q; i++ ){
        scanf("%d",&f);
        if(f == 0){
            scanf("%d %d",&s,&t);
            arr[t-1] == 0 ? printf("EVEN\n") : printf("ODD\n");
        }else{
            scanf("%d",&s);
            //arr[s-1] = ~arr[s-1];
            if(arr[s-1] == 1){
              arr[s-1] = 0;  
            }
            else if(arr[s-1] == 0){
              arr[s-1] = 1;  
            }
        }
    }
    return 0;
}


/* this code takes time more than 1 second
#include <iostream>
using namespace std;

int binToDec(int *arr, int start, int end){
    int dec = 0;
    int power = 0;
    for(int i = end-1; i >= start ;i--){
        dec = arr[i]*pow(2,power) + dec;
    }
    return dec;
}

int main()
{
    int arr[1000];
    int n,q;
    int f,s,t;
    cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < q; i++ ){
        cin>>f;
        if(f == 0){
            cin>>s>>t;
            int ans = binToDec(arr,s,t);
            ans%2 == 0?cout<<"EVEN\n" : cout<<"ODD\n" ;
        }else{
            cin>>s;
            if(arr[s-1] == 1){
              arr[s-1] = 0;  
            }
            else if(arr[s-1] == 0){
              arr[s-1] = 1;  
            }
        }
    }
    return 0;
}
*/
