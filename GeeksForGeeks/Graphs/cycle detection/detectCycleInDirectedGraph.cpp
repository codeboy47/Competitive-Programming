/*
To detect a back edge, we can keep track of vertices currently in recursion stack of function for DFS traversal. If we reach a vertex that is already in the recursion stack, then there is a cycle in the tree. The edge that connects current vertex to the vertex in the recursion stack is back edge. We have used recStack[] array to keep track of vertices in the recursion stack. */

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

     void addEdge(int u, int v){
          arr[u].push_back(v);
     }


     bool dfsCyclicHelper(int src, bool *visited, bool *recStack){

          visited[src] = true;
          recStack[src] = true;

          for(auto it = arr[src].begin(); it != arr[src].end(); it++){
               if(!visited[*it]){
                    if(dfsCyclicHelper(*it,visited,recStack)){
                         return true;
                    }
               }

               else if(recStack[*it]){
                    return true;
               }
          }

          recStack[src] = false;
          return false;
     }

     // time complexity is O(V + E)
     bool isCyclic(){

          bool *visited = new bool[vertices];
          bool *recStack = new bool[vertices];
          memset(visited,false,sizeof(bool)*vertices);
          memset(recStack,false,sizeof(bool)*vertices);

          for(int i = 0; i < vertices; i++){
               if(!visited[i]){
                    bool ans = dfsCyclicHelper(i,visited,recStack);
                    if(ans){
                         return true;
                    }
               }
          }

          return false;

     }

};


int main(){

     graph g(4);
     g.addEdge(0, 1);
     g.addEdge(0, 2);
     g.addEdge(1, 2);
     g.addEdge(2, 0);
     g.addEdge(2, 3);
     g.addEdge(3, 3);

     if(g.isCyclic())
         cout << "Graph contains cycle\n";
     else
         cout << "Graph doesn't contain cycle\n";


     return 0;
}
