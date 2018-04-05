#include <bits/stdc++.h>
using namespace std;

// goldmann sach question. Ignore 1st solution

int findSubarrayCount(int arr[], int n, int k){

    int s = 0, e = 0, count1 = 0, p = arr[0], count = 0;

    while(e < n){

        if(p < k){
            e++;
            p *= arr[e];
        }
        else if(p > k){
            p /= arr[s];
            s++;
        }
        else{
            int i = s;
            while(i < e && arr[i] == 1)
                i++;
            count1 = i - s;
            count += count1 + 1;
            e++;
            if(e == n) break;

            p *= arr[e];
            if(arr[e] != 1){
                s = i;
            }

        }

        if(arr[e] == 0){
            s = e+1;
            e = s;
            p = arr[s];
        }
    }

    return count;

}

int findSubarrayCount2(int arr[], int n, int k){

    int s = 0, e = 0, p = arr[0], count = 0;

    while(e < n){

        if(p < k){
            e++;
            p *= arr[e];
        }
        else if(p > k){
            p /= arr[s];
            s++;
        }
        else{

            int count1 = 0;
            while(s < e && arr[s] == 1){
                s++;
                count1++;
            }

            while(e < n && p == k){
                count += (count1 + 1);
                e++;
                p *= arr[e]; // it means arr[e] is 1 if loop runs
            }

        }

        if(arr[e] == 0){
            s = e+1;
            e = s;
            p = arr[s];
        }
    }

    return count;
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int arr[10000];

        int n,k;
        cin>>n>>k;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<findSubarrayCount2(arr,n,k)<<endl;
    }

    return 0;
}


/* TEST CASES
6
5 24
1 2 3 4 1
ans : 4

5 4
1 0 4 1 1
ans : 3

6 4
2 1 1 1 4 5
ans : 4

8 4
2 1 1 4 1 1 2 2
ans : 12

9 8
4 2 2 2 2 8 1 1 2
ans : 6

5 4
1 1 4 1 1
ans : 9
*/
