#include <bits/stdc++.h>
using namespace std;


int minimizeStringValue(char *str, int k){

	unordered_map<char,int> hash;
	for(int i = 0; i < strlen(str); i++){
		if(hash.count(str[i]) == 0){
			hash[str[i]] = 1;
		}
		else{
			hash[str[i]]++;
		}
	}


	priority_queue<int> heap; 
	for(auto it = hash.begin(); it != hash.end(); it++){
		heap.push(it->second);
	}

	
	for(int i = 0; i < k; i++){
		int top = heap.top();
		if(top > 0){
		    heap.pop();
			heap.push(top-1);
		}
	}

	int sum = 0;
	while(!heap.empty()){
		sum += pow(heap.top(),2);
		heap.pop();
	}
	return sum;
}

int main(){

    int t;
    char str[10000];
    cin>>t;
    while(t--){
          
        cin>>str;
        int k;
        cin>>k;
        cout<<minimizeStringValue(str,k)<<endl;
    }

    return 0;
}