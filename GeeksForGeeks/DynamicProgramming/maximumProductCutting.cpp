#include <iostream>
using namespace std;

/* The main function that teturns the max possible product */
int maxProd(int n)
{
// n equals to 2 or 3 must be handled explicitly
if (n == 2 || n == 3) return (n-1);

// Keep removing parts of size 3 while n is greater than 4
int res = 1;
while (n > 4)
{
	n -= 3;
	res *= 3; // Keep multiplying 3 to res
}
return (n * res); // The last part multiplied by previous parts
}

int maxProd2(int n)
{
int val[n+1];
val[0] = val[1] = 0;

// Build the table val[] in bottom up manner and return
// the last entry from the table
for (int i = 1; i <= n; i++)
{
	int max_val = 0;
	for (int j = 1; j < i; j++)
		max_val = max(max_val, max(j*(i-j), j*val[i-j]));
	val[i] = max_val;
}
return val[n];
}

/* Driver program to test above functions */
int main()
{
	cout << "Maximum Product is " << maxProd(10) <<endl << maxProd2(10);
	return 0;
}
