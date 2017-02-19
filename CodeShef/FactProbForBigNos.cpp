// How to store big numbers as built in data types failed to store very large numbers
// https://discuss.codechef.com/questions/7992/how-can-i-store-very-very-large-integers-accurately
// We can understand this by calculating factorial of very large nos like 100
// long long int can only store upto factorial of 20 only
// so we use array to store digits of no : one digit per position

#include<iostream>
#include<vector>
using namespace std;

int main(){
	//vector<int> arr;
	int arr[200]; // for storing digits of number
	int m; // for current size of array
	int temp; // for storing carry of number greater than 9
	int n,i,j,x,t;
	cin>>t;
	while(t--){
		m = 1;
		//arr.push_back(1);
		arr[0] = 1;
		cin>>n; // enter no
		for(i = 1;i <= n;i++){
			temp = 0;
			for(j = 0;j < m;j++){
				x = i*arr[j]+temp; // add temp here not in next line
				arr[j] = x%10;
				temp = x/10;
				
			}
			while(temp > 0){
				//arr.push_back(temp);
				arr[m] = temp%10;
				temp = temp/10;
				m++;
				
			}
		}
		for(i = m-1;i>=0;i--){
			cout<<arr[i];
		}
		cout<<endl;
	}

	/*long long int i,no = 21,product = 1;
	for(i = 1;i <= no;i++){
		product *= i;
	}
	cout<<product;*/
}