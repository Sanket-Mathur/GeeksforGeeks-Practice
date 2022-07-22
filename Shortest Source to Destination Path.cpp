//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[0][0] == 0 || A[X][Y] == 0) {
            return -1;
        }
        
        queue<pair<int, int>> q;
        int level = 0;
        vector<vector<bool>> visited(N, vector<bool> (M, false));
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        q.push({0, 0});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                pair<int, int> v = q.front();
                q.pop();
                
                for (auto dir : directions) {
                    int x = v.first + dir.first, y = v.second + dir.second;
                    if (x > N - 1 || y > M - 1 || x < 0 || y < 0) {
                        continue;
                    }
                    
                    if (x == X && y == Y) {
                        return level + 1;
                    }
                    if (A[x][y] != 0 && !visited[x][y]) {
                        q.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends