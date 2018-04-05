#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll getDecimal(string s)
{
    ll len = s.length();
    ll ans = 0;
    ll j = 0;
    for (ll i = len - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            ans += pow(2, j);
        j += 1;
    }
    return ans;
}
 
// Utility function which convert decimal
// number to its binary representation
string convertToBinary(ll n)
{
    string temp;
    while (n > 0)
    {
        ll rem = n % 2;
        temp.push_back(48 + rem);
        n = n / 2;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
 
// utility function to check all the
// substrings and get the longest substring.
ll longestCommon(ll n, ll m)
{
    string str1 = convertToBinary(n);
    string str2 = convertToBinary(m);
    //cout<<str1<<" "<<str2<<" ";
    string res; 
    ll n1 = str1.length();
    ll n2 = str2.length();

    ll dp[n1+1][n2+1];

    ll len = 0, s = 0, maxVal= -1;
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                
                if(len < dp[i][j]){
                    len = dp[i][j];
                    res = str1.substr(i-len,len);
                    //cout<<s<<" "<<len<<" ";
                }
                else if(len == dp[i][j]){
                    string k = str1.substr(i-len,len);
                    ll newVal = getDecimal(k);
                    ll oldVal = getDecimal(res);
                    if(newVal > oldVal){
                        res = k;
                    }
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    
    //cout<<"j "<<res<<endl;
    if (res == "")
        return -1;
 
    return getDecimal(res);
}

int main(){
     
     
    int t;
    cin>>t;
     
     while(t--){
          ll n,m;
          cin>>n>>m;
          if(m > n){
              swap(n,m);
          }
          
          cout<<longestCommon(n,m)<<endl;
          
     }

     return 0;
}