//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int stepX[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int stepY[8] = {1, -1, 1, -1, 2, -2, 2, -2};
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N) {
		vector<vector<int>> board(N + 1, vector<int> (N + 1, 0));
	    queue<pair<int, int>> q;
	    
	    int tx = TargetPos[0], ty = TargetPos[1];
	    q.push({KnightPos[0], KnightPos[1]});
	    while (!q.empty()) {
	        pair<int, int> p = q.front();
	        q.pop();
	        
	        if (p.first == tx && p.second == ty) {
	            return board[tx][ty];
	        }
	        
	        for (int i = 0; i < 8; ++i) {
	            int nx = p.first + stepX[i], ny = p.second + stepY[i];
	            if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] != 0) {
	                continue;
	            }
	            
	            q.push({nx, ny});
	            board[nx][ny] = board[p.first][p.second] + 1;
	        }
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends