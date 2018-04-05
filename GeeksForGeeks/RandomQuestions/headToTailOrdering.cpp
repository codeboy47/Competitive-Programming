#include <iostream>
#include <vector>
using namespace std;

bool canPossible(vector<string> v, bool *visited, string str, int k, int n){

     if(n == k)     return true;

     for(int i = 0; i < n; i++){

          if(!visited[i] && str[str.size()-1] == v[i][0]){
               visited[i] = true;
               if(canPossible(v,visited,v[i],k+1,n)){
                    return true;
               }
               visited[i] = false;
          }

     }

     return false;

}


int main(){

     int t;
     cin>>t;
     while(t--){

          vector<string> v;
          int n;
          cin>>n;
          bool *visited = new bool[n];

          for(int i = 0; i < n; i++){
          	string s;
          	cin>>s;
          	v.push_back(s);
               visited[i] = false;
          }


          bool flag = false;
          for(int i = 0; i < n; i++){
               visited[i] = true;
               if(canPossible(v,visited,v[i],1,n)){
                    flag = true;
                    break;
               }
               visited[i] = false;
          }

          if(flag == true){
               cout<<"Head to tail ordering is possible."<<endl;
          }else{
               cout<<"Head to tail ordering is not possible."<<endl;
          }
     }

     return 0;
}
