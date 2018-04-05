/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* You are required to complete this method*/
int findEquilibrium(int arr[], int n){

     int sum = 0;
     for(int i = 0; i < n; i++){
          sum += arr[i];
     }

     int sumForward = 0;
     for(int i = 1; i < n-1; i++){
          sumForward += arr[i-1];
          if(sumForward == sum - sumForward - arr[i]){
               return i;
          }
     }
     return -1;
}
