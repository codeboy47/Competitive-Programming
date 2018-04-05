// Asked in microsoft
#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void generateHelper(bool flag, int *arr1, int i, int n, int *arr2, int j, int m, int *output, int idx){

     if(flag == false){
          for(int k = j; k < m; k++){
               if(arr1[i] < arr2[k]){
                    output[idx] = arr2[k];
                    print(output,idx);
                    if(k != m-1){
                         generateHelper(true,arr1,i+1,n,arr2,k,m,output,idx+1);
                    }
               }
          }
     }
     else{
          for(int k = i; k < n; k++){
               if(arr2[j] < arr1[k]){
                    output[idx] = arr1[k];
                    generateHelper(false,arr1,k,n,arr2,j+1,m,output,idx+1);
               }
          }
     }

}

void generate(int arr1[], int n, int arr2[], int m){

     int output[10000];
     for(int k = 0; k < n; k++){
          output[0] = arr1[k];
          generateHelper(false,arr1,k,n,arr2,0,m,output,1);
     }
}

int main(){

     int arr1[10000],arr2[10000],output[10000];
     int t;
     cin>>t;
     while(t--){
          int n,m;
          cin>>n>>m;
          for(int i = 0; i < n; i++){
               cin>>arr1[i];
          }
          for(int i = 0; i < m; i++){
               cin>>arr2[i];
          }

          generate(arr1,n,arr2,m);
     }

     return 0;
}
