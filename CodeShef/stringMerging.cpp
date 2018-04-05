#include<bits/stdc++.h>
using namespace std;
 
int dp[6000][6000];
 
int F(char* a, int n, char* b, int m){
 
	dp[0][0] = -1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	for(int i = 2; i <= n; i++){
		if(a[i-1] != a[i-2]){
			dp[0][i] = dp[0][i-1] + 1;
		}
		else if(a[i-1] == a[i-2]){
			dp[0][i] = dp[0][i-1];
		}
	}
	
	for(int i = 2; i <= m; i++){
		if(b[i-1] != b[i-2]){
			dp[i][0] = dp[i-1][0] + 1;
		}
		else if(b[i-1] == b[i-2]){
			dp[i][0] = dp[i-1][0];
		}
	}	
 
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
 
			if(i != 1 && b[i-1] == b[i-2]){
				dp[i][j] = dp[i-1][j];
			}
			else if(j != 1 && a[j-1] == a[j-2]){
				dp[i][j] = dp[i][j-1];
			}
			else if(b[i-1] == a[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				//dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
			else if(b[i-1] != a[j-1]){
				dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	/*for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
 
	return dp[m][n];
 
 
}
 
int main(){
 
	int t;
	char a[10000],b[10000];
	cin>>t;
	while(t--){
 
		int n1,n2;
		cin>>n1>>n2;
		cin>>a>>b;
		cout<<1+F(a,n1,b,n2)<<endl;
	}
 
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
 
int F(string a, int n, string b, int m){
 
	int dp[n+1];
 
 
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
 
			if(i == 0){
				if(j < 2){
					dp[j] = 0;
				}else{
					if(a[j-1] != a[j-2]){
						dp[j] = dp[j-1] + 1;
					}
					else{
						dp[j] = dp[j-1];
					}
				}
			}
			else if(j == 0){
				if(i < 2){
					dp[j] = 0;
				}else{
					if(b[i-1] != b[i-2]){
						dp[j] = dp[j] + 1;
					}
					else{
						dp[j] = dp[j];
					}
				}
			}
			else if(i != 1 && b[i-1] == b[i-2]){
				dp[j] = dp[j];
			}
			else if(j != 1 && a[j-1] == a[j-2]){
				dp[j] = dp[j-1];
			}
			else if(b[i-1] == a[j-1]){
				dp[j] = 1 + dp[j-1];
			}
			else if(b[i-1] != a[j-1]){
				dp[j] = 1 + min(dp[j],dp[j-1]);
			}
 
			//cout<<dp[j]<<" ";
		}
		//cout<<endl;
	}
	
	return dp[n];
 
 
}
 
int main(){
 
	int t;
	string a,b;
	cin>>t;
	while(t--){
 
		int n1,n2;
		cin>>n1>>n2;
		cin>>a>>b;
		cout<<1+F(a,n1,b,n2)<<endl;
	}
 
	return 0;
} 
*/