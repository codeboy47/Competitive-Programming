// difference between ++i and i++ in for loop
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i = 0;
	int j = 0;
	cout<<"i= "<<i++<<" &	j= "<<++j<<endl;
	for(i = 0;i<10;i++)
		cout<<i<<" ";
	cout<<endl;
	for(j = 0; j < 10;++j)
		cout<<j<<" ";
	
	return 0;
}
// answer no difference in loop but value of j increments first then updated
// to j where as value of i is updated first then incremented