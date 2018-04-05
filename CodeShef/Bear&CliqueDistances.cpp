#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <limits>
using namespace std;
 
typedef long ll; 
typedef pair<ll,ll> isPair;
 
class Graph{
    ll V;  
    vector< pair<ll,ll> > *arr;
 
public:
 
    Graph(ll vertices){
		V = vertices;
		arr = new vector<isPair>[vertices];
	}
 
    void addEdge(ll u, ll v, ll w){
    	arr[u].push_back(make_pair(v, w));
    	arr[v].push_back(make_pair(u, w));
    }
 	void shortestPath(ll src){
 
	    priority_queue< isPair, vector <isPair> , greater<isPair> > pq;
	 	
	    long long int inf = 1000000001000001;
 
	    vector<long long int> dist;
	 	for(ll i = 0; i < V; i++){
			dist.push_back(inf);
		}
	 	
	    pq.push(make_pair(0, src));
	    dist[src] = 0;
	 
	    while (!pq.empty())
	    {
	        ll u = pq.top().second;
	        pq.pop();
	 
	        vector< pair<ll,ll> >::iterator it;
	        for (it = arr[u].begin(); it != arr[u].end(); it++)
	        {
	            ll v = (*it).first;
	            ll weight = (*it).second;
	 
	            if (dist[v] > dist[u] + weight)
	            {
	                dist[v] = dist[u] + weight;
	                pq.push(make_pair(dist[v], v));
	            }
	        }
	    }
	    for (int i = 1; i < V; i++){
	        printf("%lld ",dist[i]);
	    }
	}
};
 
int main(){
	ll t,n,k,m,s;
	ll i,j,a,b;
	ll x,c;
 
    
	scanf("%ld",&t);
	while(t--){
		scanf("%ld %ld %ld %ld %ld",&n,&k,&x,&m,&s);
		Graph g(n+1);
		
		ll src = 1, dest = src + 1, r = 0, diff = k - 2;
		for(i = 1; i <= (k*(k-1))/2; i++){
			if(i == k + r){
				src++;
				dest = src+1;
				r = r + diff;
				diff--;
			}
			g.addEdge(src,dest,x);
			dest++;
		}
		
		for(i = 0; i < m; i++){
			scanf("%ld %ld %ld",&a,&b,&c);
			g.addEdge(a,b,c);
		}
 
		g.shortestPath(s);    
	    cout<<endl;
	}
	return 0;
} 