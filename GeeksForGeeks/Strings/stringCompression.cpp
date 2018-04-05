#include <bits/stdc++.h>
using namespace std;

int stringCompare(char *str1, char *str2){
    
    int i = 0, j = 0;
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    while(i < n1  && i < n2){
        
        if(i > 0){
            

            if(str1[i-1] == 'n' && str1[i] == 'g'){
                if(str2[i-1] >= 'o'){
                    return -1;
                }
                else{
                    return 1;
                }
            }
            else if(str2[i-1] == 'n' && str2[i] == 'g'){
                if(str1[i-1] >= 'o'){
                    return 1;
                }
                else{
                    return -1;
                }
            }
            else if(str1[i] > str2[i]){
                        //cout<<"1"<<endl;
                return 1;
            }
            else
            {
                        //cout<<"-1"<<endl;
               return -1;
            }
        }
        else{
            
            if(str1[i] < str2[i]){
                return -1;
            }
            else{
                return 1;
            }
        }
        
        i++;
    }
   
   
        if(i < n1){
            return 1;
        }
        else if(i < n2){
            return -1;
        }
        return 0;
    
}

int main(){

     int t;
     char str1[10000], str2[10000];
     cin>>t;
     while(t--){
          
          cin>>str1>>str2;
          
          cout<<stringCompare(str1,str2)<<endl;
          
     }

     return 0;
}