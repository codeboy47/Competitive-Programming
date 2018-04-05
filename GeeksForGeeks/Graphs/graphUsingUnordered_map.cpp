#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <unordered_map>
using namespace std;

template<typename T>
class graph{

     int vertices;
     unordered_map<T, vector<T> > hash;

public:

     graph() { }
     graph(int V) :  vertices(V) { }

     void addEdge(T u, T v, bool undirectedGraph = true){

          hash[u].push_back(v);
          if(undirectedGraph){
               hash[v].push_back(u);
          }
          vertices = hash.size();
     }

     void bfs(T src, T dest){

          unordered_map<T,bool> visited;
          unordered_map<T,int> distance;
          unordered_map<T,T> parent;
          for(auto it = hash.begin(); it != hash.end(); it++){
               distance[it->first] = INT_MAX;
          }

          queue<T> q;
          q.push(src);
          visited[src] = true;
          distance[src] = 0;
          parent[src] = src;
          while(!q.empty()){
               T front = q.front();
               q.pop();
               cout<<front<<endl;
               for(int i = 0; i < hash[front].size(); i++){
                    if(visited[hash[front][i]] == false){
                         q.push(hash[front][i]);
                         visited[hash[front][i]] = true;
                         distance[hash[front][i]] = distance[front] + 1;
                         parent[hash[front][i]] = front;
                    }
               }
          }

          cout<<"Distance from "<<src<<" : "<<endl;
          for(auto it = distance.begin(); it != distance.end(); it++){
               cout<<it->first<<" - "<<it->second<<endl;
          }

          cout<<"Path from source "<<src<<" to "<<dest<<endl;
          T d = dest;
          while(d != src){
               cout<<d<<"<--";
               d = parent[d];
          }
          cout<<d<<endl;
     }

     void dfsHelper(T src, unordered_map<T,bool> &visited){
          visited[src] = true;
          cout<<src<<" ";

          if(hash.count(src) != 0){
               for(int i = 0; i < hash[src].size(); i++){
                    if(!visited[hash[src][i]]){
                         dfsHelper(hash[src][i],visited);
                    }
               }
          }
          /* OR
          for(auto it = hash[src].begin(); it != hash[src].end(); it++){
               if(!visited[*it]){
                    dfsHelper(*it,visited);
               }
          }*/
     }


     void dfs(){

          unordered_map<T,bool> visited;

          cout<<endl<<"DFS :- "<<endl;

          int component = 1;
          for(auto it = hash.begin(); it != hash.end(); it++){
               if(!visited[it->first]){
                    cout<<"Component "<<component<<" : ";
                    dfsHelper(it->first,visited);
                    cout<<endl;
                    component++;
               }
          }

     }

     // works on bfs
     int shortestPath(T src, T dest){

          unordered_map<T,int> dist;
          for(auto it = hash.begin(); it != hash.end(); it++){
               dist[it->first] = -1;
          }

          queue<T> q;
          q.push(src);
          dist[q.front()] = 0;

          while(!q.empty()){

               T top = q.front();
               q.pop();

               for(auto it = hash[top].begin(); it != hash[top].end(); it++){
                    if(dist[*it] == -1){
                         q.push(*it);
                         dist[*it] = dist[top] + 1;
                         if(*it == dest){
                              return dist[*it];
                         }
                    }
               }
          }

          return -1;

     }

     // Implement isConnected for our graph
	// means if a vertex is given check whether it is connected with all other vertices of graph
     bool isConnected(T src){

          unordered_map<T,bool> visited;
          for(auto it = hash.begin(); it != hash.end(); it++){
               visited[it->first] = false;
          }
          dfsHelper(src,visited);
          for(auto it = visited.begin(); it != visited.end(); it++){
               if(it->second == false){
                    return false;
               }
          }
          return true;
     }


     void printAdjList(){
          for(auto it = hash.begin(); it != hash.end(); it++){
               cout<<it->first<<" -> ";
               for(int i = 0; i < it->second.size(); i++){
                    cout<<it->second[i]<<"  ";
               }
               cout<<endl;
          }
     }

};


int main(){

    graph<string> g;
    g.addEdge("Delhi","Agra");
    //g.addEdge("Delhi","Jaipur");
    g.addEdge("Jaipur","Bhopal");
    g.addEdge("Agra","Jaipur");
    g.addEdge("Mumbai","Agra");
    g.addEdge("Delhi","Mumbai");
    g.addEdge("Andaman","Nicobar");

    g.printAdjList();
    string city1,city2;
    cin>>city1>>city2;

    g.bfs(city1,city2);

    g.dfs();

    // this ques is for undirected graph
    cout<<"Shortest Path is "<<g.shortestPath("Delhi","Bhopal")<<endl;

    if(g.isConnected("Delhi"))
         cout<<"Its a connected graph "<<endl;
    else
         cout<<"Not connected"<<endl;


    return 0;
}
