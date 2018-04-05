#include <iostream>
#include <unordered_map>
using namespace std;

void countDistinct(int A[], int k, int n){

     unordered_map<int,int> hash;

     for(int i = 0; i < k-1; i++){
          if(!hash.count(A[i])){
               hash[A[i]] = 1;
          }else{
               hash[A[i]]++;
          }
     }

     int ptr = 0;

     for(int i = k-1; i < n; i++){
          if(!hash.count(A[i])){
               hash[A[i]] = 1;
          }
          else{
               hash[A[i]]++;
          }

          cout<<hash.size()<<" ";

          hash[A[ptr]]--;
          if(hash[A[ptr]] == 0){
               hash.erase(A[ptr]);
	     }

          ptr++;

     }

     for(auto it = hash.begin(); it != hash.end(); it++){
     	cout<<it->first<<" "<<it->second<<endl;
     }

}

int main(){

     int t;
     int arr[100000];
     cin>>t;
     while(t--){
          int n,k;
          cin>>n>>k;
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          countDistinct(arr,k,n);
          cout<<endl;
     }

     return 0;

}
