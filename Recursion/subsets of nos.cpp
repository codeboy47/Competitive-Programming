#include<iostream>
using namespace std;

void printSubset(int *arr1, int n){
    int no = n,k,i,j,arr2[100];
    for(i=0;i<n;i++){
        k = 0;
        for(j = i;j<no;j++){
            arr2[k] = arr1[j];
            for(int x = 0; x < j + 1; x++){
                cout<<arr2[x];
            }
            //k++;
            cout<<endl;
        }
        no--;
    }
}

int main(){
    int arr1[100],i,n;
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>arr1[i];
    }
    printSubset(arr1,n);
}
