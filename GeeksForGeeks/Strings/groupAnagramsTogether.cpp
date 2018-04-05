#include <bits/stdc++.h>
using namespace std;


int countAnagrams(vector<string> v){

	unordered_map<string,int> hash;

	for(int i = 0; i < v.size(); i++){
		string temp(v[i]);
		sort(temp.begin(),temp.end());
		hash[temp]++;
	}

    vector<int> arr;
	for(auto it = hash.begin(); it != hash.end(); it++){
		arr.push_back(it->second);
	}

    sort(arr.begin(),arr.end());
    
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

     int t;
     vector<string> v;
     cin>>t;
     while(t--){
          
          int n;
          cin>>n;
          for(int i = 0; i < n; i++){
          		string s;
          		cin>>s;
          		v.push_back(s);
          }
          
          countAnagrams(v);
          v.clear();

          
     }

     return 0;
}