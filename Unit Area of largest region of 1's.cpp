// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    area = max(area, 1 + findarea(grid, grid.size(), grid[0].size(), i, j));
                }
            }
        }
        
        return area;
    }
    
    int findarea(vector<vector<int>> &grid, int n, int m, int i, int j) {
        grid[i][j] = 0;
        
        int area = 0;
        
        if (i > 0 && j > 0 && grid[i - 1][j - 1] == 1)
            area += 1 + findarea(grid, n, m, i - 1, j - 1);
        if (i > 0 && j < m - 1 && grid[i - 1][j + 1] == 1)
            area += 1 + findarea(grid, n, m, i - 1, j + 1);
        if (i < n - 1 && j > 0 && grid[i + 1][j - 1] == 1)
            area += 1 + findarea(grid, n, m, i + 1, j - 1);
        if (i < n - 1 && j < m - 1 && grid[i + 1][j + 1] == 1)
            area += 1 + findarea(grid, n, m, i + 1, j + 1);
        if (i > 0 && grid[i - 1][j] == 1)
            area += 1 + findarea(grid, n, m, i - 1, j);
        if (i < n - 1 && grid[i + 1][j] == 1)
            area += 1 + findarea(grid, n, m, i + 1, j);
        if (j > 0 && grid[i][j - 1] == 1)
            area += 1 + findarea(grid, n, m, i, j - 1);
        if (j < m - 1 && grid[i][j + 1] == 1)
            area += 1 + findarea(grid, n, m, i, j + 1);
        
        return area;
    }
};

// { Driver Code Starts.
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends