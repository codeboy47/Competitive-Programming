#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
#include<cmath>
using namespace std;

int main(){
	int i,a,b,count = 0;
	vector<int> arr;
	scanf("%d %d",&a,&b); 
	int total = 0;
		arr.push_back(-1);
		arr.push_back(0);
		arr.push_back(2);
		arr.push_back(2);
		arr.push_back(5);
		arr.push_back(2);
		arr.push_back(6);
		arr.push_back(2);
		arr.push_back(9);
		arr.push_back(5);
		arr.push_back(6);
		arr.push_back(2);
		arr.push_back(12);
		arr.push_back(2);
		arr.push_back(6);
		arr.push_back(6);
		arr.push_back(14);
		arr.push_back(2);
		arr.push_back(11);
		arr.push_back(2);
		arr.push_back(12);
		arr.push_back(6);
		arr.push_back(6);
		arr.push_back(2);
		arr.push_back(20);
		arr.push_back(5);
		arr.push_back(6);
		arr.push_back(9);
		arr.push_back(12);
		arr.push_back(2);
		arr.push_back(14);
		arr.push_back(2);
		arr.push_back(20);
		arr.push_back(6);
		arr.push_back(6);
		arr.push_back(6);
		arr.push_back(20);
		arr.push_back(2);
		arr.push_back(6);
		arr.push_back(6);
		arr.push_back(20);
		arr.push_back(2);
		arr.push_back(14);
		arr.push_back(2);
		arr.push_back(12);
		arr.push_back(12);
		arr.push_back(6);
		arr.push_back(2);
		arr.push_back(30);
		arr.push_back(5);
		arr.push_back(11);

	for(i = a; i <= b; i++){
		total = total + arr[i];
	}

	printf("%d",total);
	return 0;
}
/*
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
#include<cmath>
using namespace std;

class pairD{
public:
	int count;
	int max;
	pairD() : count(0) , max(1) { }
};

pairD findDivisors(int n){
	pairD p;
	int count = 0;
	//set<int> s;
	for(int i = 1; i <= sqrt(n)+1; i++){  // O(sqrt(n))
        if(n/i == i-1){
        	continue;
        }
        if(n%i == 0){
        	count++;
       	    //s.insert(i);
       	    if(n/i != n){
       	    	p.max = max((i,p.max),n/i);
       	    	count++;
       	    	//s.insert(n/i);	
       	    }
       	    if(n/i == i){
       	    	count--;
       	    }
	    }
	}
//	cout<<p.max<<" ";
	p.count = count+1;
	//p.max = *(s.rbegin());
	//p.count = s.size()+1;
	return p;
}

int sumOfDegree(int n){
	int sum = 0;
	bool flag = true;
	pairD p;
	for(int i = n;i != 1;){
		p = findDivisors(i);
		sum = sum + p.count; 
		//cout<<sum<<" ";
		if(flag == true){
			sum--;
			flag = false;
		}
		i = p.max;
	}
	return sum+1;
}

int main(){
	int i,a,b,count = 0;
	scanf("%d %d",&a,&b); 
	int total = 0;
	for(i = a; i <= b; i++){
		total = total + sumOfDegree(i);
	}
	if(a == 1 || b == 1){
		total--;
	}
	printf("%d",total);
	return 0;
}
/*
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string.h>
#include <set>
#include<cmath>
using namespace std;

class pairD{
public:
	int count;
	int max;
	pairD() : count(0) , max(1) { }
};

pairD findDivisors(int n){
	pairD p;
	int count = 0;
	set<int> s;
	for(int i = 1; i <= sqrt(n)+1; i++){  // O(sqrt(n))
        if(n%i == 0){
        	count++;
       	    s.insert(i);
       	    if(n/i != n){
       	    	//p.max = max((i,p.max),n/i);
       	    	count++;
       	    	s.insert(n/i);	
       	    }
	    }
	}
//	cout<<p.max<<" ";
	//p.count = count+1;
	p.max = *(s.rbegin());
	p.count = s.size()+1;
	return p;
}

int sumOfDegree(int n){
	int sum = 0;
	bool flag = true;
	pairD p;
	for(int i = n;i != 1;){
		p = findDivisors(i);
		sum = sum + p.count; 
		//cout<<sum<<" ";
		if(flag == true){
			sum--;
			flag = false;
		}
		i = p.max;
	}
	return sum+1;
}

int main(){
	int i,a,b,count = 0;
	scanf("%d %d",&a,&b); 
	int total = 0;
	for(i = a; i <= b; i++){
		total = total + sumOfDegree(i);
	}
	printf("%d",total);
	return 0;
}

*/
