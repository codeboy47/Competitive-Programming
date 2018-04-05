#include <iostream>
using namespace std;

long maxHappiness(int arr[], int n){

    long sum[100000];
    int ts = 0;
    for(int i = 0; i < n; i++){
        ts += arr[i];
        sum[i] = ts;
    }

    int cs = 0;
    int s = 0;
    int ms = 0;
    for(int i = 0; i < n; i++){

        cs += arr[i];

        if(arr[i] < 0){
            int sep = ms + arr[i] + (ts-sum[i])*(n-i-1);
            int full = ts*n;
            int left = cs*(i-s+1) + (ts-sum[i])*(n-i-1);
            int right = ms + (ts-sum[i]+arr[i])*(n-i);

            if(sep > ms && sep > full && sep > left && sep > right){
                ms += arr[i];
                s = i+1;
                cs = 0;
            }
            if(left > ms && left > sep && left > full && left > right){
                ms += cs*(i-s+1);
                s = i + 1;
                cs = 0;
            }
            if(right > ms && right > sep && right > full && right > left){
                ms += arr[i];
            }
        }

    }

    return ms;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[100000];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<maxHappiness(arr,n)<<endl;
    }

    return 0;
}

/*
#include <iostream>
using namespace std;

long maxHappiness(int arr[], int n){

    long sum[100000];
    int ts = 0;
    for(int i = 0; i < n; i++){
        ts += arr[i];
        sum[i] = ts;
    }

    int cs = 0;
    int s = 0;
    int ms = 0;
    for(int i = 0; i < n; i++){

	    cs += arr[i];

	    if(arr[i] == 0){
	            if((ts-sum[i])*(n-i-1) < 0){
	                s++;
	            }
	    }

        if(arr[i] < 0){
            if(cs*(i-s+1) >= (ts-sum[i])*(n-i-1) && (ts-sum[i])*(n-i-1) > 0){
                ms += (cs-arr[i])*(i-s);
                ms += arr[i];
                cs = 0;
                s = i+1;
            }

            if((ts-sum[i])*(n-i-1) < 0){
                s++;
            }

        }

    }

	cout<<s<<" ";
    ms += cs*(n-s);
    return ms;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[100000];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<maxHappiness(arr,n)<<endl;
    }

    return 0;
}

*/
