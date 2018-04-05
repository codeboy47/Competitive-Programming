//	 https://practice.geeksforgeeks.org/problems/circle-of-strings/0 

#include <bits/stdc++.h>
using namespace std;


class graph{

	int V;
	unordered_map<char, vector<char> > adj;

public:

	graph() : V(0) { }
	graph(int v) : V(v) { }

	void addEgde(char u, char v){
		adj[u].push_back(v);
		V = adj.size();
	}

	bool IndegreeEqualsOutdegree(){

		unordered_map<char,int> indegree;
		unordered_map<char,int> outdegree;

		for(auto it = adj.begin(); it != adj.end(); it++ ){

			outdegree[it->first] = it->second.size();
			for(int i = 0; i < it->second.size(); i++){
				if(!indegree.count(it->second[i])){
				    indegree[it->second[i]] = 1;
				}else{
				    indegree[it->second[i]]++;
				}
			}
		}
        
        
		for(auto it = outdegree.begin(); it != outdegree.end(); it++ ){
		 
		    if(it->second != indegree[it->first]){
				return false;
			}
		}
		return true;

	}

	graph reverseGraph(){

		graph revG;
		for(auto it = adj.begin(); it != adj.end(); it++ ){
			for(int i = 0; i < it->second.size(); i++){
				revG.addEgde(it->second[i],it->first);
			}
		}

		return revG;

	}

	void dfsHelper(char ch, unordered_map<char,bool> &visited){

		visited[ch] = true;
		for(int i = 0; i < adj[ch].size(); i++){
			if(!visited.count(adj[ch][i])){
				dfsHelper(adj[ch][i],visited);
			}
		}

	}

	bool stronglyConnected(){
		
		unordered_map<char,bool> visited;

		char c = adj.begin()->first;
		dfsHelper(c,visited);

		if(visited.size() != V){
			return false;
		}		

		visited.clear();

		graph gRev = reverseGraph();

		gRev.dfsHelper(c,visited);

		if(visited.size() != V){
			return false;
		}

		return true;

	}

	/* 	To check whether this graph can have a loop which goes through all the vertices, 
		we’ll check two conditions : 
			1)	Indegree and Outdegree of each vertex should be same.
			2)	Graph should be strongly connected.
	*/
	bool circlePresent(){

        return IndegreeEqualsOutdegree() && stronglyConnected() ? true : false;
	}

	void printGraph(){
	
		for(auto it = adj.begin(); it != adj.end(); it++ ){
		    cout<<it->first<<" --> ";
			for(int i = 0; i < it->second.size(); i++){
				cout<<it->second[i]<<" ";
			}
			cout<<endl;
		}
		
	}
	
	void cleargraph(){
	    adj.clear();
	}

};


int main(){

    int t;
    graph g;
    cin>>t;
    while(t--){
    	
    	int n;
    	string s;
    	cin>>n;
    	for(int i = 0; i < n; i++){
    		cin>>s;
    		char u = s[0];
			char v = s[s.size()-1];
        	g.addEgde(u,v);
    	}

        //g.printGraph();
        cout<<g.circlePresent()<<endl;
        g.cleargraph();
 
    }

    return 0;
}