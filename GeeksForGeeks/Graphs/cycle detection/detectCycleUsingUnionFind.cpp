// Detect Cycle in an Undirected Graph
// Here we use Disjoint Set (Or Union-Find)

#include <iostream>
using namespace std;

class Pair{
public:
     int parent;
     int rank;
};


int find(int i, int *parent){

     if(parent[i] == i){
          return i;
     }
     return find(parent[i],parent);
}

int findUsingPathCompression(int i, Pair *arr){
     if(arr[i].parent == i){
          return i;
     }
     arr[i].parent = findUsingPathCompression(arr[i].parent,arr);
     return arr[i].parent;
}


void Union(int xp, int yp, int *parent){

     parent[yp] = xp;
}

void UnionByRank(int x, int y, Pair *arr){

     int xroot = findUsingPathCompression(x,arr);
     int yroot = findUsingPathCompression(y,arr);

     if(arr[xroot].rank > arr[yroot].rank){
          arr[yroot].parent = xroot;
     }
     else if(arr[xroot].rank < arr[yroot].rank){
          arr[xroot].parent = yroot;
     }
     else{
          arr[yroot].parent = xroot;
          arr[xroot].rank++;

     }


}

bool isCyclic(int graph[][1000], int vertices, int edges){

     Pair *arr = new Pair[vertices];

     for(int i = 0; i < vertices; i++){
          arr[i].parent = i;
          arr[i].rank = 0;
     }

     for(int i = 0; i < edges; i++){

          int x = graph[i][0];
          int y = graph[i][1];

          int xParent = findUsingPathCompression(x,arr);
          int yParent = findUsingPathCompression(y,arr);

          if(xParent == yParent){
               return true;
          }

          UnionByRank(xParent,yParent,arr);

     }

     return false;

}

int main(){

     int vertices, edges;
     cin>>vertices>>edges;

     int graph[1000][1000];


     for(int i = 0; i < edges; i++){
               cin>>graph[i][0]; // u
               cin>>graph[i][1]; // v
     }

     isCyclic(graph,vertices,edges) ? cout<<"graph contains cycle\n" : cout<<"graph doesn't contain any cycle\n";

     return 0;
}

/*
v = 7 e = 6
4 3
3 2
6 0
1 0
2 0
1 2
*/
