#include <bits/stdc++.h>
using namespace std;

void rollingCharacters(string str, int *arr, int n){

	int count[n] = { 0 };
	//int *count = new int[n];
	//memset(count,0,sizeof(int)*n); 
	for(int i = 0; i < n; i++){
		count[arr[i]-1]++ ;

	}
    
	for(int i = n-2; i >= 0; i--){
		count[i] += count[i+1]; 
	}
    
    string result = "";
	for(int i = 0; i < n; i++){
	    result += (count[i]+str[i]%97)%26+97;
	    //cout<<char((count[i]+str[i]%97)%26+97);
			
	}

	cout<<result<<endl;
}

int main(){

	int t;
	int arr[1000];
	string str;
	cin>>t;
	while(t--){

		int n;
		cin>>n;

		cin>>str;

		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}

		rollingCharacters(str,arr,n);
		
		
	}
	return 0;
}