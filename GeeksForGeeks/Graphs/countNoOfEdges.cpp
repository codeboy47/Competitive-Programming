// Count number of edges in an undirected graph

#include <iostream>
#include <vector>
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
          arr[v].push_back(u);
     }

     // we use handshaking lemma : In every finite undirected graph number of vertices with odd degree is always even
     // Formula : sum of degree of all vertices = 2 * edges
     int countEdges(){

          int sum = 0;
          for(int i = 0; i < vertices; i++){
               sum += arr[i].size();
          }

          return sum/2;
     }

};


int main(){
    int V = 9 ;
    graph g(V);

    g.addEdge(0, 1 );
    g.addEdge(0, 7 );
    g.addEdge(1, 2 );
    g.addEdge(1, 7 );
    g.addEdge(2, 3 );
    g.addEdge(2, 8 );
    g.addEdge(2, 5 );
    g.addEdge(3, 4 );
    g.addEdge(3, 5 );
    g.addEdge(4, 5 );
    g.addEdge(5, 6 );
    g.addEdge(6, 7 );
    g.addEdge(6, 8 );
    g.addEdge(7, 8 );

    cout << g.countEdges() << endl;

    return 0;
}
