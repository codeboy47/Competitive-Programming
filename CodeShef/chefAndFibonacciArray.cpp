#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

int countArrays(vector<int> &v, unordered_map<int,int> &hash, int n, int i){

	if(i == n-1){
          return 1;
     }
     if(v[i] == 0){
          return countArrays(v,hash,n,i+1);
     }

     int no = 0;
     for(int j = 0; j < n; j++){
          no = no*10 + v[j];
     }
     //cout<<no<<endl;
     if(hash.count(no)){
          return 0;
     }
     hash[no] = 1;


     int c = 0;
     for(int i = 0; i < n-1; i++){

          if(i < n-2 &&  v[i] > 0 && v[i+1] > 0){
               v[i]--;
               v[i+1]--;
               v[i+2]++;
               c = c + countArrays(v,hash,n,i) ;
               //cout<<"1 "<<c<<endl;
               v[i]++;
               v[i+1]++;
               v[i+2]--;
          }
          else if(i == n-2 && v[i] > 0 && v[i+1] > 0){
               v[i]--;
               v[i+1]--;
               v.push_back(1);
               c = c + countArrays(v,hash,n+1,i);
               //cout<<"2 "<<c<<endl;
               v.pop_back();
               v[i]++;
               v[i+1]++;
          }

     }

     return c+1;

}

int main(){

     vector<int> v;
     unordered_map<int,int> hash;
     int n;
     int t;
     scanf("%d", &t);
     while(t--){

          scanf("%d", &n);
          for(int i = 0; i < n; i++){
               int d;
               scanf("%d", &d);
               v.push_back(d);
          }
          cout<<countArrays(v,hash,n,0)<<endl;
          v.clear();
     }

     return 0;
}
