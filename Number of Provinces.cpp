//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V, false);
        int provinces = 0;
        
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                provinces++;
                visited[i] = true;
                dfs(adj, V, visited, i);
            }
        }
        
        return provinces;
    }
    
    void dfs(vector<vector<int>> &adj, int V, vector<bool> &visited, int index) {
        for (int i = 0; i < V; ++i) {
            if (adj[index][i] == 1 && !visited[i]) {
                visited[i] = true;
                dfs(adj, V, visited, i);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends