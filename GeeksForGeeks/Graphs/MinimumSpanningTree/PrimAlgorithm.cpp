#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <climits>
using namespace std;

class graph{
     int vertices;
     vector<pair<int,int>> *adj;
public:

     graph(int V){
          vertices = V;
          adj = new vector<pair<int,int>>[V];
     }

     void addEdge(int u, int v, int wt){
          adj[u].push_back(make_pair(v,wt));
          adj[v].push_back(make_pair(u,wt));
     }

     int  PrimsMST(){

          int minCost = 0;

          int *parent = new int[vertices]; // to store edges of MST
          int *minValue = new int[vertices];
          bool *visited = new bool[vertices];
          for(int i = 0; i < vertices; i++){
               minValue[i] = INT_MAX;
               visited[i] = false;
               parent[i] = -1;
          }

          minValue[0] = 0;

          set<pair<int,int> > s;

          s.insert(make_pair(0,0));

          while(!s.empty()){

               int front = s.begin()->second;
               int weight = s.begin()->first;
               s.erase(s.begin());

               /*if(visited[front]){
                    continue;
               }*/

               visited[front] = true;
               minCost += weight;

               for(auto it = adj[front].begin(); it != adj[front].end(); it++){

                    if(!visited[it->first] && it->second < minValue[it->first]){
                         auto search = s.find(make_pair(minValue[it->first],it->first));
                         if(search != s.end()){
                              s.erase(search);
                         }
                         parent[it->first] = front;
                         minValue[it->first] = it->second;
                         s.insert(make_pair(it->second,it->first));
                    }

               }
          }


          for(int i = 1; i < vertices; i++){
               cout<<parent[i]<<" -- "<<i<<" = "<<minValue[i]<<endl;
          }
     	return minCost;
     }

};

int main(){

     int vertices, edges;
     cin>>vertices>>edges;

     graph g(vertices);

     for(int i = 0; i < edges; i++){
          int x, y, wt;
          cin>>x>>y>>wt;
          g.addEdge(x,y,wt);
     }

     cout<<g.PrimsMST();

     return 0;
}

/*
9 14
0 1 4
0 7 8
1 2 9
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
