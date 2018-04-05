#include <iostream>
#include <vector>
#include <stack>
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
          cout<<src<<" ";
          for(int i = 0; i < arr[src].size(); i++){
               if(!visited[arr[src][i]]){
                    dfsHelper(arr[src][i],visited);
               }
          }
     }

     void fillStackUsingDFSHelper(stack<int> &s, int src, bool *visited){
          visited[src] = true;
          for(int i = 0; i < arr[src].size(); i++){
               if(!visited[arr[src][i]]){
                    fillStackUsingDFSHelper(s,arr[src][i],visited);
               }
          }
          s.push(src);
     }

     void findSCC(){

          bool *visited = new bool[vertices];
          memset(visited,false,sizeof(bool)*vertices);

          stack<int> s;

          for(int i = 0; i < vertices; i++){
               if(!visited[i]){
                    fillStackUsingDFSHelper(s,0,visited);
               }
          }

          graph gRev = reverseGraph();
          memset(visited,false,sizeof(bool)*vertices);

          while(!s.empty()){
               int top = s.top();
               s.pop();
               if(!visited[top]){
                    gRev.dfsHelper(top,visited);
                    cout<<endl;
               }
          }

     }

};

int main(){
	graph g(5);
     g.addEdge(1, 0);
     g.addEdge(0, 2);
     g.addEdge(2, 1);
     g.addEdge(0, 3);
     g.addEdge(3, 4);
     cout << "Following are strongly connected components in given graph :\n";
     g.findSCC();
     return 0;
}
