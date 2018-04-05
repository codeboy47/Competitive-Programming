#include <bits/stdc++.h>
using namespace std;

// my method
void removeAdjacentDuplicates(string &str, int i, int n){

  if(str[i] == '\0' || str[i+1] == '\0'){
    return;
  }

  if(str[i] == str[i+1]){
      int j = i+1;
      while(str[i] == str[j])
          j++;
    str.erase(str.begin()+i,str.begin()+j);
    removeAdjacentDuplicates(str,i,n);
  }
    else
      removeAdjacentDuplicates(str,i+1,n);
      
  if(str.size() != n){
      removeAdjacentDuplicates(str,0,str.size());
  }
  
}

// gfg method
char* removeDup(char * str, int n)
{
    int len = strlen(str);
    int k = 0; // To store index of result
 
    // Start from second character and add
    // unique ones
    int i;
    for ( i=1; i< len; i++) {
        if (str[i-1] != str[i])
            str[k++] = str[i-1];
 
        else
            // Keep skipping (removing) characters
            // while they are same.
            while (str[i-1] == str[i])
                i++;
    }
 
    // Add last character and terminator
    str[k++] = str[i-1];
    str[k] =  '\0';
 
    // Recur for string if there were some removed
    // character
    if (k != n)
        removeDup(str, k);// Shlemial Painter's Algorithm
 
    // If all characters were unique
    else return str;
}

int main(){

    int t;
    string str;
    cin>>t;
    while(t--){
          
        cin>>str;
          
        removeAdjacentDuplicates(str,0,str.size());

        cout<<str<<endl;
    }

     return 0;
}