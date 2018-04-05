// http://stackoverflow.com/questions/1701067/how-to-check-that-an-element-is-in-a-stdset
#include<bits/stdc++.h>
#include<vector>
#include<string.h>
#include<set>
#include<map>

using namespace std;

int main(){
    bool flag = true;
    set<int> v;
    int i,count = 1,wt=0;
    string s;
    getline (cin,s);
    //cin >> s;
    int n;
    scanf("%d",&n);
    //cin >> n;
    for(i = 1;i <= s.size();i++){
        if(s[i-1] != s[i]){
            wt = s[i-1] - 96;
            v.insert(wt);
            //v.push_back(wt);
            count = 1;
        }else{
            count++;
            wt = (s[i-1] - 96)*count;
            v.insert(wt);
            //v.push_back(wt);          
        }
    }
    for(int a0 = 0; a0 < n; a0++){
        int x;
        scanf("%d",&x);
        /*cin >> x;
        for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it){
            if(*it == x){
                printf("Yes\n");
                //cout<<"Yes"<<endl;
                flag = false;
                //v.erase(it);
                break;
            }
        }
        if(flag == true){
            printf("No\n");
            //cout<<"No"<<endl;
        }
        flag = true;*/
        
        if(v.count(x) == 1){  // to check element is present or not
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}
