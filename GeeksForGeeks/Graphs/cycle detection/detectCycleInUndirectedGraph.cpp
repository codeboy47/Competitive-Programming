/*
We can either use BFS or DFS. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already
visited and u is not parent of v, then there is a cycle in graph. If we don’t find such an adjacent for any vertex,
we say that there is no cycle
*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class graph{

     int vertices;
     vector<int> *arr;

public:

     graph(int V){
          vertices = V;
          arr = new vector<int>[V];
     }

     void addEdge(int u, int v, bool undir = true){
          arr[u].push_back(v);
          if(undir){
               arr[v].push_back(u);
          }
     }


     // here we assume there are no parallel edges between 2 vertices or self loop like u - v and v - u or v - v
     // for that use recStack method just like we used in cycle detection in directed graph
     bool dfsCyclicHelper(int src, int parent, bool *visited){

          visited[src] = true;

          for(auto it = arr[src].begin(); it != arr[src].end(); it++){
               if(!visited[*it]){
                    if(dfsCyclicHelper(*it,src,visited)){
                         return true;
                    }
               }

               else if(*it != parent){
                    return true;
               }
          }

          return false;
     }

     // time complexity is O(V + E)
     bool isCyclic(){

          bool *visited = new bool[vertices];
          memset(visited,false,sizeof(bool)*vertices);


          for(int i = 0; i < vertices; i++){
               if(!visited[i]){
                    bool ans = dfsCyclicHelper(i,-1,visited);
                    if(ans){
                         return true;
                    }
               }
          }

          return false;

     }

};


int main(){

     graph g1(5);
     g1.addEdge(1, 0);
     g1.addEdge(0, 2);
     g1.addEdge(2, 0);
     g1.addEdge(0, 3);
     g1.addEdge(3, 4);
     g1.isCyclic()? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

     graph g2(3);
     g2.addEdge(0, 1);
     g2.addEdge(1, 2);
     g2.isCyclic()? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

     return 0;
}
