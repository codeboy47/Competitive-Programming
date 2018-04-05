#include <iostream>
#include <algorithm>
using namespace std;


// time complexity is O(n) and space complexity is O(d)
void rotateUsingTempArray(int *arr, int n, int d){

	int * temp = new int[d];
	int i;
	for(i = 0; i < d; i++){
		temp[i] = arr[i];
	}
	for( i = 0; i < n-d; i++){
		arr[i] = arr[i+d];
	}
	int k = 0;
	for(; i < n; i++){
		arr[i] = temp[k++];
	}

	for(int i = 0; i < n; i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
}

// time complexity is O(n*d) and space complexity is O(1)
void leftRotate(int *arr, int n, int d){
	for(int k = 0; k < d; k++){
	    for(int i = 1; i < n; i++){
		   swap(arr[i],arr[i-1]);
	    }
	}

	for(int i = 0; i < n; i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int GCD(int a, int b){
	if(b == 0){
		return a;
	}
	return GCD(b,a%b);
}

// time complexity is O(n) and space complexity is O(1)
void jugglingAlgorithm(int *arr, int n, int d){

	int gcd = GCD(n,d);

	for(int i = 0; i < gcd; i++){
		int j = i;
		int k = i;
		int temp = arr[i];
		do{
			j = k;
			k = (j + d)%n;
			arr[j] = arr[k];
			//swap(arr[j],arr[k]);
		}while(k != i);
		arr[j] = temp;
		//swap(arr[j],temp);
	}

	for(int i = 0; i < n; i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;

}

void reverse(int *arr, int s, int e){
	while(s < e){
		swap(arr[s],arr[e]);
		s++;
		e--;
	}
}
// time complexity is O(n) and space complexity is O(1)
void reversalAlgorithm(int *arr, int n, int d){
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);

	for(int i = 0; i < n; i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void swap(int *arr, int s1, int s2, int d){
	int i = 0;
	while(i < d){
		swap(arr[s1],arr[s2]);
		s1++;
		s2++;
		i++;
	}
}
// time complexity is O(n) and space complexity is O(1)
void blockSwapAlgorithm(int arr[], int n, int d){

    if(d == 0 || d == n){
        for(int i = 0; i < n; i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	    return;
    }

	int i = d; // size of 1st subarray
	int j = n-d; // size of 2nd part
	while(i != j){
		if(i < j){ // A  <  B
			swap(arr,d-i,j+d-i,i); // as i is always  < d
			j = j - i;
		}
		else{  // A > B
			swap(arr,d-i,d,j);
			i = i - j;
		}
	}
	swap(arr,d-i,d,i) ;

	for(int i = 0; i < n; i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int t;
     int arr[10000];
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         for(int i = 0; i < n; i++){
             cin>>arr[i];
         }

         int d;
         cin>>d;

	    blockSwapAlgorithm(arr,n,d);

     }
	return 0;
}
