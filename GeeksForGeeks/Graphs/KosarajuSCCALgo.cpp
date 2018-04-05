#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

class graph{

     int vertices;
     vector<int> *arr;

public :

     graph() { }
     graph(int V){
          vertices = V;
          arr = new vector<int> [vertices];
     }

     void addEdge(int u, int v){
          arr[u].push_back(v);
     }

     graph reverseGraph(){
          graph gRev(vertices);
          for(int i = 0; i < vertices; i++){
               for(int j = 0; j < arr[i].size(); j++){
                    gRev.addEdge(arr[i][j],i);
               }
          }
          return gRev;
     }

     void dfsHelper(int src, bool *visited){
          visited[src] = true;
          for(int i = 0; i < arr[src].size(); i++){
               if(!visited[arr[src][i]]){
                    dfsHelper(arr[src][i],visited);
               }
          }
     }

     bool isStronglyConnected(){

          bool *visited = new bool[vertices];
          memset(visited,false,sizeof(bool)*vertices);

          dfsHelper(0,visited);

          for(int i = 0; i < vertices; i++){
               if(!visited[i]){
                    return false;
               }
          }

          graph gRev = reverseGraph();

          memset(visited,false,sizeof(bool)*vertices);

          gRev.dfsHelper(0,visited);

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
     g1.addEdge(0, 1);
     g1.addEdge(1, 2);
     g1.addEdge(2, 3);
     g1.addEdge(3, 0);
     g1.addEdge(2, 4);
     g1.addEdge(4, 2);
     g1.isStronglyConnected()? cout << "Yes\n" : cout << "No\n";

     graph g2(4);
     g2.addEdge(0, 1);
     g2.addEdge(1, 2);
     g2.addEdge(2, 3);
     g2.isStronglyConnected()? cout << "Yes\n" : cout << "No\n";


     return 0;
}
