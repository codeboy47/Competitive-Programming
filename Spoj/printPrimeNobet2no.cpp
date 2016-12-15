/*Your task is to generate all prime numbers between two given numbers!

Input

The input begins with the number t of test cases in a single line (t<=10).
In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
*/

#include <iostream>
using namespace std;

int main() {

	// your code here
    long long int t,m,n,i,j,k;
    cin>>t;
    for(k = 0; k < t; k++){
        cin>>m>>n;
        for(i = m; i <= n; i++){
            for(j = 2; j*j < i; j++){
                if(i%j==0)
                    break;
            }
            if(j == i){
                cout<<j<<endl;
            }
        }
        cout<<endl;
    }

	return 0;
}
/*
#include <iostream>
using namespace std;

int main() {

	// your code here
    long long int t,m,n,i,j,k,flag=0;
    cin>>t;

    cin>>m>>n;

        for(i = m; i <= n; i++){
            for(j = 2; j < i; j++){
                if(i%j==0)
                    break;
            }
            if(j == i){
                cout<<j<<endl;
            }
        	if(i==n && flag < t-1){
        		flag++;
        		cin>>m>>n;
        		i=m-1;
        	}
        }


	return 0;
}

*/
