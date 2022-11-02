//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            unordered_set<int> rows, cols;
            for (int i = 0; i < k; ++i) {
                rows.insert(enemy[i][0] - 1);
                cols.insert(enemy[i][1] - 1);
            }
            
            int maxr = 0, pr = -1;
            for (int fr = 0; fr < n; ++fr) {
                if (rows.find(fr) == rows.end()) {
                    maxr = max(maxr, fr - pr);
                } else {
                    pr = fr;
                }
            }
            
            int maxc = 0, pc = -1;
            for (int fc = 0; fc < m; ++fc) {
                if (cols.find(fc) == cols.end()) {
                    maxc = max(maxc, fc - pc);
                } else {
                    pc = fc;
                }
            }
            
            return maxr * maxc;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends