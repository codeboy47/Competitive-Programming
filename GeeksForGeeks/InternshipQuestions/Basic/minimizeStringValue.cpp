#include <bits/stdc++.h>
using namespace std;

class compare{
public:
	bool operator () (pair<char, int> &p1, pair<char, int> &p2){
		return p1.second < p2.second;
	}
};

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


	priority_queue<pair<char,int> , vector<pair<char,int>> , compare > heap;
	for(auto it = hash.begin(); it != hash.end(); it++){
		heap.push(make_pair(it->first,it->second));
	}


	for(int i = 0; i < k; i++){
		pair<char,int> top = heap.top();
		if(top.second > 0){
		    heap.pop();
		   	heap.push(make_pair(top.first,top.second-1));
		}

	}

	int sum = 0;
	while(!heap.empty()){
		sum += pow(heap.top().second,2);
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
