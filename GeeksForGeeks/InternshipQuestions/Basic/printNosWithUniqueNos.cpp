#include <bits/stdc++.h>
using namespace std;

void printNosWithUniqueDigits(int s, int e){

    unordered_map<int,bool> hash;

    for(int i = s; i <= e; i++){
        int no = i;
        if(no < 10){
            cout<<no<<" ";
        }
        else{
            while(no!=0){
                if(!hash.count(no%10)){
                    hash[no%10] = true;
                }
                else{
                    break;
                }
                no /= 10;
            }
            if(no == 0){
                cout<<i<<" ";
            }
        }
        hash.clear();
    }
    cout<<endl;
}

int main(){

    int t;
    cin>>t;
    while(t--){

          int s,e;
          cin>>s>>e;

          printNosWithUniqueDigits(s,e);


    }

    return 0;
}
