#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

int findMinLength(vector<string> &arr){

     int ans = INT_MAX;
     for(int i = 0; i < arr.size(); i++){
          int l = arr[i].length();
          ans = min(ans,l);
     }
     return ans;
}

// method 1
string commonPrefix(vector<string> &arr, int n){

     int minLen = findMinLength(arr);
     string ans = "\0";

     for(int i = 0; i < minLen; i++){

          char ch = arr[0][i];

          int j;
          for( j = 1; j < n; j++){
               if(arr[j][i] != ch){
                    return ans;
               }
          }
          ans.push_back(ch);
     }

     return ans;

}

string commonPrefixHelper(string s1, string s2){

     int l1 = s1.size();
     int l2 = s2.size();

     string ans = "\0";
     for(int i = 0, j = 0; i < l1 && j < l2; i++,j++){
          if(s1[i] != s2[j]){
               break;
          }
          ans.push_back(s1[i]);
     }
     return ans;
}

// method 2
string commonPrefixDivideAndConquer(vector<string> &arr, int s, int e){

     if(s == e){
          return arr[s];
     }
     if(s < e){
          int mid = (s+e)/2;
          string s1 = commonPrefixDivideAndConquer(arr,s,mid);
          string s2 = commonPrefixDivideAndConquer(arr,mid+1,e);
          return commonPrefixHelper(s1,s2);
     }
}

int main(){

    int t;
    cin>>t;
    vector<string> arr;

    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            string s;
            cin>>s;
            arr.push_back(s);
        }

        string str = commonPrefixDivideAndConquer(arr,0,n-1);

        if(str == "\0"){
             cout<<"-1"<<endl;
        }
        else{
             cout<<str<<endl;
        }

        arr.clear();
    }
	return 0;
}
