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


int main(){
    int q;
    int count = 0;
    int sum1 = 0,sum2 = 0;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector< vector<int> > M(n,vector<int>(n));
        for(int M_i = 0;M_i < n;M_i++){
           for(int M_j = 0;M_j < n;M_j++){
              cin >> M[M_i][M_j];
           }
        }
        for(int i = 0;i < n-1;i++){
           for(int j = 0;j < n;j++){
                if(M[i][j] == M[i+1][j]){
                    count++;
                }
               //sum1 = M[i][j] +sum1;  
           }
        }
        if(count == n){
            cout<<"Possible"<<endl;
        }else{
            cout<<"Impossible"<<endl;
        }
        count = 0;
        
        
        // your code goes here
    }
    return 0;
}
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


int main(){
    int q;
    int sum1 = 0,sum2 = 0;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector< vector<int> > M(n,vector<int>(n));
        for(int M_i = 0;M_i < n;M_i++){
           for(int M_j = 0;M_j < n;M_j++){
              cin >> M[M_i][M_j];
           }
        }
        for(int i = 0;i < n;i++){
           for(int j = 0;j < n;j++){
      
               sum1 = M[i][j] +sum1;  
           }
            if(i == n-1){
                if(sum1 == sum2){
                    cout<<sum1<<sum2<<"Possible"<<endl;
                   
                }
                else{
                    cout<<sum1<<sum2<<"Impossible"<<endl;
                }
                break;
            }
            sum2 = sum1;
            sum1 = 0;
        }
        sum1 = 0;
        sum2 = 0;
        
        // your code goes here
    }
    return 0;
}
