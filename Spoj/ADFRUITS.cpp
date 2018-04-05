/*
logic longest common subsequence
then mark all common characters by backtracking
repeat
then print in a that are false
then print in b that are false
then print common chars that are true
finish
print remaining in both

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[103],b[103];
    while(scanf("%s",a)!=EOF)
    {
        scanf("%s",b);
        int alen=strlen(a),blen=strlen(b);
        int dp[alen+1][blen+1];
        int i,j;
        for(i=0;i<=alen;i++)
        {
            for(j=0;j<=blen;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        bool ta[alen],tb[blen];

        fill(ta,ta+alen,false);
        fill(tb,tb+blen,false);

        i=alen;
        j=blen;
        while(i>0&&j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ta[i-1]=true;
                tb[j-1]=true;
                i--;
                j--;
            }
            else
            {
                (dp[i][j-1]>=dp[i-1][j])?(j--):(i--);
            }
        }

        int k=0,l=0;
        while(k<alen&&l<blen)
        {
            while(k<alen&&!ta[k])
            {
                cout<<a[k];
                k++;
            }
            while(l<blen&&!tb[l])
            {
                cout<<b[l];
                l++;
            }

            while(k<alen&&l<blen&&ta[k]&&tb[l])
            {
                cout<<a[k];
                k++;
                l++;
            }
        }

        while(k<alen)
        {
            cout<<a[k];k++;
        }
        while(l<blen)
        {
            cout<<b[l];l++;
        }
        cout<<endl;
    }
    return 0;
}
