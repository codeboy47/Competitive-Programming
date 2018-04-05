// Time Complexity : O(ElogE) or O(ElogV)
// We need to sort edges according to its weight thats why we use array and not adjacency list

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class data{
public:

     int u;
     int v;
     int wt;

};

bool compare(const data &g1, const data &g2){
	return g1.wt < g2.wt;
}



class Pair{
public:
     int parent;
     int rank;
};

int findByPathCompression(int i, Pair *arr){
     if(arr[i].parent == i){
          return i;
     }
     arr[i].parent =  findByPathCompression(arr[i].parent,arr);
     return arr[i].parent;
}

int UnionByRank(int xp, int yp, Pair *arr){

     int xroot = findByPathCompression(xp,arr);
     int yroot = findByPathCompression(yp,arr);

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

int KruskalMST(vector<data> &path, data *graph, int vertices, int edges){

     int count = 0;
     int minCost = 0;
     Pair arr[vertices];
     for(int i = 0; i < vertices; i++){
          arr[i].parent = i;
          arr[i].rank = 1;
     }

     for(int i = 0; i < edges; i++){

          int up = findByPathCompression(graph[i].u,arr);
          int vp = findByPathCompression(graph[i].v,arr);

          if(up != vp){
               count++;
               minCost += graph[i].wt;
               path.push_back(graph[i]);
               UnionByRank(up,vp,arr);
          }

          if(count == vertices - 1){
               break;
          }
     }

     return minCost;

}

int main(){

     int vertices, edges;
     cin>>vertices>>edges;

     data * graph = new data[edges];

     for(int i = 0; i < edges; i++){
          int x, y, weight;
          cin>>x>>y>>weight;
          graph[i].u = x;
          graph[i].v = y;
          graph[i].wt = weight;
     }

     sort(graph,graph+edges,compare);

     vector<data> path;

     cout<<"Total minimum cost of graph : ";
     cout<<KruskalMST(path,graph,vertices,edges)<<endl;

     for(int i = 0; i < path.size(); i++){
          cout<<path[i].u<<" -- "<<path[i].v<<" = "<<path[i].wt<<endl;
     }

     return 0;
}
