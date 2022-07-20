//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int longest = 1, start = 0;
        for (int i = 0; i < S.length(); ++i) {
            int beg = i, end = i;
            while (beg > -1 && end < S.length() && S[beg] == S[end]) {
                --beg;
                ++end;
            }
            if (longest < end - beg - 1) {
                longest = end - beg - 1;
                start = beg + 1;
            }
            
            beg = i, end = i + 1;
            while (beg > -1 && end < S.length() && S[beg] == S[end]) {
                --beg;
                ++end;
            }
            if (longest < end - beg - 1) {
                longest = end - beg - 1;
                start = beg + 1;
            }
        }
        
        return S.substr(start, longest);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends