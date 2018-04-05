#include <bits/stdc++.h>
using namespace std;

// recursion and maths question

int recursiveSumOfDigits(int n){

    if(n == 0)  return 0;

    return n%10 + recursiveSumOfDigits(n/10);
}


int sumOfDigitSum(int n){

    if(n < 9)   return n;

    int sum = recursiveSumOfDigits(n);

    if(sum < 10) return sum;

    else recursiveSumOfDigits(sum);

}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        cout<<sumOfDigitSum(n)<<endl;

    }

    return 0;
}
