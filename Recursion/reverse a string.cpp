#include<iostream>
#include<string.h>
using namespace std;

void reverseString(char *str, int start, int end){
    if(start >= end){
        return;
    }else{
        char t = str[start];
        str[start] = str[end];
        str[end] = t;
        reverseString(str,start+1,end-1); // not start++ end--
    }
    return; // not necessary in void function
}

int main(){
    char str[100];
    cin.getline(str,100);
    reverseString(str,0,strlen(str)-1);
    cout<<str;
    return 0;
}
