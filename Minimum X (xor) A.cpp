//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int aSetBits = countSetBits(a);
        int bSetBits = countSetBits(b);
        
        if (aSetBits == bSetBits) {
            return a;
        }
        
        int diff = abs(aSetBits - bSetBits);
        if (aSetBits > bSetBits) {
            for (int i = 0; i < diff; ++i) {
                a &= (a - 1);
            }
        } else {
            for (int i = 0; i < diff; ++i) {
                a |= (a + 1);
            }
        }
        
        return a;
    }
    
    int countSetBits(int n) {
        int setBits = 0;
        while (n) {
            if (n & 1) {
                setBits++;
            }
            n >>= 1;
        }
        
        return setBits;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends