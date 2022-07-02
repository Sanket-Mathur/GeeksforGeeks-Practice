// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    unordered_map<int, vector<int>> graph;
	    for (auto i : edges) {
	        graph[i[0]].push_back(i[1]);
	    }
	    
	    int count = 0;
	    count_path(graph, s, d, count);
	    
	    return count;
	}
	
	void count_path(unordered_map<int, vector<int>> &graph, int curr, int d, int &count) {
	    if (curr == d) {
	        count++;
	        return;
	    }
	    
	    for (auto i : graph[curr]) {
	        count_path(graph, i, d, count);
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends