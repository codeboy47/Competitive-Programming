 #include<iostream>
#include<cstring>
using namespace std;

void printSubset(char *str, char *subset, int index){
    if(*str == '\0'){
        cout<<subset<<endl;
        return;
    }
    printSubset(str+1,subset,index);
    subset[index] = *str;
    subset[index+1] = '\0';
    printSubset(str+1,subset,index+1);
    return;
}

int main(){
    char str[100],subset[100];
    subset[0] = '\0';
    cin.getline(str,100);
    printSubset(str,subset,0);
    return 0;
}

