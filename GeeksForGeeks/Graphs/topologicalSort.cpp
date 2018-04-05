/*
Topological sorting of vertices of a Directed Acyclic Graph is an ordering of the vertices v1, v2,...vn
in such a way, that if there is an edge directed towards vertex vj from vertex vi, then vi comes before vj.
The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no in-coming edges).
*/
#include <iostream>
#include <list>
#include <string.h>
#include <queue>
using namespace std;

class graph{

     int vertices;
     list<int> *l;

public :

     graph(int v){
          vertices = v;
          l = new list<int> [v];
     }
     void addEdge(int u, int v){
          l[u].push_back(v);
     }

     // Kahn’s algorithm for Topological Sorting
     // it uses bfs technique i.e. queue
     void topologicalSort(){

          int *inDegree = new int[vertices];
          memset(inDegree,0,sizeof(int)*vertices);

          for(int i = 0; i < vertices; i++){
               for(auto it = l[i].begin(); it != l[i].end(); it++){
                    inDegree[*it]++;
               }
          }

          queue<int> q;

          for(int i = 0; i < vertices; i++){
               if(inDegree[i] == 0){
                    q.push(i);
               }
          }

          while(!q.empty()){
               int front = q.front();
               cout<<front<<" ";
               q.pop();
               for(auto it = l[front].begin(); it != l[front].end(); it++){
                    inDegree[*it]--;
                    if(inDegree[*it] == 0){
                         q.push(*it);
                    }
               }
          }

     }

};

int main(){

     graph g(6);
     g.addEdge(0,2);
     g.addEdge(0,3);
     g.addEdge(1,2);
     g.addEdge(2,3);
     g.addEdge(3,4);
     g.addEdge(3,5);
     g.addEdge(2,5);
     g.addEdge(4,5);

     g.topologicalSort();
     cout<<endl;

     return 0;
}

/*
     graph g(6);
     g.addEdge(5, 2);
     g.addEdge(5, 0);
     g.addEdge(4, 0);
     g.addEdge(4, 1);
     g.addEdge(2, 3);
     g.addEdge(3, 1);

*/
