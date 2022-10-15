//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0) {
            return -1;
        }
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> cost(n, vector<int> (m, -1));
        queue<pair<int, int>> nodes;
        
        cost[source.first][source.second] = 0;
        nodes.push(source);
        
        while (!nodes.empty() && cost[destination.first][destination.second] == -1) {
            int i = nodes.front().first, j = nodes.front().second;
            nodes.pop();
            
            if (isValid(i - 1, j, n, m) && grid[i - 1][j] == 1 && cost[i - 1][j] == -1) {
                cost[i - 1][j] = cost[i][j] + 1;
                nodes.push(make_pair(i - 1, j));
            }
            if (isValid(i + 1, j, n, m) && grid[i + 1][j] == 1 && cost[i + 1][j] == -1) {
                cost[i + 1][j] = cost[i][j] + 1;
                nodes.push(make_pair(i + 1, j));
            }
            if (isValid(i, j - 1, n, m) && grid[i][j - 1] == 1 && cost[i][j - 1] == -1) {
                cost[i][j - 1] = cost[i][j] + 1;
                nodes.push(make_pair(i, j - 1));
            }
            if (isValid(i, j + 1, n, m) && grid[i][j + 1] == 1 && cost[i][j + 1] == -1) {
                cost[i][j + 1] = cost[i][j] + 1;
                nodes.push(make_pair(i, j + 1));
            }
        }
        
        return cost[destination.first][destination.second];
    }
    
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends