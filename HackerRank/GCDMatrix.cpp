#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int gcd(int a, int b) {
    if (a%b == 0){
        return b;
    }
    return gcd(b, a%b);
   
}

int main(){
    multiset<int> s;
    int n,count = 0;
    int m;
    int q;
    cin >> n >> m >> q;
    //int a[1000];
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    //int b[1000];
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    vector< vector<int> > arr(n,vector<int>(m));
    vector< vector<int> > M(n,vector<int>(m));
    //int arr[10000][10000];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            arr[i][j] = gcd(a[i],b[j]);   
            s.insert(arr[i][j]);
            if(s.count(arr[i][j]) == 1){
                count++;
                          
            }
            M[i][j] = count;
        }
    }
   /*for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<M[i][j]<<" ";       
        }
        cout<<endl;
    }*/
    for(int a0 = 0; a0 < q; a0++){
        int r1;
        int c1;
        int r2;
        int c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        cout<<M[r2][c2]<<endl;
        count = 0;
    }
    return 0;
}
/*
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int gcd(int a, int b) {
    if (a%b == 0){
        return b;
    }
    return gcd(b, a%b);
   
}

int main(){
    multiset<int> s;
    int n,count = 0;
    int m;
    int q;
    cin >> n >> m >> q;
    //int a[1000];
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    //int b[1000];
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    vector< vector<int> > arr(n,vector<int>(m));
    vector< vector<int> > M(n,vector<int>(m));
    //int arr[10000][10000];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            arr[i][j] = gcd(a[i],b[j]);   
            s.insert(arr[i][j]);
            if(s.count(arr[i][j]) == 1){
                count++;
                          
            }
            M[i][j] = count;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<M[i][j]<<" ";       
        }
        cout<<endl;
    }
    for(int a0 = 0; a0 < q; a0++){
        int r1;
        int c1;
        int r2;
        int c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        cout<<M[r2][c2]<<endl;
        count = 0;
    }
    return 0;
}

*/
