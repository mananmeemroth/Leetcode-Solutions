// Topo sorting using BFS(with a slght difference)
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> ans;
	    vector<int> inDegree(V, 0);	    
	    for(int i=0; i<V; i++) {
	        for(auto it : adj[i]) inDegree[it]++;
	    }	    
	    queue<int> q;	    
	    for(int i=0; i<V; i++) {
	        if(inDegree[i] == 0) q.push(i);
	    }	    
	    while(!q.empty()) {
	        
	        // Get the node
	        int node = q.front();
	        
	        // Add it to the answer
	        ans.push_back(node);
	        q.pop();
	        
	        // Traverse the neighbours
	        for(auto it : adj[node]) {
	            
	            // Decrement the in-degree
	            inDegree[it]--;
	            
	            /* Add the node to queue if 
	            its in-degree becomes zero */
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
	    
	    // Return the result
	    return ans;
    }
};
