#include <bits/stdc++.h>
using namespace std;

// here we use dijkstra algorithm

int minCostPath(int arr[][1000], int n){

    set< pair<int,pair<int,int>> > s; // <distance,vertex>

    int distance[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j <  n; j++){
            distance[i][j] = INT_MAX;
        }
    }

    distance[0][0] = arr[0][0];
    s.insert(make_pair(arr[0][0],(make_pair(0,0))));

    while(!s.empty()){

        int dist = s.begin()->first;
        int i = s.begin()->second.first;
        int j = s.begin()->second.second;
        s.erase(s.begin());

        // traverse all the neighbours of source vertex
        if(j != n-1 && dist + arr[i][j+1] < distance[i][j+1]){
            distance[i][j+1] = dist + arr[i][j+1];
            s.insert(make_pair(distance[i][j+1],(make_pair(i,j+1))));
        }

        if(i != n-1 && dist + arr[i+1][j] < distance[i+1][j]){
            distance[i+1][j] = dist + arr[i+1][j];
            s.insert(make_pair(distance[i+1][j],(make_pair(i+1,j))));
        }

        if(j != 0 && dist + arr[i][j-1] < distance[i][j-1]){
            distance[i][j-1] = dist + arr[i][j-1];
            s.insert(make_pair(distance[i][j-1],(make_pair(i,j-1))));
        }

        if(i != 0 && dist + arr[i-1][j] < distance[i-1][j]){
            distance[i-1][j] = dist + arr[i-1][j];
            s.insert(make_pair(distance[i-1][j],(make_pair(i-1,j))));
        }

    }

    return distance[n-1][n-1];
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int arr[1000][1000];
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>arr[i][j];
            }
        }

        cout<<minCostPath(arr,n)<<endl;

    }

    return 0;
}
