#include <iostream>
#include<cmath> 
#include<set>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	set<int> s;
	while(t--){
	    int n;
	    cin>>n;
	    for(int i = 1; i <= sqrt(n)+1; i++){
	        if(n%i == 0){
	            s.insert(i);
	            s.insert(n/i);
	            //cout<<i<<" "<<n/i<<" ";
	        }
	    }
	    set<int>::iterator it;
	    for(it = s.begin();it!=s.end();it++){
	        cout<<*it<<" ";
	    }
	    cout<<endl;
	    s.clear();
	}
	return 0;
}