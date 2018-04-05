#include <bits/stdc++.h>
using namespace std;

// another important question
void findColNameFromColNo(long n){

	string str = "";

	while(n!=0){

		if(n%26 == 0){
			str += 'Z';
			n = (n-1)/26;
		}else{
		    str += 'A' + (n%26) - 1;
		    n = n/26;
        }
	}

	reverse(str.begin(),str.end());
	cout<<str<<endl;
}

int main(){

     int t;
     long n;
     cin>>t;
     while(t--){
          
          cin>>n;
          
          findColNameFromColNo(n);
          
     }

     return 0;
}