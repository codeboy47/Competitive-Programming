#include <iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}

int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;

    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}

/* Implementation of Quick Sort
A[] --> Array to be sorted
si  --> Starting index
ei  --> Ending index
*/
void quickSort(int A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}
int main() {
	int i,n,T,target,arr[100000];
	cin>>T;
	while(T--){
	    bool flag = false;
    	cin>>n>>target;
    	for(i = 0;i <n;i++){
    		cin>>arr[i];
    	}
    	quickSort(arr, 0,n-1);
    	//sort(arr,arr+n);
    	int end = n-1;
    	for(i = 0;i < end;){
    		if(arr[end] == target - arr[i]){
    			flag = true;
    			break;
    		}
    		if(arr[end] > target - arr[i]){
    			end--;
    		}
    		if(arr[end] < target - arr[i]){
    			i++;
    		}
    	}
    	if(flag == true){
    	    cout<<"Yes"<<endl;
    	}else{
    	    cout<<"No"<<endl;
    	}
	}
	return 0;
}