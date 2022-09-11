//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        int count = 0;
        vector<vector<bool>> visited(mat.size(), vector<bool> (mat[0].size(), false));
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                helper(mat, target, i, j, count, 0, visited);
            }
        }
        
        return count;
    }
    
    void helper(vector<vector<char>> &mat, string &target, int i, int j, int &count, int ind, vector<vector<bool>> &visited) {
        if (!isValid(mat, i, j) || mat[i][j] != target[ind] || visited[i][j]) {
            return;
        } else if (ind == target.length() - 1) {
            count++;
            return;
        }
        
        visited[i][j] = true;
        helper(mat, target, i + 1, j, count, ind + 1, visited);
        helper(mat, target, i - 1, j, count, ind + 1, visited);
        helper(mat, target, i, j + 1, count, ind + 1, visited);
        helper(mat, target, i, j - 1, count, ind + 1, visited);
        visited[i][j] = false;
    }
    
    bool isValid(vector<vector<char>> &mat, int i, int j) {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size()) {
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends