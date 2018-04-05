#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class graph{

     long vertices;
     vector<int> * adj;

public:

     graph(int v){
          vertices = v;
          adj = new vector<int>[v];
     }

     void addEdge(int u, int v){
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     void dfsHelper(int src, bool *visited, int &count){

          visited[src] = true;
          count++;

          for(auto it = adj[src].begin(); it != adj[src].end(); it++){
               if(!visited[*it]){
                    dfsHelper(*it,visited,count);
               }
          }
     }

     void dfs(vector<int> &arr){

           bool * visited = new bool[vertices];
           memset(visited,false,sizeof(bool)*vertices);

           for(int i = 0; i < vertices; i++){
                if(!visited[i]){
                     int count = 0;
                     dfsHelper(i,visited,count);
                     arr.push_back(count);
                }
           }

     }

     // no of ways to pair astronauts of  different countries = Total ways - no of ways to pair astronauts of same country
     long findCombinations(){

          long totalWays = (vertices*(vertices-1))/2;
          vector<int> arr;
          dfs(arr);

          long ans = totalWays;
          for(int i = 0; i < arr.size(); i++){
               long waysToPairSameCountryAstronauts = (arr[i]*(arr[i]-1))/2;
               ans = ans - waysToPairSameCountryAstronauts;
          }

          return ans;

     }


};

int main(){

     int n,p;

     cin>>n>>p;

     graph g(n);
     for(int i = 0; i  < p; i++){
          int a,b;
          cin>>a>>b;
          g.addEdge(a,b);
     }

     cout<<g.findCombinations();

     return 0;
}
