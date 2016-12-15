#include <sstream>
#include <vector>
#include<string.h>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function
    vector<int> arr;
    char c = ','; // error ","
    int s=0,i,flag=0;
    for(i = 0; str[i] != '\0'; i++){
       if(str[i] == '-'){
           flag = 1;
       }
        else if(str[i] != c){
           s = (str[i]-48) + s*10;
           //arr.push_back(s);
       }
       else if(str[i] == c){
           if(flag == 1){
               s = s*(-1);
               flag = 0;
           }
           arr.push_back(s);
           s = 0;
       }
   }
    if(flag == 1){
               s = s*(-1);
               flag = 0;
    }
    arr.push_back(s); // error mising last term
    /*
     while(*str!='\0'){
       if(strcmp(str,",") != 0){
           c = str[i]-48;
           arr.push_back(c);
       }
       if(strcmp(str,",") == 0){
          cout<<endl;
       }
         str++;
      }*/

    return arr;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
