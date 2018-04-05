#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> dp;

// top down dp approach
int isBreakable(unordered_map<string,bool> hash, string str, int idx){

    if(idx == str.size()){
        return 1;
    }

    string prefix = "";
    for(int i = idx; i < str.size(); i++){

        prefix += str[i];

        string suffix = str.substr(i+1,str.size());
        if(dp.count(suffix)){ // if remaining part of string is present in dp return result i.e no need to recur
            return dp[suffix];
        }

        if(hash[prefix]) {  // check if prefix is present in dictionary
            int ans = isBreakable(hash,str,i+1);
            dp[suffix] = ans;
            if(ans == 1){
                return 1;
            }
        }

    }

    return 0;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n; // no of words in dictionary
        cin>>n;

        unordered_map<string,bool> hash;
        for(int i = 0; i < n; i++){
            string s;
            cin>>s;
            hash[s] = true;
        }

        string str;
        cin>>str;

        cout<<isBreakable(hash,str,0)<<endl;

        dp.clear();
        hash.clear();
    }

    return 0;
}
