// asked in companies : Amazon, Microsoft, Morgan-Stanley
#include <iostream>
using namespace std;


// we maintain 2 values at each index
// positiveProduct stores max positive product at current index
// negativeProduct stores max negative product at current index
int maximumProductSubarray(int *arr, int n){

     int positiveProduct = 1;
     int negativeProduct = 1;
     int maxProduct = 1;
     for(int i = 0; i < n; i++){

          if(arr[i] > 0){
               positiveProduct = positiveProduct*arr[i];
               negativeProduct = min(negativeProduct*arr[i],1); // min(-ve * +ve is -ve,1)
          }
          else if(arr[i] == 0){
               positiveProduct = 1;
               negativeProduct = 1;
          }
          else{
               int temp = positiveProduct;
               positiveProduct = max(1,arr[i]*negativeProduct); // max(1,-ve * -ve is +ve)
               negativeProduct = arr[i]*temp;
          }

          maxProduct = max(maxProduct,positiveProduct);

     }

     return maxProduct;
}

int main(){

     int t;
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          int arr[10000];
          for(int i = 0; i < n; i++){
               cin>>arr[i];
          }

          cout<<maximumProductSubarray(arr,n)<<endl;
     }

}
