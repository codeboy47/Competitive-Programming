#include <iostream>
#include <list>
#include <string.h>
#include <queue>
#include <unordered_map>
using namespace std;

template<typename T>
class graph{
public :
     int vertices;
     unordered_map<T, vector<T> > hash;


    graph() { }
     graph(int v){
          vertices = v;
     }
     void addEdge(T u, T v){
          hash[u].push_back(v);
          vertices = hash.size();
     }


     bool dfsHelper(T src, unordered_map<T,bool> &visited, int count, int n){
          visited[src] = true;
          //cout<<src<<" ";
          if(count == n){
          	return true;
          }

          if(hash.count(src) != 0){
               for(int i = 0; i < hash[src].size(); i++){
               	//cout<<hash[src][i]<<" ";
                    if(!visited[hash[src][i]]){
                         if(dfsHelper(hash[src][i],visited,count+1,n)){
                         	return true;
                         }
                    }
               }
          }
          /* OR
          for(auto it = hash[src].begin(); it != hash[src].end(); it++){
               if(!visited[*it]){
                    dfsHelper(*it,visited);
               }
          }*/
          visited[src] = false;
          return false;
     }


     void dfs(int n){

          unordered_map<T,bool> visited;
          for(auto it = hash.begin(); it != hash.end(); it++){
               visited[it->first] = false;
          }

          bool ans, flag  = false;

          for(auto it = hash.begin(); it != hash.end(); it++){
          	//cout<<it->first<<" ";
               if(!visited[it->first]){
                    ans = dfsHelper(it->first,visited,1,n);
               }
               if(ans){
                    cout<<"Head to tail ordering is possible."<<endl;
                    flag = true;
                    break;
               }
          }

          if(!flag){
               cout<<"Head to tail ordering is not possible."<<endl;
          }

     }



     // Kahn’s algorithm for Topological Sorting
     // it uses bfs technique i.e. queue
     void topologicalSort(){

        if(hash.size() == 0){
            cout<<"Head to tail ordering is not possible.";
            return;
        }

          unordered_map<T,int> inDegree;

          for(auto it = hash.begin(); it != hash.end(); it++){
               inDegree[it->first] = 0;
          }

          for(auto i = hash.begin(); i != hash.end(); i++){
               for(auto it = hash[i->first].begin(); it != hash[i->first].end(); it++){
                    inDegree[*it]++;
               }
          }

          queue<T> q;


          for(auto it = hash.begin(); it != hash.end(); it++){
              if(inDegree[it->first] == 0){
                  q.push(it->first);
              }
          }

          while(!q.empty()){
               T front = q.front();
               q.pop();
               for(auto it = hash[front].begin(); it != hash[front].end(); it++){
                    inDegree[*it]--;
                    if(inDegree[*it] == 0){
                         q.push(*it);
                    }
               }
          }

          bool flag = true;
          for(auto it = hash.begin(); it != hash.end(); it++){
              if(inDegree[it->first] != 0){
                  flag = false;
                  cout<<"Head to tail ordering is not possible.";
                  break;
              }
          }

        if(flag == true){
            cout<<"Head to tail ordering is possible.";
        }
     }

     void gclear(){
     	for(auto it = hash.begin(); it != hash.end(); it++){
		hash[it->first].clear();
     	}
     	hash.clear();
     }



};

int main(){

    vector<string> v;

    int t;
    cin>>t;
    while(t--){

    int V;
    cin>>V;
    for(int i = 0; i < V; i++){
	string s;
	cin>>s;
	v.push_back(s);
    }

     graph<string> g;

     for(int i = 0; i < V; i++){
         int end = v[i].length();
         for(int j = 0; j < V; j++){
             if(i != j  && v[i][end-1] == v[j][0]){
                 g.addEdge(v[i],v[j]);
             }
         }
     }

     g.dfs(V);
     //g.topologicalSort();

     g.gclear();
     v.clear();

    }

     return 0;
}
