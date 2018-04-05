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
    int t;
    long count = 1,sum= 0,total = 0,largest=0;
    long arr[1000000];
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n; // no of students
        int m; // no of relationships
        cin >> n >> m;
        for(long i = 0;i <= n;i++){
                arr[i] = 0;
        }
        for(int a1 = 0; a1 < m; a1++){
           
            for(long i = 1;i <= n;i++){
                //cout<<arr[i]<<" ";
                if(arr[i] > largest){
                    largest = arr[i];
                }
            }
            int x;
            int y;
            cin >> x >> y;
            if(arr[x] == 0 && arr[y] == 0){
                arr[x] = 1;
                arr[y] = 1;
                sum = 2;
                //largest = 1;
            }
            else if((arr[x] > 0 && arr[y] == 0) || (arr[y] > 0 && arr[x] == 0)){
                sum = 0;
                arr[x] = 1; arr[y] = 1;
                for(long i = 1;i <= n;i++){
                    if(arr[i] > 0){
                        //flag = true;
                        //break;
                        arr[i] = largest+1;
                        //largest = arr[i];
                    }
                    sum = arr[i] + sum;
                }
            }
            
            
            total = total + sum;
            //cout<<sum<<" "<<total<<" "<<endl;
        }
        printf("%ld",total);
    }
    return 0;
}
