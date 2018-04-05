#include <bits/stdc++.h>
using namespace std;


string encode(string str){

	unordered_map<string,string> hash;

	for(int i = 0; i < 26 ; i++){
		string s = "";
		s += i+97;
		hash[s] = to_string(i+1);
	}

	int idx = 27;
	string result = "";
	string ss = "";
	for(int i = 0; i < str.size(); ){

		if(hash.count(ss+str[i])){
			ss += str[i]; 
			i++;
		}
		else{
			result += hash[ss] + "0";
			hash[ss+str[i]] = to_string(idx); 
			idx++;
			ss.clear();
			ss = "";
		}
	}
	
	result += hash[ss] + "0";
	return result;
}

string decode(string str){

	string result = "";

	vector<string> v;
	v.push_back("$");
	for(int i = 0; i < 26; i++){
		string s = "";
		s += i+97;
		v.push_back(s);
	}

	int no = 0;
	int power = 1;
	string prev = "";
	string curr = "";
	for(int i = 0; i < str.size(); i++){

		if(str[i] == '0' && (i+1 == str.size() || str[i+1] != '0' )) {
			if(no == v.size()){
				prev = prev + prev[0];
				result += prev;
				v.push_back(prev);
				no = 0;
				power = 1;
				continue;
			}
			else if(no > v.size()){
				return "invalid";
			}
			
			result += v[no];
			
			if(prev == ""){
				prev = v[no];
			}else{
				curr = prev + v[no][0];
				//prev.clear();
				prev = v[no];
				v.push_back(curr);  
				//curr.clear(); 
			}
			no = 0;
			power = 1;
		}
		else{
			int x = str[i] - 48;
			no = no*power + x;
			power *= 10;
		}

	}

	string resultEncode = encode(result);
	//cout<<resultEncode<<" ";
	if(resultEncode.compare(str) == 0){
		return result;
	}
	
	return "invalid";

}

int main(){

	int t;
	cin>>t;
	while(t--){
	
		string str;
		cin>>str;

		cout<<decode(str)<<endl;

	}

	return 0;
}