#include <bits/stdc++.h>
using namespace std;

// this is not a dp question

void maxLeftSubArraySum(int a[], int size, int sum[])
{
    int curr_max = 0;

    for (int i = 0; i < size; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        sum[i] = curr_max;
    }

}


void maxRightSubArraySum(int a[], int n, int sum[])
{
    int curr_max = 0;

    for (int i = n-1; i >= 0; i--)
    {
        curr_max = max(a[i], curr_max + a[i]);
        sum[i] = curr_max;
    }

}

int findMaxAbsDiff(int arr[], int n)
{
    int leftMax[n];
    maxLeftSubArraySum(arr, n, leftMax);

    int rightMax[n];
    maxRightSubArraySum(arr, n, rightMax);

    // Invert array (change sign) to find minumum
    // sum subarrays.
    int invertArr[n];
    for (int i = 0; i < n; i++)
        invertArr[i] = -arr[i];

    int leftMin[n];
    maxLeftSubArraySum(invertArr, n, leftMin);
    for (int i = 0; i < n; i++)
        leftMin[i] = -leftMin[i];

    int rightMin[n];
    maxRightSubArraySum(invertArr, n, rightMin);
    for (int i = 0; i < n; i++)
        rightMin[i] = -rightMin[i];

    int result = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        int absValue = max(abs(leftMax[i] - rightMin[i + 1]),
                        abs(leftMin[i] - rightMax[i + 1]));
        if (absValue > result)
            result = absValue;
    }

    return result;
}


int main(){

    int arr[100000];
    int t;
    cin>>t;
    while(t--){


        int n;
        cin>>n;

        for(int i = 0; i <  n; i++){
            cin>>arr[i];
        }

        cout<<findMaxAbsDiff(arr,n)<<endl;

    }

    return 0;
}
