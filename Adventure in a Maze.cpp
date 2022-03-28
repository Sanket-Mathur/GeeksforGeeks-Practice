// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    int MOD = 1000000007;
    
    vector<int> FindWays(vector<vector<int>> &matrix){
        int n = matrix.size();
        
        vector<vector<pair<int, int>>> paths(n, vector<pair<int, int>> (n));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                paths[i][j] = {0, matrix[i][j]};
            }
        }
        paths[0][0].first = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int uP = 0, lP = 0, uS = 0, lS = 0;
                if (i > 0 && paths[i - 1][j].first > 0 && (matrix[i - 1][j] == 2 || matrix[i - 1][j] == 3)) {
                    uP = paths[i - 1][j].first;
                    uS = paths[i - 1][j].second;
                }
                if (j > 0 && paths[i][j - 1].first > 0  && (matrix[i][j - 1] == 1 || matrix[i][j - 1] == 3)) {
                    lP = paths[i][j - 1].first;
                    lS = paths[i][j - 1].second;
                }
                
                paths[i][j] = {max(paths[i][j].first, (lP + uP) % MOD), paths[i][j].second + max(lS, uS) % MOD};
            }
        }
        
        vector<int> result;
        result.push_back(paths[n - 1][n - 1].first);
        result.push_back(paths[n - 1][n - 1].first ? paths[n - 1][n - 1].second : 0);
        
        return result;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends