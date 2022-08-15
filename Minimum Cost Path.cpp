//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> costs(n, vector<int> (n, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        costs[0][0] = grid[0][0];
        
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push(make_pair(grid[0][0], make_pair(0, 0)));
        
        while (!pq.empty()) {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            
            int dist = p.first, r = p.second.first, c = p.second.second;
            for (int i = 0; i < 4; ++i) {
                int x = dx[i] + r, y = dy[i] + c;
                if (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y]) {
                    visited[x][y] = true;
                    if (dist + grid[x][y] < costs[x][y]) {
                        costs[x][y] = dist + grid[x][y];
                        pq.push(make_pair(costs[x][y], make_pair(x, y)));
                    }
                }
            }
        }
        
        return costs[n - 1][n - 1];
    }
};

//{ Driver Code Starts.
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends