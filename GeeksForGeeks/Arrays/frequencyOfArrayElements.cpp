#include <iostream>
using namespace std;

// time complexity is O(n) and space complexity is O(1)
void countFrequencies(int *arr, int n){

     int i = 0;
     while(i  < n){

          if(arr[i] <= 0){
               i++;
               continue;
          }

          int index = arr[i]-1;

          if(arr[index] > 0){
               arr[i] = arr[index];
               arr[index] = -1;
          }
          else{
               arr[index]--;
               arr[i] = 0;
               i++;
          }

     }

}


void countFrequencies2(int arr[], int n){

     for(int i = 0; i < n; i++){
          arr[i] = arr[i]-1;
     }

     for(int i = 0; i < n; i++){
          arr[arr[i]%n] = arr[arr[i]%n] + n;
     }

     for(int i = 0; i < n; i++){
          cout<<i+1<<" -> "<<arr[i]/n<<endl;
     }
}

void print(int arr[], int n){
     for(int i = 0; i < n; i++){
          if(arr[i] < 0){
               arr[i] = arr[i]*(-1);
          }
     }
     for(int i = 0; i < n; i++){
          cout<<arr[i]<<" ";
     }
     cout<<endl;
}

int main(){

     int t;
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          int arr[100000];
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          //countFrequencies(arr,n);
          //print(arr,n);
          countFrequencies2(arr,n);

     }

     return 0;
}
