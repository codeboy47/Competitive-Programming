/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete below method */
void countDistinct(int A[], int k, int n){

     unordered_map<int,int> hash;

     for(int i = 0; i < k-1; i++){
          if(!hash.count(A[i])){
               hash[A[i]] = 1;
          }else{
               hash[A[i]]++;
          }
     }

     int ptr = 0;

     for(int i = k-1; i < n; i++){
          if(!hash.count(A[i])){
               hash[A[i]] = 1;
          }
          else{
               hash[A[i]]++;
          }

          cout<<hash.size()<<" ";

          hash[A[ptr]]--;
          if(hash[A[ptr]] == 0){
               hash.erase(A[ptr]);
	     }

          ptr++;

     }

}