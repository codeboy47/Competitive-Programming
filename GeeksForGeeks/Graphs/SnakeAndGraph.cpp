#include <iostream>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;

template<typename T>
class graph{

     int vertices;
     unordered_map<T, vector<T> > hash;

public:

     graph() : vertices(0) { }
     graph(int v) : vertices(v) { }

     // directed graph
     void addEdge(T u, T v){
          hash[u].push_back(v);
          vertices = hash.size();
     }



     void bfs(T src, T dest){

          T *parent  = new T[37];
          bool *visited = new bool[37];
          T *distance = new T[37];
          memset(visited,false,sizeof(bool)*37);
          memset(distance,-1,sizeof(T)*37);
          queue<T> q;
          q.push(src);
          visited[q.front()] = true;
          parent[q.front()] = 0;
          distance[q.front()] = 0;
          while(!q.empty()){
               int front  = q.front();
               cout<<front<<endl;
               q.pop();
               for(auto it = hash[front].begin(); it != hash[front].end(); it++){
                    if(!visited[*it]){
                         q.push(*it);
                         visited[*it] = true;
                         parent[*it] = front;
                         distance[*it] = distance[front] + 1;
                    }
               }
          }

          cout<<"Distance from src 0 :"<<endl;
          for(T i = 36; i >= 0; i--){
               cout<<i<<" : "<<distance[i]<<endl;
          }

          cout<<"Path from src to dest : "<<endl;
          T temp = dest;
          while(temp != src){
               cout<<temp<<"<---";
               temp = parent[temp];
          }
          cout<<src<<endl;

     }

};


int main(){

     graph<int> g;
     int board[50] = {0};
     board[2]= 13;
     board[5] = 2;
     board[9] = 18;
     board[18] = 11;
     board[17] = -13;
     board[20] = -14;
     board[24] = -8;
     board[25] = 10;
     board[32] = -2;
     board[34] = -22;

     for(int i = 0; i < 36; i++){
          for(int dice = 1; dice <= 6; dice++){
               int t = i + dice + board[i+dice];
               if(t <= 36){
                    g.addEdge(i,t);
               }
          }
     }
     g.bfs(0,36);
     return 0;
}
