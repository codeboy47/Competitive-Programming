#include <bits/stdc++.h>
using namespace std;


bool checkLength(char *str){

	int i = strlen(str)-1;
	int no = 0;
	int power = 1;
	while(str[i] <= 57){
		int x = str[i] - 48;
		no += x*power;
        power *= 10;
		i--;
	}
	
	int len = i+1;

	if(no == len){
		return true;
	}
	return false;

}

int main(){

    int t;
    char str[10000];
    cin>>t;
    while(t--){
          
        cin>>str;
        
        checkLength(str) == true ? cout<<1<<endl : cout<<0<<endl;

          
    }

    return 0;
}