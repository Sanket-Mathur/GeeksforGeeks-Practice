// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    const int MOD = 1000000007;
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    vector<vector<int>> matrix(n, vector<int> (m, 0));
	    for (vector<int> dims : blocked_cells) {
	        matrix[dims[0] - 1][dims[1] - 1] = 1;
	    }
	    
	    vector<vector<int>> dp(n, vector<int> (m, -1));
	    
	    return noOfWays(n - 1, m - 1, matrix, dp);
	}
	
	int noOfWays(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
	    if (i < 0 || j < 0 || matrix[i][j] == 1) {
	        return 0;
	    } else if (i == 0 && j == 0) {
	        return 1;
	    } else if (dp[i][j] != -1) {
	        return dp[i][j];
	    }
	    
	    int left = noOfWays(i - 1, j, matrix, dp);
	    int top = noOfWays(i, j - 1, matrix, dp);
	    
	    dp[i][j] = (left + top) % MOD;
	    return dp[i][j];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends