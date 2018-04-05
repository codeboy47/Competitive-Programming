#include <bits/stdc++.h>
using namespace std;

// asked in yahoo
void nextGreaterEvenNo(string str){

	int n  = str.size();

    int *v = new int[n];
	for(int i = 0; i < n; i++){
		v[i] = str[i]-48;
	}
	
	int i;
	while(1){
	    
		for(i = n-2; i >= 0; i--){

			if(v[i] < v[i+1]){
	            break;	
			}
		}

		if(i == -1){
			cout<<-1<<endl;
			return;
		}
	
		int nextGreater = INT_MAX;
		int idx = -1;
		for(int j = i+1; j < n; j++){
			if(v[i] < v[j] && nextGreater > v[j]){
				nextGreater = v[j];
				idx = j;
			}
		}

		
		swap(v[i],v[idx]);

		sort(v+i+1,v+n);
		
        if(v[n-1]%2 == 0){
   			for(int j = 0; j < n; j++){
    			cout<<v[j];
    		}
    		cout<<endl;
            return;        
        }
    }

}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
        cin>>str;
          
        nextGreaterEvenNo(str);
     }

     return 0;
}