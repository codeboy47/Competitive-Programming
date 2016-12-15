#include<iostream>
#include<string.h>
using namespace std;
string removeConsDuplicates(char *str){
    static int i = 0;
    if(i < strlen(str)){
        if(str[i] == str[i+1]){
            for(int j = i;j<=strlen(str);j++){
                str[j] = str[j+1];
            }
        }
        i++;
        return removeConsDuplicates(str);
    }else{
        return str;
    }

}
/*
string removeConsDuplicates(char *str){
    int i = 0;
    while(i < strlen(str)){
        if(str[i] == str[i+1]){
            for(int j = i;j<=strlen(str);j++){
                str[j] = str[j+1];
            }
        }
        i++;
    }
    return str;
}
*/
int main(){
    char str[100];
    cin.getline(str,100);
    string s = removeConsDuplicates(str);
    cout<<s;
}
