//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int> result;
        
        int row1 = 0, row2 = R - 1, col1 = 0, col2 = C - 1;
        while (row1 <= row2 && col1 <= col2) {
            for (int i = col1; i <= col2; ++i) {
                result.push_back(a[row1][i]);
            }
            row1++;
            
            for (int i = row1; i <= row2; ++i) {
                result.push_back(a[i][col2]);
            }
            col2--;
            
            if (row1 <= row2 && col1 <= col2) {
                for (int i = col2; i >= col1; --i) {
                    result.push_back(a[row2][i]);
                }
                row2--;
                
                for (int i = row2; i >= row1; --i) {
                    result.push_back(a[i][col1]);
                }
                col1++;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends