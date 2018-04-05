#include <bits/stdc++.h>
using namespace std;

int patternCount(string str)
{
    char last = str[0];

    int i = 1, counter = 0;
    while (i < str.size())
    {
        /* We found 0 and last character was '1',
          state change*/
        if (str[i] == '0' && last == '1')
        {
            while (str[i] == '0')
                i++;

            /* After the stream of 0's, we got a '1',
               counter incremented*/
            if (str[i] == '1')
                counter++;
        }

        /* Last character stored */
        last = str[i];
        i++;
    }

    return counter;
}

int main(){

     int t;
     char str[10000];
     cin>>t;
     while(t--){
          
          cin>>str;
          
          cout<<patternCount(str)<<endl;
          
     }

     return 0;
}