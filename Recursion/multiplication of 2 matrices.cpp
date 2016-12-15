#include<iostream>
using namespace std;
int arr3[100][100];
/*
void multiply(int arr1[100][100], int arr2[100][100],int row1,int col1,int row2,int col2){
    int i,j,k;
    for(i=0;i<row1;i++){
        for(j=0;j<row1;j++){
            arr3[i][j] = 0;
        }
    }
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            for(k=0;k<col1;k++){
               arr3[i][j] = arr3[i][j] + arr1[i][k]*arr2[k][j];
            }
        }
    }
}
*/
void multiply(int arr1[100][100], int arr2[100][100],int row1,int col1,int row2,int col2){
    static int i=0,j=0,k=0;
    if(i < row1){
        if(j < col1){
            if(k < col1){
                arr3[i][j] = arr3[i][j] + arr1[i][k]*arr2[k][j];
                k++;
                multiply(arr1,arr2,row1,col1,row2,col2);
            }
            j++;
            k = 0;
            multiply(arr1,arr2,row1,col1,row2,col2);
        }
        i++;
        j = 0;
        k = 0;
        multiply(arr1,arr2,row1,col1,row2,col2);
    }
    return;
}

int main(){
    int row1,col1,row2,col2,i,j,arr1[100][100],arr2[100][100];

    cout<<"row 1 and col 1";
    cin>>row1>>col1;
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            cin>>arr1[i][j];
        }
    }

    cout<<"row 2 and col 2";
    cin>>row2>>col2;
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++){
            cin>>arr2[i][j];
        }
    }
    multiply(arr1,arr2,row1,col1,row2,col2);

    for(i=0;i<row1;i++){
        for(j=0;j<row1;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
