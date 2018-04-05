#include <iostream>
using namespace std;
#define INF 9999

void floydWarshell(int graph[][4], int v){

     int distance[v][v];

     for(int i = 0; i < v; i++){
          for(int j = 0; j < v; j++){
               distance[i][j] = graph[i][j];
          }
     }

     for(int k = 0; k < v; k++){
          for(int i = 0; i < v; i++){
               for(int j = 0; j < v; j++){
                    // distance b/w vertices i & j is distance b/w i & k + distance b/w k & j
                    if(distance[i][j] > distance[i][k] + distance[k][j]){
                         distance[i][j] = distance[i][k] + distance[k][j];
                    }
               }
          }
     }


     for(int i = 0; i < v; i++){
          for(int j = 0; j < v; j++){
               if(distance[i][j] == INF){
                    cout<<"INF"<<"  ";
               }
               else{
                    cout<<distance[i][j]<<"    ";
               }
          }
          cout<<endl;
     }


}


int main(){

     int vertices = 4;

     int graph[4][4] = { {0,  3,  6,  15},
                         {INF, 0, -2, INF},
                         {INF, INF, 0, 2},
                         {1, INF, INF, 0}
                       };

     floydWarshell(graph,4);

     return 0;
}
