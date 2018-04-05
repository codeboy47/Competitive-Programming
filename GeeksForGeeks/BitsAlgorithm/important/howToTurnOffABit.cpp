#include <iostream>
using namespace std;
 

/*
The idea is to use bitwise <<, & and ~ operators. Using expression "~(1 << (k - 1))“, we get a number 
which has all bits set, except the k’th bit. If we do bitwise & of this expression with n, we get a 
number which has all bits same as n except the k’th bit which is 0.
*/

int turnOffK(int n, int k)
{
    if (k <= 0) return n;
 
    return (n & ~(1 << (k - 1)));
}
 
int main()
{
    int n = 15;
    int k = 4;
    cout << turnOffK(n, k);
    return 0;
}