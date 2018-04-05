#include <bits/stdc++.h>
using namespace std;

string recurringSequence(int num, int den){

    string res = "";
    unordered_map<int,int> hash;
    
    int rem = num%den;
    while(rem != 0 && !hash.count(rem)){
        
        hash[rem] = res.size(); 
        
        rem *= 10; 
        num = rem; 
        
        res += to_string(num/den); 
        
        rem = num%den;

    }

    return rem == 0 ? "" :
    res = res.substr(0,hash[rem]) + "(" + res.substr(hash[rem]) + ")";

}


int main() {

    int t,num,den;
    cin>>t;

    while(t--){

        cin>>num;
        cin>>den;

        string s = recurringSequence(num,den);
        string ans = "";

        if(s == ""){
            cout<<num/(float)den<<endl;
        }
        else{
            ans = to_string(num/den)+ "." + s;
            cout<<ans<<endl;
        }

    }

    return 0;
}


