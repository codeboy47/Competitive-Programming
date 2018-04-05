#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int noOfDigits(ll n){
    int count = 0;
    while(n != 0){
        count++;
        n /= 10;
    }
    return count;
}

void printNosWithAbsoluteDiff(int digits, ll val, ll n){
    
    if(val == 0){
        for(int i = 1; i <= 9; i++){
            printNosWithAbsoluteDiff(digits-1,val+i,n);
        }
        return;
    }
    
    if(val*pow(10,digits) > n){
        return;
    }
    
    if(digits == 0){
        cout<<val<<" ";
        return;
    }

    if(val%10 > 0){
        printNosWithAbsoluteDiff(digits-1,val*10 + (val%10) - 1,n);
    }
    if(val%10 < 9){
        printNosWithAbsoluteDiff(digits-1,val*10+ (val%10) + 1,n);
    }
}


int main(){

     int t;
     char str[10000];
     ll n;
     cin>>t;
     while(t--){
          
          cin>>n;
          
          int countDigits = noOfDigits(n);

          if(countDigits == 1){
                cout<<-1;
          }
          else{
                for(int i = 2; i <= countDigits; i++){
                    printNosWithAbsoluteDiff(i,0,n);
                } 
          }
          
          cout<<endl;
     }

     return 0;
}