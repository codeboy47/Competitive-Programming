#include <bits/stdc++.h>
using namespace std;

void printZigZag(string str, int n){

    if (n == 1){
        cout<<str<<endl;      
        return;
    }
    
	vector<string> v;
	for(int i = 0; i < n; i++){
		v.push_back("");
	}

	int k = 0;
	bool flag = false;
	for(int i = 0; i < str.size(); i++){
		
		if(flag == true){
			k--;
		}
		v[k] += str[i];
		if(flag == false){
			k++;
		}
		if(k == 0){
		    k++;
			flag = false;
		}
		if(k == n){
			k--;
			flag = true;
		}
	}

	string res = "";
	for(int i = 0; i < n; i++){
		res += v[i];
	}

	cout<<res<<endl;

}

int main(){

     int t;
     string str;
     cin>>t;
     while(t--){
          
          int n;
          cin>>str>>n;
          
          printZigZag(str,n);
          
     }

     return 0;
}