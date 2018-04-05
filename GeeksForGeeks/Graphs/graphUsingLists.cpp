#include <iostream>
#include <list>

using namespace std;


class graph{

     int vertices;
     list<int> *l;

public:

     graph(int V){
          vertices = V;
          l = new list<int>[V];
     }

     void addEdge(int u, int v, bool undirectedGraph = true){

          l[u].push_back(v);
          if(undirectedGraph){
               l[v].push_back(u);
          }
     }

     void printAdjList(){

          for(int i = 0; i < vertices; i++){
               cout<<i<<" -> ";
               for(auto it = l[i].begin(); it != l[i].end(); it++){
                    cout<<*it<<" ";
               }
               cout<<endl;
          }

     }

};


int main(){

     graph g(5);

     g.addEdge(1,2);
     g.addEdge(1,3);
     g.addEdge(3,4);
     g.addEdge(2,3);
     g.addEdge(4,0);

     g.printAdjList();

     return 0;
}
