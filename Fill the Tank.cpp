// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    long long minimum_amount(vector<vector<int>> &Edges, int num, int start, int *cap) {
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < num - 1; ++i) {
            edges[Edges[i][0] - 1].push_back(Edges[i][1] - 1);
            edges[Edges[i][1] - 1].push_back(Edges[i][0] - 1);
        }
        
        vector<bool> visited(num, false);
        visited[start - 1] = true;
        
        return helper(edges, num, start - 1, cap, visited);
    }
    
    long long helper(unordered_map<int, vector<int>> &edges, int N, int S, int *cap, vector<bool> &visited) {
        long long maxRequired = 0, count = 0; 
        
        for (auto i : edges[S]) {
            if (!visited[i]) {
                visited[i] = true;
                long long res = helper(edges, N, i, cap, visited);
                if (res == -1) {
                    return -1;
                }
                
                maxRequired = max(maxRequired, res);
                count++;
            }
        }
        
        long long result = maxRequired * count + cap[S];
        if (result > 1e18) {
            return -1;
        }
        return result;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends