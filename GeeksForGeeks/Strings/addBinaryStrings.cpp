#include <bits/stdc++.h>
using namespace std;


void addBinary(string a, string b){

    string result = ""; 
    int s = 0;         
 
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);
 
        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;
 
        // Compute carry
        s /= 2;
        
        i--; j--;
    }
    cout<<result<<endl;
}


void addString(string str1, string str2){

	int n1 = str1.size()-1;
	int n2 = str2.size()-1;

	int i = n1, j = n2;

	int carry = 0;
	string res = "";
	while(i >= 0 && j >= 0){

		if(str1[i] == '0' && str2[j] == '0'){
			if(carry == 1){
				res += "1";
			}
			else{
				res += "0";
			}
			carry = 0;
		}
		else if(str1[i] == '0' && str2[j] == '1'){
			if(carry == 1){
				res += "0";
				carry = 1;
			}
			else{
				res += "1";
			}
		}
		else if(str1[i] == '1' && str2[j] == '0'){
			if(carry == 1){
				res += "0";
				carry = 1;
			}
			else{
				res += "1";
			}
		}
		else if(str1[i] == '1' && str2[j] == '1'){
			if(carry == 1){
				res += "1";
			}
			else{
				res += "0";
			}
			carry = 1;
		}

		i--;
		j--;
	}
	while(i >= 0){
		if(str1[i] == '1'){
			if(carry == 1){
				res += "0";
				carry = 1;
			}
			else{
				res += "1";
			}
			
		}
		else{
			if(carry == 1){
				res += "1";
			}
			else{
				res += "0";
			}
			carry = 0;
		}
		i--;
	}
	while(j >= 0){
		if(str2[j] == '1'){
			if(carry == 1){
				res += "0";
				carry = 1;
			}
			else{
				res += "1";
			}
			
		}
		else{
			if(carry == 1){
				res += "1";
			}
			else{
				res += "0";
			}
			carry = 0;
		}
		j--;
	}
	if(carry == 1){
	    res += "1";
	}

	reverse(res.begin(),res.end());

	cout<<res<<endl;
}

int main(){

     int t;
     string str1, str2;
     cin>>t;
     while(t--){
          
          cin>>str1>>str2;
          
          addString(str1,str2);
          
     }

     return 0;
}