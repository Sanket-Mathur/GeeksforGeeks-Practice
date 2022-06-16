// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    
	    for (int i = 0; i < V; ++i) {
	        if (color[i] == -1) {
    	        color[i] = 0;
    	        if (!dfs(V, adj, color, i)) {
    	            return false;
    	        }
	        }
	    }
	    
	    return true;
	}
	
    bool dfs(int V, vector<int> adj[], vector<int> &color, int node) {
        for (auto i : adj[node]) {
            if (color[i] != -1 && color[i] == color[node]) {
                return false;
            } else if (color[i] == -1) {
                color[i] = color[node] == 0 ? 1 : 0;
                if (!dfs(V, adj, color, i)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends