#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &grid, int i, int j, int n, int m, int lvl) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;
    
    grid[i][j] = lvl;
    
    if (j > 0 && (grid[i][j - 1] > 0 || grid[i][j - 1] < lvl - 1))
        solve(grid, i, j - 1, n, m, lvl - 1);
    if (j < m - 1 && (grid[i][j + 1] > 0 || grid[i][j + 1] < lvl - 1))
        solve(grid, i, j + 1, n, m, lvl - 1);
    if (i > 0 && (grid[i - 1][j] > 0 || grid[i - 1][j] < lvl - 1))
        solve(grid, i - 1, j, n, m, lvl - 1);
    if (i < n - 1 && (grid[i + 1][j] > 0 || grid[i + 1][j] < lvl - 1))
        solve(grid, i + 1, j, n, m, lvl - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int> (m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0)
                    solve(grid, i, j, n, m, 0);
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res = min(res, grid[i][j]);
            }
        }
        
        cout << -res << endl;
    }
    
	return 0;
}