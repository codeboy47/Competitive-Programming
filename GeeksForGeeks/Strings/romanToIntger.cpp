#include <bits/stdc++.h>
using namespace std;

int getValue(char r){
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}

void romanNoIntoInteger(string str){

	int sum = 0;
	for(int i = 0; i < str.size(); i++){

		int value = getValue(str[i]);

		if(i < str.size()-1){
			int nextValue = getValue(str[i+1]);
			if(nextValue > value){
				value = nextValue - value;
				i++;
			}
		}
		
		sum += value;
	}

	cout<<sum<<endl;

}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          romanNoIntoInteger(str);
          
     }

     return 0;
}