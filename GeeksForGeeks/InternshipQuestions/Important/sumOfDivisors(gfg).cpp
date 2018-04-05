#include <bits/stdc++.h>
using namespace std;

int divSum(int num){

    int sum = 0;

    for (int i=2; i<=sqrt(num); i++){

        if (num%i==0){
            if(num/i == i) // if both divisors are same
                sum += i;
            else
                sum += i + num/i;
        }
    }

    // Add 1 to the result as 1 is also a divisor
    return (sum + 1);
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        cout<<divSum(n)<<endl;

    }

    return 0;
}
