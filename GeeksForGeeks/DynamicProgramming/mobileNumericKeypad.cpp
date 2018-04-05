#include <bits/stdc++.h>
using namespace std;

int countOfNosHelper(int n, int i, int j){

    if(i == 4 || i == -1 || j == 3 || j == -1){
        return 0;
    }
    if((i == 3 && j == 0) || (i == 3 && j == 2)){
        return 0;
    }

    if(n == 1){
        return 1;
    }

    int count = 0;

    count += countOfNosHelper(n-1,i,j) + countOfNosHelper(n-1,i-1,j) + countOfNosHelper(n-1,i,j-1) + countOfNosHelper(n-1,i+1,j) + countOfNosHelper(n-1,i,j+1);

    return count;

}

// recursive solution
int countOfNos(int n){

    if(n <= 0)
        return 0;
    if(n == 1)
        return 10;

    int count = 0;
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 2; j++){
            if((i == 3 && j == 0) || (i == 3 && j == 3)){
                // do nothing
            }else{
                count += countOfNosHelper(n,i,j);
            }
        }
    }

    return count;
}


// bottom up dp approach O(n) time and O(n) space
long countOfNosBottomUpDP(char keypad[][3], int n){

    long dp[10][n+1];
    //memset(dp,0,sizeof(dp));

    for(int i = 0; i < 10; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for(int k = 2; k <= n; k++){
        for(int i = 0; i <= 3; i++){
            for(int j = 0; j <= 2; j++){

                if(keypad[i][j] != '*' && keypad[i][j] != '#'){

                    dp[keypad[i][j]-48][k] = dp[keypad[i][j]-48][k-1];

                    if(i != 0 && keypad[i-1][j] != '*' && keypad[i-1][j] != '#') // up
                        dp[keypad[i][j]-48][k] += dp[keypad[i-1][j]-48][k-1];

                    if(i != 3 && keypad[i+1][j] != '*' && keypad[i+1][j] != '#') // down
                        dp[keypad[i][j]-48][k] += dp[keypad[i+1][j]-48][k-1];

                    if(j != 0 && keypad[i][j-1] != '*' && keypad[i][j-1] != '#') // left
                        dp[keypad[i][j]-48][k] += dp[keypad[i][j-1]-48][k-1];

                    if(j != 2 && keypad[i][j+1] != '*' && keypad[i][j+1] != '#') // right
                        dp[keypad[i][j]-48][k] += dp[keypad[i][j+1]-48][k-1];

                }
            }
        }
    }


    long count = 0;
    for(int i = 0; i <= 9; i++){
        count += dp[i][n];
    }

    return count;
}

int main(){

    int t;
    cin>>t;
    char keypad[4][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}};
    while(t--){

        int n;
        cin>>n;

        cout<<countOfNos(n)<<endl;
        cout<<countOfNosBottomUpDP(keypad,n)<<endl;

    }

    return 0;
}
