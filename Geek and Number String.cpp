//{ Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    unordered_set<string> possible = {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"};
    int minLength(string s, int n) {
        stack<char> stk;
        int len = n;
        for (int i = 0; i < n; ++i) {
            if (!stk.empty() && possible.find(string(1, stk.top()) + s[i]) != possible.end()) {
                stk.pop();
                len -= 2;
            } else {
                stk.push(s[i]);
            }
        }
        
        return len;
    } 
};


//{ Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends