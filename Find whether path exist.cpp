// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int srcX = -1, srcY = -1;
        for (int i = 0; i < grid.size() && srcX == -1; ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    srcX = i;
                    srcY = j;
                    break;
                }
            }
        }
        
        return helper(grid, srcX, srcY, grid.size(), grid[0].size());
    }
    
    bool helper(vector<vector<int>> &grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        } else if (grid[i][j] == 0) {
            return false;
        } else if (grid[i][j] == 2) {
            return true;
        }
        
        grid[i][j] = 0;
        
        if (helper(grid, i - 1, j, n, m) ||
        helper(grid, i + 1, j, n, m) || 
        helper(grid, i, j -1, n, m) ||
        helper(grid, i, j + 1, n, m)) {
            return true;
        }
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends