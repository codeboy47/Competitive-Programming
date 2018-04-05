#include <iostream>
using namespace std;

int main() {
    bool flag= false;
    long long int arr[100000];
    long long int t,i,j,k,n,count1=0,count0=0,largest=-1;
    cin>>t;
    for(k =0;k< t;k++){
        cin>>n;
        count1 = 0;
        count0 = 0;
        largest = -1;
        for(i = 0;i < n;i++){
            cin>>arr[i];
        }
        for(i = 0;i < n;i++){
           if(arr[i] == 0){
                count0++;
            } 
        }
        for(i = 0;i < n;i++){
           if(arr[i] == 1){
                count1++;
            } 
        }
        if(count0 > count1){
            
            for(i = 0;i < n;i++){
            
            if(arr[i] == 0){
                //count0++;
                arr[i] = 1;
                flag = true;
            }
            else if(flag == true && arr[i] == 1){
                arr[i] = 0;
               
            }
        }
        count1 = 0;
        for(i = 0;i < n;i++){
           if(arr[i] == 1){
                count1++;
            } 
        }
        cout<<count1<<endl;
        }
        else if(count1 > count0){
            count0 = 0;
            count1 = 0;
            for(i = 0;i < n;i++){
            if(i == n-1 && arr[i] == 0){
                if(count0 > largest)
                    largest = count0;
            }
            else if(arr[i] == 0){
                count0++;
            }
            else if(arr[i] == 1){
                count1++;
                if(count0 > largest)
                    largest = count0;
                count0 = 0;
            }
            }
            cout<<count1+largest<<endl;
        }
        
        
    }
    return 0;
}