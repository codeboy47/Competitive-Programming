#include <bits/stdc++.h>
using namespace std;

void createLPS(int *lps, char *pat){

  	int j = 0;
  	lps[0] = 0;
  	for(int i = 1; i < strlen(pat); i++){

  		if(pat[i] == pat[j]){
  			lps[i] = j + 1;
  			j++;
  		}
  		else{
  			if(j > 0){
  			    j = lps[j-1];
  			    i--;
  			}
  			else{
  				lps[i] = 0;
  			}
  			
  		}
  	}
}



int main(){

     int t;
     char str[100000];
     int arr[100000];
     cin>>t;
     while(t--){
          
          cin>>str;
          int maax = -1;
          createLPS(arr,str);
          //computeLPSArray(str,strlen(str),arr);
          
          int n = strlen(str);
          
          for(int i = 0; i < n; i++){
              cout<<arr[i]<<" ";
          }
          cout<<arr[n-1]<<endl; //  it wants your answer to be for whole string.
          
     }

     return 0;
}