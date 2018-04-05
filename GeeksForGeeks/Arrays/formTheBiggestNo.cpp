#include <bits/stdc++.h>
#include <string>
using namespace std;

bool compares(string x, string y){

     string xy = x + y;
     string yx = y + x;

     if(xy.compare(yx) > 0){
         return true;
     }
     else{
         return false;
     }

}


void makeGreatestNumber(vector<string> &arr, int n){

     sort(arr.begin(),arr.end(), compares );

     for(int i = 0; i < n; i++){
          cout<<arr[i];

     }

     cout<<endl;

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
            //cout<<1<<endl;
          makeGreatestNumber(arr,n);
          arr.clear();
     }

     return 0;
}
