#include<iostream>
using namespace std;
/* self made code
int largestElement(int *arr,int n,int i,int l){
    if(i == n)  return l;
    else if(l < arr[i]){
        l = arr[i];
        return largestElement(arr,n,i+1,l);
    }else{
        return largestElement(arr,n,i+1,l);
    }
}
*/

int largestElement(int *arr,int n){
    static int largest = -9999,i=0; // stores values in other recursive calls
    if(i == n)  return largest;
    else if(largest < arr[i]){
        largest = arr[i];
        i++;
        return largestElement(arr,n);
    }else{
        i++;
        return largestElement(arr,n);
    }
}

/* online code
int largestElement(int arr[],int n){

    static int i=0,max =-9999;

    if(i < n){
         if(max<arr[i])
           max=arr[i];
      i++;
      largestElement(arr,n);
    }

    return max;
}*/

int main(){
    int arr[100],i,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<largestElement(arr,n);
}
