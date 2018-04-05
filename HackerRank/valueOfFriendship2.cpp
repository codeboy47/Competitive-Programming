// this question is done by disjoint set and union
// https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
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
    unordered_map<int,int> hash;
    long prevX,prevY;
    int t;
    long count = 0,sum= 0,total = 0,largest=0;
    long arr[1000000];
    //cin >> t;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; // no of students
        int m; // no of relationships
        scanf("%d %d",&n,&m);
        //cin >> n >> m;
        for(long i = 0;i <= n;i++){
                arr[i] = 0;
        }
        for(int a1 = 0; a1 < m; a1++){
            
            int x;
            int y;
            cin >> x >> y;
            prevX = x;
            prevY = y;
            if(arr[x] == 0 && arr[y] == 0){
                
                largest = largest + 1;
                arr[x] = largest;
                arr[y] = largest;
                count = count + 2;
                sum = largest*count;
            }
            else if((arr[x] > 0 && arr[y] == 0) || (arr[y] > 0 && arr[x] == 0)){
                largest = largest + 1;
                arr[x] = largest;
                arr[y] = largest;
                //sum = 0;
                count++;
                sum = largest*count;

            }
            
            
            total = total + sum;
            //cout<<sum<<" "<<total<<" "<<endl;
        }
        printf("%ld",total);
    }
    return 0;
}
/*#include <map>
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

int traverse(vector<int> &arr,int x,int n){
    int sum = 0;
    for(int i = 1;i <= n;i++){
        if(arr[i] > 0){
            arr[i] = x;
            sum = sum + arr[i];
        }
       // cout<<arr[i]<<" ";
    }
   // cout<<endl;
    return sum;
}

int main(){
    int t;
    int count = 1,sum = 0,total = 0,largest=0,friends = 0;
    
    //int arr[1000000];
    cin >> t;
    //for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
        vector<int> arr(n);
        for(int i = 0;i <= n;i++){
                arr[i] = 0;
        }
        for(int a1 = 0; a1 < m; a1++){
            int x;
            int y;
            cin >> x >> y;
            if(arr[x] == 0 && arr[y] == 0){
                arr[x] = 1;
                arr[y] = 1;
                sum = 2;
                //largest = 1;
            }else if((arr[x] > 0 && arr[y] == 0) || (arr[y] > 0 && arr[x] == 0)){
                sum = 0;          
                friends = arr[x] + arr[y] + 1;
                arr[x] = 1;
                arr[y] = 1;
                sum = traverse(arr,friends,n);
            }
            total = total + sum;
            //cout<<sum<<" "<<total<<" "<<endl;
        }
        printf("%d",total);
   // }
    return 0;
}
*/