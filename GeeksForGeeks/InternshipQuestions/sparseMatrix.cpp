#include <iostream>
#include <list>
using namespace std;


void optimizingSpaceUsingArray(int sparseMatrix[][5], int r, int c){

     int arr[3][1000];

     int k = 0;
     for(int i = 0; i < r; i++){
          for(int j = 0; j < c; j++){
               if(sparseMatrix[i][j] != 0){
                    arr[0][k] = i;
                    arr[1][k] = j;
                    arr[2][k] = sparseMatrix[i][j];
                    k++;
               }
          }
     }

     cout<<"compact matrix is  :"<<endl;
     for(int i = 0; i < 3; i++){
          for(int j = 0; j < k; j++){
               cout<<arr[i][j]<<" ";
          }
          cout<<endl;
     }

}

class node{
public:
     int row;
     int col;
     int data;

};

void optimizingSpaceUsingLinkedList(int sparseMatrix[][5], int r, int c){

     list<node> l;

     for(int i = 0; i < r; i++){
          for(int j = 0; j < c; j++){
               if(sparseMatrix[i][j] != 0){
                    node n;
                    n.row = i;
                    n.col = j;
                    n.data = sparseMatrix[i][j];
                    l.push_back(n);
               }
          }
     }

     cout<<endl<<"linked list representation of sparse matrix is :"<<endl;
     for(auto it = l.begin(); it != l.end(); it++){
          cout<<"("<<it->row<<", "<<it->col<<", "<<it->data<<")--->";
     }
     cout<<"NULL"<<endl<<endl;

}

int main(){


     int sparseMatrix[4][5] =
     {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
     };


     optimizingSpaceUsingArray(sparseMatrix,4,5);
     optimizingSpaceUsingLinkedList(sparseMatrix,4,5);


     return 0;
}
