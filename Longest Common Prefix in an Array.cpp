// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        int cnt = 0, minLen = INT_MAX;
        
        for (int i = 0; i < N; ++i) {
            minLen = min(minLen, (int)arr[i].length());
        }
        
        for (int c = 0; c < minLen; ++c) {
            bool flag = true;
            for (int i = 0; i < N - 1; ++i) {
                if (arr[i][c] != arr[i + 1][c]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
        }
        
        return cnt > 0 ? arr[0].substr(0, cnt) : "-1";
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends