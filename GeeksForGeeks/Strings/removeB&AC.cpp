#include <bits/stdc++.h>
using namespace std;



int main(){

     int t;
     string str;
     cin>>t;
     while(t--){
          
          cin>>str;
          
            int i;
            for( i = 0; str[i] != '\0' && i < str.size()-1; ){
                
                if(str[i] == 'a' && str[i+1] == 'c'){
                    //cout<<i<<" "<<str[0];
                    str.erase(str.begin()+i,str.begin()+i+2);
                }
                else if(str[i] == 'b'){
                    str.erase(str.begin()+i,str.begin()+i+1);
                }
                else{
                    i++;
                }
            }
            
            if(str[i] == 'b'){
                    str.erase(str.begin()+i,str.begin()+i+1);
            }
            
            if(str.size() <= 0){
                cout<<endl;
            }
            else
                cout<<str<<endl;
     }

     return 0;
}