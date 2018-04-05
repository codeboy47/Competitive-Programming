#include <bits/stdc++.h>
using namespace std;

// maths and bits question

int countPairs(int arr[], int n, int x){

    unordered_map<int,int> hash;

    for(int i = 0; i < n; i++){
        hash[arr[i]] = true;
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        int no = x^arr[i];
        if(no != arr[i] && hash[no] == true){
            hash[arr[i]] = false;
            hash[no] = false;
            count++;
        }
    }

    return count;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        int arr[10000];
        for(int i = 0; i < n; i++)
            cin>>arr[i];

        int x;
        cin>>x;

        cout<<countPairs(arr,n,x)<<endl;

    }

    return 0;
}
