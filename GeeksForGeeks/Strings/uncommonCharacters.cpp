#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

void findAndPrintUncommonChars(string str1, string str2)
{

    int present[MAX_CHAR];
    for (int i=0; i<MAX_CHAR; i++)
        present[i] = 0;

    int l1 = str1.size();
    int l2 = str2.size();

    for (int i=0; i<l1; i++)
        present[str1[i] - 'a'] = 1;

    for (int i=0; i<l2; i++)
    {
        if (present[str2[i] - 'a'] == 1
            || present[str2[i] - 'a'] == -1)
            present[str2[i] - 'a'] = -1;

        else
            present[str2[i] - 'a'] = 2;
    }

    // print all the uncommon characters
    for (int i=0; i<MAX_CHAR; i++)
        if (present[i] == 1 || present[i] == 2 )
            cout << (char(i + 'a'));
}

int main(){

     int t;
     cin>>t;
     while(t--){

          set<char> s;
          string str1,str2;
          cin>>str1>>str2;
          findAndPrintUncommonChars(str1,str2);

          cout<<endl;

     }

     return 0;
}
