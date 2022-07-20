//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = -1;
                    rotting(grid, i, j, n, m);
                }
            }
        }
        
        int result = INT_MAX;
        for (auto i : grid) {
            for (auto j : i) {
                if (j == 1) {
                    return -1;
                }
                result = min(result, j);
            }
        }
        
        return -result - 1;
    }
    
    void rotting(vector<vector<int>> &grid, int i, int j, int n, int m) {
        if (i > 0 && possible(grid, i - 1, j, i, j)) {
            grid[i - 1][j] = grid[i][j] - 1;
            rotting(grid, i - 1, j, n, m);
        }
        if (j > 0 && possible(grid, i, j - 1, i, j)) {
            grid[i][j - 1] = grid[i][j] - 1;
            rotting(grid, i, j - 1, n, m);
        }
        if (i < n - 1 && possible(grid, i + 1, j, i, j)) {
            grid[i + 1][j] = grid[i][j] - 1;
            rotting(grid, i + 1, j, n, m);
        }
        if (j < m - 1 && possible(grid, i, j + 1, i, j)) {
            grid[i][j + 1] = grid[i][j] - 1;
            rotting(grid, i, j + 1, n, m);
        }
    }
    
    bool possible(vector<vector<int>> &grid, int mX, int mY, int i, int j) {
        return grid[mX][mY] != 2 && grid[mX][mY] != 0 && (grid[mX][mY] == 1 || grid[mX][mY] < grid[i][j] - 1);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends