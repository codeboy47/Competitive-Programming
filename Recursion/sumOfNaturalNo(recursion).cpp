#include <iostream>
using namespace std;

int sum(int n){
	if(n == 0){
		return 0;
	}if(n == 1){
		return 1;
	}
	return (n + sum(n-1));

}

int main() {
	// your code goes here
	int n;
	cin>>n;
	cout<<sum(n);
	return 0;
}
