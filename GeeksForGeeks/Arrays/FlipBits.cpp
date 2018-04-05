#include <bits/stdc++.h>
using namespace std;

// the problem looks like a dp problem but can be solved by kadane's algorithm


// time complexity is O(n)
int findSubarray(int *arr, int n){

    int ones = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            ones++;
            arr[i] = -1;
        }
        else{
            arr[i] = 1;
        }
    }

    // apply kadane's here
    int cs = 0, ms = 0;
    for(int i = 0; i < n; i++){

        cs += arr[i];
        if(cs < 0){
            cs = 0;
        }
        ms = max(ms,cs);

    }

    return ones + ms;
}

int main(){

    int t;
    cin>>t;
    int arr[100000];
    while(t--){

        int n;
        cin>>n;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<findSubarray(arr,n)<<endl;

    }

    return 0;
}
