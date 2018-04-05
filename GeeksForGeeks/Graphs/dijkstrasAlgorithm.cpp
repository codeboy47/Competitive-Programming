#include <iostream>
#include <set>
#include <climits>
#include <vector>
using namespace std;


class graph{

     int vertices;
     vector<pair<int,int> > *arr;

public:

     graph(int v){
          vertices = v;
          arr = new vector<pair<int,int> >[v];
     }

     void addEdge(int u, int v, int w, bool undir = true){
          arr[u].push_back(make_pair(v,w));
          if(undir == true){
               arr[v].push_back(make_pair(u,w));
          }
     }

     void dijkstra(int src){
          set<pair<int,int> > s;
          int *distance = new int[vertices];

          for(int i = 0; i < vertices; i++){
               distance[i] = INT_MAX;
          }

          s.insert(make_pair(0,src));
          distance[src] = 0;

          while(!s.empty()){

               int dist = s.begin()->first;
               int front = s.begin()->second;
               s.erase(s.begin());

               for(auto it = arr[front].begin(); it != arr[front].end(); it++){

                    if( it->second + dist < distance[it->first]){
                         auto search = s.find(make_pair(distance[it->first],it->first));
                         if(search != s.end()){
                              s.erase(search);
                         }
                         distance[it->first] = it->second + dist;
                         s.insert(make_pair(distance[it->first],it->first));
                    }
               }
          }

          for(int i = 0; i < vertices; i++){
               cout<<i<<" : "<<distance[i]<<endl;
          }

     }


};


int main(){

     graph g(6);
     g.addEdge(0,1,1);
     g.addEdge(0,4,6);
     g.addEdge(4,2,1);
     g.addEdge(4,5,7);
     g.addEdge(4,1,3);
     g.addEdge(1,2,4);
     g.addEdge(2,3,3);
     g.addEdge(3,5,2);

     g.dijkstra(0);

     return 0;
}
