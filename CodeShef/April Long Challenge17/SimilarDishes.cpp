#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
using namespace std;


int main(){
	int t,count = 0;
	int i , j ,k;
	vector<string> arr1; // to store array of strings like this : eggs sugar flour salt
	vector<string> arr2;
	char str1[100];
	char str2[100];
	scanf("%d",&t);
	while(t--){
		count = 0;
		bool flag = false;
		for( i = 0; i < 4; i++){
			cin>>str1;
			//cin.getline(str1,100);
			arr1.push_back(str1);
		}
		for( i = 0; i < 4; i++){
			cin>>str2;
			//cin.getline(str2,100);
			arr2.push_back(str2);
		}
		//cout<<" -- "<<arr1[1].length()<<" -- ";
		for( i = 0; i < 4; i++){
			for( j = 0; j < 4 ; j++){
				for( k = 0; arr1[i][k] != '\0' && arr2[j][k] != '\0' ; ){
					if(arr1[i][k] == arr2[j][k]){
						k++;
					}
					if(arr1[i][k] != arr2[j][k]){
						break;
					}
				}
				if(k == arr1[i].length() && k == arr2[j].length()){
					count++;
					break;
				}
			}
			if(count >= 2){
				flag = true;
				break;
			}
		}
		if(flag == true){
			printf("similar\n");
		}else{
			printf("dissimilar\n");
		}
		arr1.clear();
		arr2.clear();
	}
	return 0;
}