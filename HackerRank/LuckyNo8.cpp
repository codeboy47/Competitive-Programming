#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector<long> subset;
long printSubsets(vector<long> &v,long index){
	long count = 0;
	static long no = 0;
	for(int i = index; i < v.size(); i++){
        long no2 = no;
		subset.push_back(v[i]); 
		no = no*10 + v[i]; // 9 90+6 960+8
		if(no%8 == 0){
				const long c = 1e9+7;
				count = (count+1)%c;
		}
		count =  printSubsets(v,i+1) + count;
        no = no2;
		subset.pop_back();	
	}
	return count;
}/*
long printSubsets(vector<long> &v,long index){
	long count = 0,no;
	
	for(int i = index; i < v.size(); i++){
		subset.push_back(v[i]); 
		no = 0;
		for(int j = 0;j < subset.size();j++){
			no = subset[j] + no*10;
		}
		if(no%8 == 0){
				//cout<<" "<<no<<"    ";
				const long c = 1e9+7;
				count = (count+1)%c;
		}
		count =  printSubsets(v,i+1) + count;
		subset.pop_back();	
	}
	return count;
}*/

int main() {
	long number,n,count;
	cin>>n>>number;
    vector<long> v;
    stack<long> s;
    for(long i = 0;i < n;i++){
   		long a = number%10;
   		s.push(a);
   		number = number/10;
    }
    while(!s.empty()){
    	v.push_back(s.top());
    	s.pop();
    }
    printf("%d",printSubsets(v,0));
    return 0;
}

/*	if input number is string then
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
	long static count = 0;
void printSubset(char * str, char *subset, int index) {
   
    if (*str == '\0') {
    	//str = "968";
        int no = atoi(subset);
        //printf("%d ",no);
    	if(no%8 == 0){
				const long c = 1e9+7;
				count = (count+1)%c;
               // printf("%d ",count);
		}
          return ;
    }
   
    printSubset(str+1, subset, index);

    subset[index] = *str;
    subset[index+1] = '\0';
    printSubset(str+1, subset, index+1);
  
    return ;
}
int main(){
    int n; 
    scanf("%d",&n);
    char* number = (char *)malloc(512000 * sizeof(char));
    char* subset = (char *)malloc(512000 * sizeof(char));
    subset[0] = '\0';
    scanf("%s",number);
   printSubset(number,subset,0);
    printf("%ld",count-1);
    // your code goes here
    return 0;
}
*/