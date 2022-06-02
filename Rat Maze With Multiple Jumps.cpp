// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    vector<vector<int>> resultant;
    int minHops;
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	    vector<vector<int>> solution(matrix.size(), vector<int> (matrix[0].size(), 0));
	    minHops = INT_MAX;
	    
	    solution[0][0] = 1;
	    trace(matrix, 0, 0, matrix.size(), matrix[0].size(), solution, 0);
	    
	    if (minHops < INT_MAX) {
	        return resultant;
	    }
	    return vector<vector<int>> (1, vector<int> (1, -1));
	}
	
	void trace(vector<vector<int>> &matrix, int i, int j, int n, int m, vector<vector<int>> &result, int hops) {
	    if (i == n - 1 && j == m - 1) {
	        if (hops < minHops) {
	            minHops = hops;
	            resultant = result;
	        }
	        return;
	    }
	    
	    for (int x = 1; x <= matrix[i][j]; ++x) {
	        if (isSafe(matrix, i, j + x, n, m)) {
	            result[i][j + x] = 1;
	            trace(matrix, i, j + x, n, m, result, hops + x);
	            result[i][j + x] = 0;
	        }
	        if (isSafe(matrix, i + x, j, n, m)) {
	            result[i + x][j] = 1;
	            trace(matrix, i + x, j, n, m, result, hops + x);
	            result[i + x][j] = 0;
	        }
	    }
	    
	    matrix[i][j] = 0;
	}
	
	bool isSafe(vector<vector<int>> &matrix, int i, int j, int n, int m) {
	    if (i >= n || j >= m) {
	        return false;
	    } else if (matrix[i][j] > 0 || (i == n - 1 && j == m - 1)) {
	        return true;
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends