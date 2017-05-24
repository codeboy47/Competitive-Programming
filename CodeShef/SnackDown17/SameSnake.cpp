#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <limits>
using namespace std;
 
int main(){
	int x11,y11,x12,y12,x21,y21,x22,y22;
	int t,sum1 = 0,sum2 = 0;
	cin>>t;
	while(t--){
		sum1 = 0;
		sum2 = 0;
		cin>>x11>>y11>>x12>>y12;
		cin>>x21>>y21>>x22>>y22;
		if(x11 == x21 && y11 == y21){
			cout<<"yes"<<endl;
		}
		else if(x11 == x22 && y11 == y22){
			cout<<"yes"<<endl;
		}
		else if(x12 == x21 && y12 == y21){
			cout<<"yes"<<endl;
		}
		else if(x12 == x22 && y12 == y22){
			cout<<"yes"<<endl;
		}
		else if(x11 == x12 && x12 == x21 && x21 == x22){
			sum1 = y11 + y12;
			sum2 = y21 + y22;
			if(sum1 > sum2){
				if(max(y21,y22) - min(y11,y12) >= 0){
					cout<<"yes"<<endl;
				}else{
					cout<<"no"<<endl;
				}
			}else if(sum2 > sum1){
				if(max(y11,y12) - min(y21,y22) >= 0){
					cout<<"yes"<<endl;
				}else{
					cout<<"no"<<endl;
				}
			}
			else if(sum1 == sum2){
				cout<<"yes"<<endl;
			}
		}
		else if(y11 == y12 && y12 == y21 && y21 == y22){
			sum1 = x11 + x12;
			sum2 = x21 + x22;
			if(sum1 > sum2){
				if(max(x21,x22) - min(x11,x12) >= 0){
					cout<<"yes"<<endl;
				}else{
					cout<<"no"<<endl;
				}
			}else if(sum2 > sum1){
				if(max(x11,x12) - min(x21,x22) >= 0){
					cout<<"yes"<<endl;
				}else{
					cout<<"no"<<endl;
				}
			}
			else if(sum1 == sum2){
				cout<<"yes"<<endl;
			}
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
