#include <bits/stdc++.h>
using namespace std;


bool isValid(int A, long mid, vector<int> C){

	int painters = 1;
	long total = 0;
	for(long i = 0; i < C.size(); i++){

		if(C[i] > mid){
			return false;
		}

		else if(total + C[i] <= mid){
			total += C[i];
		}

		else if(total + C[i] > mid){
			painters++;
			total = C[i];
		}

		//If you run out of painters, isValid = false else isValid = true.
		if(painters > A){
		    return false;
		}

	}

	return true;

}


int paint(int A, vector<int> &C) {

	long sum = 0;
	for(long i = 0; i < C.size(); i++){
		sum += C[i];
	}

	long s = 0, e = sum, mid;

    long ans = INT_MAX;
	while(s <= e){

		 mid = (s+e)/2;

		if(isValid(A,mid,C)){
			ans = min(ans,mid);
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}

	return ans;

}


int main(){

    int t;
    cin>>t;
    while(t--){

        int k,n;
        cin>>k>>n;

        vector<int> v;
        for(int i = 0; i < n; i++){
            int d;
            cin>>d;
            v.push_back(d);
        }

        cout<<paint(k,v)<<endl;
        v.clear();
    }

    return 0;
}
