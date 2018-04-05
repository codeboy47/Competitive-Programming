// Given an array and a number k, find the largest sum of the subarray containing at least k numbers. It may be assumed
// that the size of array is at-least k.

// this is not a dp question

#include <bits/stdc++.h>
using namespace std;

// time complexity is O(n)
int maxLeftSubArraySum(int arr[], int n, int k){

    int cs = arr[0];
    int maxSumSoFar[10000];
    maxSumSoFar[0] = arr[0];
    for(int i = 1; i < n; i++){
        cs = max(arr[i], cs + arr[i]);
        maxSumSoFar[i] = cs;
    }

    int i;
    cs = 0;
    for( i = 0; i < k; i++){
        cs += arr[i];
    }

    int ms = cs;
    int j = i;
    i = 0;
    while(j < n){
        cs = cs + arr[j] - arr[i];
        ms = max(ms,max(cs,cs + maxSumSoFar[i]));
        i++;
        j++;
    }

    return ms;

}


// time complexity is O(n^2)
int maxLeftSubArraySum2(int arr[], int n, int k){

    int ans = INT_MIN;
    for(int j = 0; j <= n-k; j++){
        int cs = 0;
        int ms = INT_MIN;

        int i;
        for( i = j; i < j+k; i++){
            cs += arr[i];
        }

        ms = max(ms,cs);
        for( ; i < n; i++){
            cs += arr[i];
            ms = max(ms,cs);

        }

        ans = max(ans,ms);
    }

    return ans;
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        int arr[20000];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        int k;
        cin>>k;

        cout<<maxLeftSubArraySum(arr,n,k)<<endl;
    }

    return 0;
}
