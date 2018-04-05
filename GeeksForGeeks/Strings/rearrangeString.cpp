#include <bits/stdc++.h>
using namespace std;


void rearrangeString(string str){

	int hash[26] = {0};

	int sum = 0;
	for(int i = 0; i < str.size(); i++){

		if(str[i] >= 'A' && str[i] <= 'Z'){
			hash[str[i]-'A']++;
		}
		else{
			sum += str[i] - 48;
		}
	}

	string res = "";
	for(int i = 0; i < 26; i++){

		while(hash[i]--)
			res += i + 'A';
	}

	res += to_string(sum);
	cout<<res<<endl;
}

int main(){

     int t;
     string str;
     cin>>t;
     while(t--){
          
     	  cin>>str;
          
          rearrangeString(str);

          
     }

     return 0;
}