#include<bits/stdc++.h>
using namespace std;

// here we use concept of LIS

class points{
public:
    int p1;
    int p2;
    points() : p1(0) , p2(0) { }
    points(int x, int y) : p1(x) , p2(y) { }
};

bool compare(points &a, points &b){

    if(a.p1 == b.p1)
        return a.p2 < b.p2;

    return a.p1 < b.p1;

}

int maxBridges(int *arr1, int *arr2, int n){

        vector<points> v;

        for(int i = 0; i < n; i++){
            points p(arr1[i],arr2[i]);
            v.push_back(p);
        }

        sort(v.begin(),v.end(),compare);

        /*for(int i = 0; i < n; i++){
            cout<<v[i].p1<<" "<<v[i].p2<<" ";
        }*/


        int *dp = new int[n];
        for (int i=0; i<n; i++)
            dp[i] = 1;

        for(int i = 1; i < n; i++){
                int ans = 0;
                for(int j = i-1; j >= 0; j--){
                        if(v[i].p2 >= v[j].p2){
                                ans = max(ans,dp[j]);
                        }
                }
                dp[i] = 1+ans;
        }

        int bridges = dp[0];
        for(int i = 1; i < n; i++){
            bridges = max(bridges,dp[i]);
        }

        return bridges;
}


int main(){

        int t;
        cin>>t;
        while(t--){

                int arr1[10000], arr2[10000];
                int n;
                cin>>n;

                for(int i = 0; i < n; i++){
                        cin>>arr1[i];
                }

                for(int i = 0; i < n; i++){
                        cin>>arr2[i];
                }

                cout<<maxBridges(arr1,arr2,n)<<endl;

        }

        return 0;
}
