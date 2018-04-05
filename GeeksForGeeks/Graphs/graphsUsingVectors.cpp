#include <iostream>
#include <vector>
using namespace std;


class graph{

     int vertices;
     vector<int> *arr;

public:

     graph(int V) : vertices(V) {
          arr = new vector<int>[V]; // array of vectors
          // arr is pointing to 1st vector
     }

     void addEdge(int u, int v, bool undirectedGraph = true){

          arr[u].push_back(v);
          if(undirectedGraph){
               arr[v].push_back(u);
          }
     }

     void printAdjList(){

          for(int i = 0; i < vertices; i++){
               cout<<i<<" -> ";

               for(int j = 0; j < arr[i].size(); j++){
                    cout<<arr[i][j]<<" ";
               }
               /* OR
               for(auto it = arr[i].begin(); it != arr[i].end(); it++){
                    cout<<*it<<" ";
               }
               */
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
