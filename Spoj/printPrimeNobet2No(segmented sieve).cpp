// print prime nos bet 2 nos using segmented sieve

// C++ program to print all primes smaller than or equal to
// n using Segmented Sieve

#include <iostream>
#include <cmath>
using namespace std;

int simpleSieve(int limit, int prime[],int c,int m,int n){
    int i,j;
    bool arr[limit+1];
    for(i=0;i<limit;i++){
        arr[i] = true;
    }

    for(i=2;i*i<limit;i++){  // not including 11 for limit = 11 and n = 100
        if(arr[i] == true){
            for(j=2*i;j<limit;j=j+i){
                arr[j] = false;
            }
        }
    }
    i = 0;
    for(j=2;j<limit;j++){
        if(arr[j] == true){
            prime[i] = j;
            c++;
            i++;
            if(j > m && j < n)
            cout<<j<<" ";
        }
    }

    return c;
}

void segmentedSieve(int m, int n){
    int i,j;
    int limit = sqrt(n)+1;
    int prime[n];
    //cout<<sizeof(prime)/sizeof(prime[0])<<"ddd";
    int size = simpleSieve(limit,prime,0,m,n) ;
    int low = limit;
    int high = 2*limit; /// i.e if n = 100 ,limit = 11, low =11, high = 22 that is segment difference is 11
    while(low < n){
       bool mark[limit+1];
       for(i=0;i<limit;i++){
            mark[i] = true;
       }
       for(i=0;i<size;i++){
            int loLim = (low/prime[i])*prime[i];
            if(loLim < low)
                loLim = loLim + prime[i];
            //if(mark[i] == true)
            for(j = loLim; j < high; j = j + prime[i]){
                mark[j-low] = false;
            }
       }
       for(j = low; j < high; j++){
                if(mark[j-low] == true && m <= j && j <= n)
                    cout<<j<<" ";
        }
        low = low + limit;
        high = high + limit;
        if(high > n) high = n;
    }
}

int main(){

    int i,t;
    cin>>t;
    for(i = 0; i < t; i++){
        int m,n;
        cin>>m>>n;
        segmentedSieve(m,n);
    }
    return 0;
}

/*
// C++ program to print print all primes smaller than
// n using segmented sieve
#include <bits/stdc++.h>
using namespace std;

// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]
void simpleSieve(int limit, vector<int> &prime, int m, int n)
{
	// Create a boolean array "mark[0..n-1]" and initialize
	// all entries of it as true. A value in mark[p] will
	// finally be false if 'p' is Not a prime, else true.

}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int m, int n)
{
	// Compute all primes smaller than or equal
	// to square root of n using simple sieve

}

// Driver program to test above function
int main()
{
	long long int i,j,k,t,n,m,limit,low,high,p,loLim;
	cin>>t;
	for(k = 0; k < t; k++){
		cin>>m>>n;
		//segmentedSieve(m,n);
		limit = (sqrt(n))+1;
		vector<long long int> prime;
		//simpleSieve(limit, prime,m,n);
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));

		for (p=2; p*p<limit; p++)
		{
		// If p is not changed, then it is a prime
		if (mark[p] == true)
		{
			// Update all multiples of p
			for (j=p*2; j<limit; j+=p)
				mark[j] = false;
		}
		}

	// Print all prime numbers and store them in prime
	for (p=2; p<limit; p++)
	{
		if (mark[p] == true)
		{
			prime.push_back(p);
			if(p > m && p < n)
			cout << p << endl;
		}
	}

		low = limit;
		high = 2*limit;

	while (low < n)
	{
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));

		// Use the found primes by simpleSieve() to find
		// primes in current range
		for (i = 0; i < prime.size(); i++)
		{
			// Find the minimum number in [low..high] that is
			// a multiple of prime[i] (divisible by prime[i])
			// For example, if low is 31 and prime[i] is 3,
			// we start with 33.
			loLim = floor(low/prime[i]) * prime[i];
			if (loLim < low)
				loLim += prime[i];

			for (j=loLim; j<high; j+=prime[i])
				mark[j-low] = false;
		}

		// Numbers which are not marked as false are prime
		for (i = low; i<high; i++)
			if (mark[i - low] == true && m <= i && i <= n)
				cout << i << endl;

		// Update low and high for next segment
		low = low + limit;
		high = high + limit;
		if (high >= n) high = n;
	}
	cout<<endl;
	}
	return 0;
}

*/
