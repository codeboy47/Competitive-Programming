#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverse1(long long int *arr,long long int start,long long int end,long long int n){
     long long int j = end,arr2[1000000],i;
    for(i = 0;i < n;i++){
        arr2[i] = arr[i];
    }
   
    for(i = start;i <= end;i++){
        arr[j--] = arr2[i];
    }
    return;
}

bool checkSort(long long int*arr,long long int n){
    long long int i;
    for(i = 1;i<n;i++){
        if(arr[i-1] > arr[i]){
            return false;
            //break;
        }
    }  
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    bool flag = true;
    long long int arr[1000000];
    long long int i,j,k,n,start2=0,end2=0,start1=0,end1=0,next=0,prev=0;
    cin>>n;
    end1 = n-1;
  
    for(i = 0;i < n;i++){
        cin>>arr[i];
    }
    bool ans0 = checkSort(arr,n);
    
    prev = arr[0];
    next = arr[n-1];
    for(i = 1;i < n;i++){
        if(flag == true && arr[i] < arr[i-1]){
            start1 = i-1;
            flag = false;
            if(i == 1){
                prev = arr[i];
                next = arr[i];
            }
            if(i-2!=-1){
                prev= arr[i-2];
                next = arr[i];
            }
            //i++;
        }
        if(flag==false && (arr[i] >= prev && arr[i] <= next)){
            end1 = i;
        }
    }
    
    long long int t = arr[start1];
    arr[start1] = arr[end1];
    arr[end1] = t;
    
    bool ans1 = checkSort(arr,n);

    t = arr[start1];
    arr[start1] = arr[end1];
    arr[end1] = t;
    
    if(ans1 == false){
        start2 = 0;
        end2 = n-1;
        flag = true;
        for(i = 1;i < n;i++){
            if(flag == false && i == n-1){
                end2 = i;
            }
            if(arr[i] > arr[i-1]){
                end2 = i-1;
            }
            if(flag == true && arr[i] < arr[i-1]){
                start2 = i-1;
                flag = false;
                //i++;
            }
        }
    }
    reverse1(arr,start2,end2,n);
    bool ans2 = checkSort(arr,n);
    //cout<<n;
    if(ans0 == true){
        cout<<"yes";
    }
    else if(ans1 == true){
        cout<<"yes"<<endl<<"swap ";
        cout<<start1+1<<" "<<end1+1;
        //return 0;
    }
    else if(ans2 == true) {
        cout<<"yes"<<endl<<"reverse ";
        cout<<start2+1<<" "<<end2+1;
    }
    else{
        cout<<"no";
    }
    return 0;
}

////-----------------ANOTHER WAY------------------------------
// here we count no of ups(arr[i] > next and prev) and dips(arr[i] < next and prev) from i=0 to i=n-2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    bool flag = true;
    long long int arr[1000000];
    long long int i,n,start=0,end=0,next=0,prev=0,dip=0,up=0;
    cin>>n;
    
    for(i = 0;i < n;i++){
        cin>>arr[i];
    }
    start = 0; 
    end = n-1;
    prev = arr[0];
    next = arr[n-1];
    for(i = 1;i < n-1;i++){
        prev = arr[i-1];
        next = arr[i+1];
        if(arr[i] > next && arr[i] > prev){
            up++;
            if(flag == true){
                start = i;
                flag = false;
            }
        }
        if(arr[i] < next && arr[i] < prev){
            dip++;
            end = i;
        }
    }
    
    if(n == 2 && prev > next ){
        cout<<"yes"<<endl<<"swap ";
        cout<<start+1<<" "<<end+1;
    }
    else if(dip > 2 || up > 2){
        cout<<"no";
    }
    else if(up == 2 && dip == 1){
        cout<<"yes"<<endl<<"swap ";
        cout<<start+1<<" "<<n;
    }
    
    
    else if(up == 2 && dip == 2){
        if(arr[end] < arr[start-1]){
            cout<<"no";
        }else{
        cout<<"yes"<<endl<<"swap ";
        cout<<start+1<<" "<<end+1; 
        }
    }
    else if(up == 1 && dip == 1){
        
        if(arr[end] > arr[start-1] && start == end-1){
            cout<<"yes"<<endl<<"swap ";
            cout<<start+1<<" "<<end+1;   
        }
        else if(arr[end] < arr[start-1]){
            cout<<"no";
        }else{
            cout<<"yes"<<endl<<"reverse ";
            cout<<start+1<<" "<<end+1;
        }
    }
    else if(up == 1 && dip == 0){
        cout<<"yes"<<endl<<"reverse ";
        cout<<start+1<<" "<<n;
    }
    else if(dip == 0 && up == 0){
        cout<<"yes";
    }
    else if(dip == 1 && arr[0] < arr[2]){
        cout<<"yes"<<endl<<"swap ";
        cout<<start+1<<" "<<start+2;   
    }
    else if(up == 1 && arr[n-2] > arr[n-1]){
        cout<<"yes"<<endl<<"swap ";
        cout<<end<<" "<<end+1;
    } 
    else{
        cout<<"no";
    }
    
    
    return 0;
}
