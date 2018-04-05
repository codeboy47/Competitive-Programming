#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <limits>
using namespace std;
 

// below code is good if old cities i.e. k are more and new cities are less in number 
#define inf 1000000000000000 
typedef pair<int,int> isPair;
 
class Graph{
    int V;  
    vector< pair<int,int> > *arr;
 
public:
 
    Graph(int vertices){
		V = vertices;
		arr = new vector<isPair>[vertices];
	}
    void addEdge(int u, int v, int w){
    	arr[u].push_back(make_pair(v, w));
    	arr[v].push_back(make_pair(u, w));
    }
 	void shortestPath(int src,int k,int x){
 		
		set<isPair> s;
	    //priority_queue< isPair, vector <isPair> , greater<isPair> > pq;
	 	
	 	//const int inf = 2000000000;  too less for distances
	    //long long int inf = 100000000100001; dont use keyword long it assigns extra space for long
 
	    vector<long long int> dist;
	 	for(int i = 0; i <= V; i++){
			dist.push_back(inf);
		}

	 	long long int prev = inf;
	 	s.insert(make_pair(0,src));
	    //pq.push(make_pair(0, src));
	    dist[src] = 0;
	 	int count = 0;
	    while (!s.empty())
	    {
	        int u = (*s.begin()).second;
	        //int u = pq.top().second;
	        s.erase(s.begin());
	        //pq.pop();
	 		
	 		// we will traverse this k nodes if curr dist of node is less than prev distance
	 		// then update all k nodes connected to it
	        if(u <= k && prev > dist[u]){ // this is important as it act as a entry gate for k nodes
		        count++;
		        int v,pos = 0;
		        int weight;

		        for(int i = 1; i <= k + arr[u].size(); i++){
		        	if(i == u){
		        		continue;
		        	}
		        	if(i != u && i <= k){
		        		v = i;
		        		weight = x;	
		        	}if(i > k){
		        		v = arr[u][pos].first;
		        		weight = arr[u][pos++].second;
		        	}
		        	if (dist[v] > dist[u] + weight){
		                dist[v] = dist[u] + weight;
		               	s.insert(make_pair(dist[v], v));
		               	//if(v <= k){
		               		prev = min(prev,dist[v]); // this is good if k is more 
		               	//}		                
		            }
		  
		        }
		    }else{
		        vector< isPair >::iterator it;
		        for (it = arr[u].begin(); it != arr[u].end(); it++){
		            int v = (*it).first;
		            int weight = (*it).second;
		 
		            if (dist[v] > dist[u] + weight){
		                dist[v] = dist[u] + weight;
		               	s.insert(make_pair(dist[v], v));
		               	//pq.push(make_pair(dist[v], v));	        		
		            }
		        }
		    }
	    }
	    cout<<" count="<<count<<" ";
	    for (int i = 1; i < V; i++){
	        printf("%lld ",dist[i]);
	    }
	}
};

int main(){
	int t,n,k,m,s;
	int i,j,a,b;
	int x,c;
    
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d %d",&n,&k,&x,&m,&s);
		Graph g(n+1);
		for(i = 0; i < m; i++){
			scanf("%d %d %d",&a,&b,&c);
			g.addEdge(a,b,c);
		}
		g.shortestPath(s,k,x);    
	    cout<<endl;
	}
	return 0;
} 
/*	 OR but this does not pass all test cases
// this is good if old cities i.e. k are less and new cities are more
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <limits>
using namespace std;
 
#define inf 1000000000000000 
typedef pair<int,int> isPair;
 
class Graph{
    int V;  
    vector< pair<int,int> > *arr;
 
public:
 
    Graph(int vertices){
		V = vertices;
		arr = new vector<isPair>[vertices];
	}
    void addEdge(int u, int v, int w){
    	arr[u].push_back(make_pair(v, w));
    	arr[v].push_back(make_pair(u, w));
    }
 	void shortestPath(int src,int k,int x){
 		
		set<isPair> s;
	    //priority_queue< isPair, vector <isPair> , greater<isPair> > pq;
	 	
	 	//const int inf = 2000000000;  too less for distances
	    //long long int inf = 100000000100001; dont use keyword long it assigns extra space for long
 
	    vector<long long int> dist;
	 	for(int i = 0; i <= V; i++){
			dist.push_back(inf);
		}

	 	long long int prev = inf;
	 	s.insert(make_pair(0,src));
	    //pq.push(make_pair(0, src));
	    dist[src] = 0;
	 	int count = 0;
	    while (!s.empty())
	    {
	    	
	        int u = (*s.begin()).second;
	        //int u = pq.top().second;
	        s.erase(s.begin());
	        //pq.pop();
	 		
	 		// we will traverse this k nodes if curr dist of node is less than prev distance
	 		// then update all k nodes connected to it
	        if(u <= k && prev >= dist[u]){ // this is important as it act as a entry gate for k nodes
		        count++;
		        int v,pos = 0;
		        int weight;

		        for(int i = 1; i <= k + arr[u].size(); i++){
		        	if(i == u){
		        		continue;
		        	}
		        	if(i != u && i <= k){
		        		v = i;
		        		weight = x;	
		        	}if(i > k){
		        		v = arr[u][pos].first;
		        		weight = arr[u][pos++].second;
		        	}
		        	if (dist[v] > dist[u] + weight){
		                dist[v] = dist[u] + weight;
		               	s.insert(make_pair(dist[v], v));
		          		//cout<<" prev="<<prev<<" ";
		 	        }
		  
		        }
		    }else{
		        vector< isPair >::iterator it;
		        for (it = arr[u].begin(); it != arr[u].end(); it++){
		            int v = (*it).first;
		            int weight = (*it).second;
		 
		            if (dist[v] > dist[u] + weight){
		                dist[v] = dist[u] + weight;
		               	s.insert(make_pair(dist[v], v));
		               	//pq.push(make_pair(dist[v], v));
		              	if(v <= k)
		               		prev = min(prev,dist[v]);
		            }
		        }
		    }
	    }
	    cout<<" count="<<count<<" ";
	    for (int i = 1; i < V; i++){
	        printf("%lld ",dist[i]);
	    }
	}
};

int main(){
	int t,n,k,m,s;
	int i,j,a,b;
	int x,c;
    
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d %d",&n,&k,&x,&m,&s);
		Graph g(n+1);
		for(i = 0; i < m; i++){
			scanf("%d %d %d",&a,&b,&c);
			g.addEdge(a,b,c);
		}
		g.shortestPath(s,k,x);    
	    cout<<endl;
	}
	return 0;
} 
*/
