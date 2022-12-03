//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        if (M != N) {
            return 0;
        }
        
        int p1 = 0, p2 = 0;
        while (p1 < M && p2 < N) {
            while (p1 < M && S[p1] == '#') {
                ++p1;
            }
            while (p2 < N && T[p2] == '#') {
                ++p2;
            }
            
            if (p1 == M && p2 == N) {
                return 1;
            } else if (p1 == M || p2 == N || S[p1] != T[p2]) {
                return 0;
            } else if ((S[p1] == 'A' && p2 > p1) || (S[p1] == 'B' && p2 < p1)) {
                return 0;
            }
            
            ++p1;
            ++p2;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends