#include <bits/stdc++.h>
using namespace std;


void print(string str) {
    
    queue<string> q;
    q.push(str);

    while(!q.empty()){
        
        str = q.front();

    	int pos = str.find('?');

    	if(pos < str.size()){
    		
    		str[pos] = '0';
    		q.push(str);

    		str[pos] = '1';
    		q.push(str);
    		
    	}
    	else{
    		cout<<str<<" ";
    	}

    	q.pop();

    }
}

int main(){

     int t;
     string str;
     cin>>t;
     while(t--){
          
          cin>>str;
          
          print(str);
          cout<<endl;
          
     }

     return 0;
}