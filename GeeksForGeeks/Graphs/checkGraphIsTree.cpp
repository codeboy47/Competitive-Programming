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


     // An undirected graph is tree if :
     // 1) There is no cycle.
     // 2) The graph is connected.
     bool isTree(){

          bool *visited = new bool[vertices];
          memset(visited,false,sizeof(bool)*vertices);

          if(dfsCyclicHelper(0,-1,visited)){
               return false;
          }

          for(int i = 0; i < vertices; i++){
               if(!visited[i]){
                    return false;
               }
          }

          return true;

     }


};


int main(){

     graph g1(5);
     g1.addEdge(1, 0);
     g1.addEdge(0, 2);
     g1.addEdge(0, 3);
     g1.addEdge(3, 4);
     g1.isTree()? cout << "Graph is Tree\n":cout << "Graph is not Tree\n";

     graph g2(5);
     g2.addEdge(1, 0);
     g2.addEdge(0, 2);
     g2.addEdge(2, 1);
     g2.addEdge(0, 3);
     g2.addEdge(3, 4);
     g2.isTree()? cout << "Graph is Tree\n":cout << "Graph is not Tree\n";

     return 0;
}
