

struct val{
	int first;
	int second;
};


bool compare(struct val a, struct val b){
    return a.second > b.second;
}

int maxChainLen( struct val arr[], int n) {

   sort(arr,arr+n,compare); // sort in decreasing order of second(larger) element.

   int i, j, max = 0;
   int dp[n];

   dp[0] = 1;
   for (i = 1; i < n; i++){
      int ans = 0;
      for (j = i-1; j >= 0; j--){
         if(arr[j].first > arr[i].second)
                if(dp[j] > ans)
                    ans = dp[j];
      }
      dp[i] = ans + 1;
   }

   int len = -1;
   for ( i = 0; i < n; i++ )
        if(len < dp[i])
            len = dp[i];

   return len;
}
