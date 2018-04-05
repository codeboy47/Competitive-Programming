#include <bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main(){
	int t;
	vector<long> arr,store; 
	long o1,o2,n,i,j,count1=0,counter=0,count,k,index=0,z=0;
	long pres=0,gov=0;
	scanf("%d",&t);
	while(t--){
		scanf("%ld %ld",&o1,&o2);
		n = o1*o2;
		for(i = 0;i < n;i++){
			long e;
			scanf("%ld",&e);
			arr.push_back(e);
		}
		for(i = 0;i < n;i++){
			if(arr[i] == 1){
				count1++;
			}	
		}
		if(count1 > n/2){ 
			printf("1\n");
		}
		//else if(count1 < o1*(o2/2) || count1 < n/2 - min(o1,o2) ){
		else if(count1 < ((o1/2)+1)*((o2/2)+1) ){
			printf("0\n");
		}
		else{
	
			for(i = 0;i < n-1;i++){
				if(arr[i] == 1 && arr[i+1] == 0){
					store.push_back(i);
				}
				else if(arr[i] == 0 && arr[i+1] == 1){
					store.push_back(i);
				}
			}
			if(arr[0] == 1 && arr[n-1] == 0){
				store.push_back(n-1);
			}
			else if(arr[0] == 0 && arr[n-1] == 1){
				store.push_back(n-1);
			}
			for(z = 0;z < store.size();z++){
				j = 0;
				k = store[z];
				gov = 0;
				counter = 0;
				count = 0;
				//store pos of 1 in array and select range L R = L+o2-1|| L = R+1
				while(j < o1){
					if(arr[k] == 1){
						count++;
					}
					k++;
					counter++;
					if(k == n){
						k = 0;
					}
					if(counter == o2){
						j++;
						counter = 0;
						if(count > o2/2){
							gov++;
						}
						count = 0;
					}
				}
				if(gov > o1/2){
					printf("1\n");
					break;
				}
				gov = -1;
			}
		}
		if(gov == -1){
			printf("0\n");
		}
		gov = 0;
		count1 = 0;
		count = 0;
		counter = 0;
		k = 0;
		arr.clear();
		store.clear();
	}

	return 0;
}
/*
#include <bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int main(){
	int t;
	vector<long> arr,store; 
	long o1,o2,n,i,j,count1=0,counter=0,count,k,index=0,z=0,count0=0,counter2=0;
	long pres=0,gov=0;
	scanf("%d",&t);
	while(t--){
		scanf("%ld %ld",&o1,&o2);
		n = o1*o2;
		for(i = 0;i < n;i++){
			long e;
			scanf("%ld",&e);
			arr.push_back(e);
		}
		for(i = 0;i < n;i++){
			if(arr[i] == 1){
				count1++;
			}	
		}
		if(count1 > n/2){ // check this
			printf("1\n");
		}
		else if(count1 < ((o1/2)+1)*((o2/2)+1) ){
			printf("0\n");
		}
		else if(count1 == n/2){
			for(i = 0;i < n-1;i++){
				if(arr[i] == 1 && arr[i+1] == 0){
					store.push_back(i);
				}
				else if(arr[i] == 0 && arr[i+1] == 1){
					store.push_back(i);
				}
			}
			if(arr[0] == 1 && arr[n-1] == 0){
				store.push_back(n-1);
			}
			else if(arr[0] == 0 && arr[n-1] == 1){
				store.push_back(n-1);
			}
			for(z = 0;z < store.size();z++){
				j = 0;
				k = store[z];
				gov = 0;
				counter = 0;
				count = 0;
				while(j < o1){
					if(arr[k] == 1){
						count++;
					}
					k++;
					counter++;
					if(k == n){
						k = 0;
					}
					if(counter == o2){
						j++;
						counter = 0;
						if(count > o2/2){
							gov++;
						}
						count = 0;
					}
				}
				if(gov > o1/2){
					printf("1\n");
					break;
				}
				gov = -1;
			}
			if(gov == -1){
				printf("0\n");
			}
		}
		else{
			count0 = 1;
			index = 0;
			counter2 = 0;
			for(i = index;i < n;i++){
				if(i == n-1 && arr[i] == 0 && arr[0] == 0){
					long y = 0;
					while(arr[y] != 1){
						count0++;
						index++;
						y++;
					}
					if(index >= (o2/2) + 1){
						counter2--;
					}
					if(count0 >= (o2/2) + 1){
						//cout<<"count0=="<<count0<<" ";
						counter2++;
					}
				}
				else if(i != n-1 && arr[i] == 0 && arr[i+1] == 0){
					count0++;
				}
				else if(arr[i] == 1){
					count0 = 1;
				}
				else if(count0 >= (o2/2) + 1){
					//cout<<"count0="<<count0<<" ";
					counter2++;
				}
			}
			if(counter2 >= (o1/2)+1){
				cout<<0<<endl;
			}else{
				cout<<1<<endl;
			}
		}
		index= 0;
		gov = 0;
		count1 = 0;
		count0 = 0;
		counter2 = 0;
		count = 0;
		counter = 0;
		k = 0;
		arr.clear();
		store.clear();
	}
	return 0;
}	
*/