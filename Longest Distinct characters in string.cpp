// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    vector<bool> charCount(256, 0);
    
    int back = 0, forw = 0;
    int longestLength = 0;
    
    while (forw < S.length()) {
        if (!charCount[(int)S[forw]]) {
            charCount[(int)S[forw]] = true;
            forw++;
            
            longestLength = max(longestLength, forw - back);
        } else {
            while (charCount[(int)S[forw]]) {
                charCount[(int)S[back]] = false;
                back++;
            }
        }
    }
    
    return longestLength;
}