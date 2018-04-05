#include <bits/stdc++.h>
using namespace std;

class triplet{
public:
    int first;
    int second;
    int diff;
    triplet(int f, int s, int d) : first(f), second(s), diff(d) { }
};

bool compare(triplet &a, triplet &b){
    return a.diff > b.diff;  // decreasing order
}

// this ques looks like dp but can be solved with the help of greedy
int findMaxAmount(int arr1[], int arr2[], int n, int x, int y){

    vector<triplet> v;
    for(int i = 0; i < n; i++){
        triplet t(arr1[i],arr2[i],abs(arr1[i]-arr2[i]));
        v.push_back(t);
    }

    sort(v.begin(),v.end(),compare);

    int i, maxAmount = 0;
    for( i = 0; i < v.size() && x > 0 && y > 0 ; i++){
        if(v[i].first > v[i].second){
            maxAmount += v[i].first;
            x--;
        }
        if(v[i].first < v[i].second){
            maxAmount += v[i].second;
            y--;
        }
        if(v[i].first == v[i].second){
            if(x > 0){
                maxAmount += v[i].first;
                x--;
            }
            else if(y > 0){
                maxAmount += v[i].second;
                y--;
            }
        }
    }

    while(i < v.size() &&  x--){
        maxAmount += v[i++].first;
    }
    while(i < v.size() &&  y--){
        maxAmount += v[i++].second;
    }

    return maxAmount;
}

int main(){

    int t;
    cin>>t;
    int arr1[10000],arr2[10000];
    while(t--){

        int n,x,y;
        cin>>n>>x>>y;

        for(int i = 0; i < n; i++){
            cin>>arr1[i];
        }
        cin.ignore(100,'\n');

        for(int i = 0; i < n; i++){
            cin>>arr2[i];
        }
        cin.ignore(100,'\n');

        if(x+y < n){
            y = n - x;
        }

        cout<<findMaxAmount(arr1,arr2,n,x,y)<<endl;
    }

    return 0;
}
