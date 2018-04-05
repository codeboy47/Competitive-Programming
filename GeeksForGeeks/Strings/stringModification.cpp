#include <bits/stdc++.h>
using namespace std;

class compare{
public:
	bool operator () (pair<char,int> &p1, pair<char,int> &p2){
		return p1.second < p2.second;
	}
};

// using priority_queue
string rearrangeString1(string str){

	unordered_map<char,int> hash;
    for(int i = 0; i < str.size(); i++){
        if(hash.count(str[i]) == 0){
            hash[str[i]] = 1;
        }
        else{
            hash[str[i]]++;
        }
    }

    priority_queue< pair<char,int> , vector<pair<char,int>>, compare > maxHeap;
    for(auto it = hash.begin(); it != hash.end(); it++){
        maxHeap.push(make_pair(it->first,it->second));
    }

    string result = "";
    while(!maxHeap.empty()){

    	pair<char,int> p = maxHeap.top();
    	maxHeap.pop();
    	result += p.first;
    	p.second--;
    	
    	pair<char,int> sp;
    	if(!maxHeap.empty()){
    		sp = maxHeap.top();
    		maxHeap.pop();
    		result += sp.first;
    		sp.second--;
    	}
    	
    	if(p.second > 0)
    		maxHeap.push(p);
    	if(sp.second > 0)
    		maxHeap.push(sp);

    }

    return result;

}

bool compare(pair<char,int> &p1, pair<char,int> &p2){
    return p1.second > p2.second; 
}

// my method -  Long complicated
string rearrangeString2(string str)
{
    unordered_map<char,int> hash;
    vector<pair<char,int>> v;
    for(int i = 0; i < str.size(); i++){
        if(hash.count(str[i]) == 0){
            hash[str[i]] = 1;
        }
        else{
            hash[str[i]]++;
        }
    }
    
    str.clear();
    str = "";
    for(auto it = hash.begin(); it != hash.end(); it++){
        v.push_back(make_pair(it->first,it->second));
    }
    
    
    
    sort(v.begin(),v.end(),compare);
    
    for(int i = 0; i < v.size(); i++){
        while(v[i].second--){
            str += v[i].first;
        }
    }
    
    int fp = 1, sp = 1;
    for(sp = 1; sp < str.size(); sp++){
        
        if(str[fp] != str[sp]){
           swap(str[fp],str[sp]);
           fp = fp+2;
           
        }
    }
    
    int n = str.size()-1;
    if(str[n] == str[n-1]){
        if(n-2 >= 0){
            swap(str[n-2],str[n-1]);
        }
    }
    
   return str;
}


int main(){

    int t;
    string str;
    cin>>t;
   
    while(t--){
          
        cin>>str;
        
        string result = rearrangeString1(str);

        int i;
        for( i = 0; i < result.size()-1; i++){
        	if(result[i] == result[i+1]){
        		cout<<0<<endl;
        		break;
        	}  
    	}

    	if(i == result.size()-1){
    		cout<<1<<endl;
    	}

    }
    
    return 0;
}