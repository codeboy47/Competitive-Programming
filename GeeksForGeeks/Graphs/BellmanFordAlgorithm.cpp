#include <iostream>
using namespace std;

int * BellmanFordAlgo(int graph[][1000], int vertices, int edges){

     int *distance = new int[vertices];

     for(int i = 0; i < vertices; i++){
          distance[i] = INT_MAX;
     }

     distance[0] = 0;

     for(int i = 0; i < vertices-1; i++){
          for(int j = 0; j < edges; j++){

               if(distance[graph[j][0]] != INT_MAX && graph[j][2] + distance[graph[j][0]] < distance[graph[j][1]]){
                    distance[graph[j][1]] = graph[j][2] + distance[graph[j][0]];
               }

          }
     }

     // this loop is run to check negative weight cycle in graph
     for(int i = 0; i < edges; i++){
          if(distance[graph[i][0]] != INT_MAX && graph[i][2] + distance[graph[i][0]] < distance[graph[i][1]]){
               // it will be printed only one time as we are not updating distance
               cout<<"Graph contains negative weight cycle"<<endl;
          }
     }

     return distance;

}


int main(){

     int vertices, edges;
     cin>>vertices>>edges;

     int graph[1000][1000];
     for(int i = 0; i < edges; i++){
               cin>>graph[i][0]; // u
               cin>>graph[i][1]; // v
               cin>>graph[i][2]; // wt
     }

     int *arr = BellmanFordAlgo(graph,vertices,edges);

     for(int i = 0; i  < vertices; i++){
          cout<<i<<" : "<<arr[i]<<endl;
     }

     return 0;
}
