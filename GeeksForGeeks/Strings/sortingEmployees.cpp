#include <iostream>
#include <algorithm>
using namespace std;

class employee{
public:
     string name;
     int salary;
};

bool compare(employee &e1, employee &e2){
     if(e1.salary == e2.salary){
          return e1.name < e2.name;
     }
     return e1.salary < e2.salary;
}

void sortEmployee(employee arr[], int n){
     sort(arr,arr+n,compare);
     for(int i = 0; i < n; i++){
          cout<<arr[i].name<<" "<<arr[i].salary<<" ";
     }
     cout<<endl;
}

int main(){

     int t;
     employee arr[10000];
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          int count = 0;
          for(int i = 0; i < n; i++){
          	string x;
          	int y;
          	cin>>x>>y;
               arr[i].name = x;
               arr[i].salary = y;
          }

          sortEmployee(arr,n);
     }

     return 0;
}
