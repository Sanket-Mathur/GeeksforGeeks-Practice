//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i = 0, j = 0;
        
        while (i < S.length() && j < T.length()) {
            if (S[i] == T[j]) {
                ++i;
                ++j;
            } else if (isdigit(T[j])) {
                string cnt = "";
                while (j < T.length() && isdigit(T[j])) {
                    cnt += T[j];
                    ++j;
                }
                
                i += stoi(cnt);
            } else {
                return 0;
            }
        }
        
        return (int)(i == S.length() && j == T.length());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends