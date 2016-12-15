#include<iostream>
using namespace std;

bool sort(int *arr, int n){
    static int i = 0;
    if(i == n-1) return true;
    if(arr[i] < arr[i+1]){
        i++;
        return sort(arr,n);
    }
    if(arr[i] > arr[i+1]){
        return false;
    }
}

int main(){
    int arr[100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool k = sort(arr,n);
    if(k == true)
        cout<<"sorted array";
    else
        cout<<"unsorted";
}
