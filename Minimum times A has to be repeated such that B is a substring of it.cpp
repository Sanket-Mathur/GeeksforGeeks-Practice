// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        int bpos, apos;
        
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] == B[0]) {
                for (bpos = 0, apos = i; bpos < B.length() && apos < A.length() && A[apos] == B[bpos]; ++bpos, ++apos);
                
                if (bpos == B.length()) {
                    return 1;
                } else if (apos == A.length()) {
                    break;
                }
            }
        }
        
        if (apos != A.length()) {
            return -1;
        }
        
        int res = 2;
        apos = 0;
        while (bpos < B.length()) {
            if (B[bpos] != A[apos]) {
                return -1;
            }
            ++bpos;
            ++apos;
            
            if (apos == A.length() && bpos != B.length()) {
                ++res;
                apos = 0;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends