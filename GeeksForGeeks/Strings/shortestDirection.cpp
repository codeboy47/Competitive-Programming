#include <bits/stdc++.h>
using namespace std;

void shortestDistance(char *str){

	int countE = 0, countW = 0, countN = 0, countS = 0;
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == 'E'){
			countE++;
		}
		else if(str[i] == 'W'){
			countW++;
		}
		else if(str[i] == 'N'){
			countN++;
		}
		else{
			countS++;
		}
	}

	if(countE > countW){
		countE -= countW;
		countW = 0;
	}
	else if(countW >= countE){
		countW -= countE;
		countE = 0;
	}

	if(countN > countS){
		countN -= countS;
		countS = 0;
	}
	else if(countS >= countN){
		countS -= countN;
		countN = 0;
	}

	string result = "";
	
	while(countE--){
		result += 'E';
	}
	while(countN--){
		result += 'N';
	}
	while(countS--){
		result += 'S';
	}	
	while(countW--){
		result += 'W';
	}

	cout<<result<<endl;
}


int main(){

    int t;
    char str[10000];
    cin>>t;
    while(t--){
          
        cin>>str;
          
        shortestDistance(str);
          
    }

    return 0;
}