#include <bits/stdc++.h>
using namespace std;

bool search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
 
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j == M) 
            return true;
    }
    
    return false;
}

int main(){

     int t;
     char str[10000],patt[10000];
     cin>>t;
     while(t--){
          
          cin>>str>>patt;
          
          bool ans  = search(patt,str);
          ans ? cout<<"found"<<endl : cout<<"not found"<<endl;
          
     }

     return 0;
}