#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
using namespace std;

string dictword(vector<string>&dict,string a,int m)
{
    int i,j,len=INT_MIN;
    string ans="";
    for(i=0;i<m;i++)
    {
        string b= dict[i];
        int la= a.length(),lb= b.length();
        
        int count=0;
        
        for(j=0;j<la;j++)
        {
            if(b[count]==a[j])
            count++;
        }
        
        if(count==lb)
        {
            if(len<count)
            {
                ans=b;
                len=count;
            }
        }
        
    }
    
    return ans;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,i;
	    cin>>m;
	    string s;
	    vector<string>dict;
	    for(i=0;i<m;i++)
	    {
	        cin>>s;
	        dict.push_back(s);
	    }
	    
	    cin>>s;
	    string ans= dictword(dict,s,m);
	    cout<<ans<<endl;
	}
	return 0;
}