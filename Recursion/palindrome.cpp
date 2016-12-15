#include <iostream>
#include<string.h>
using namespace std;

bool palin(char *str,int start, int end){
	if(start >= end) return true;
	else if(str[start] == str[end])
		return palin(str,start+1,end-1);
	else return false;
}
int main() {

	//string str; // we declare string to get input use cin>>
	// to get length use str.length() in string file
	char str[1000]; // we declare character array
	cin.getline(str,1000);
	cout<<palin(str,0,strlen(str)-1);
	return 0;
}
