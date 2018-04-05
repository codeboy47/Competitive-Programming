#include <bits/stdc++.h>
using namespace std;

void factorialOfLargeNo(int *arr, int &n){

	int carry = 0;
	int arrSize = 1;
	arr[0] = 1;
	for(int i = 2; i <= n; i++){

		int j, carry = 0;
		for(j = 0; j < arrSize; j++){
			int temp = arr[j]*i + carry;
			arr[j] = (arr[j]*i + carry)%10;
			carry = temp/10;
		}
		
		while(carry){
       		arr[j] = carry%10;
       		carry /= 10;
       		j++;
        }

		arrSize = j;

	}
    
	n = arrSize;

}

int main(){

    int t;
    int n;
    int arr[10000];
    cin>>t;
    while(t--){
    
        cin>>n;
        
        factorialOfLargeNo(arr,n);

        for(int i = n-1; i >= 0; i--){
        	cout<<arr[i];
    	}    
    	cout<<endl;
    }

    return 0;
}