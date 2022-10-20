//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    int MOD = 1e9 + 7;
  public:
    int getSum(int X, int Y, int Z) {
        vector<vector<vector<long long>>> eS(X + 1, vector<vector<long long>> (Y + 1, vector<long long> (Z + 1, 0)));
        vector<vector<vector<long long>>> eN(X + 1, vector<vector<long long>> (Y + 1, vector<long long> (Z + 1, 0)));
        long long result = 0;
        
        eN[0][0][0] = 1;
        
        for (int i = 0; i < X + 1; ++i) {
            for (int j = 0; j < Y + 1; ++j) {
                for (int k = 0; k < Z + 1; ++k) {
                    if (i > 0) {
                        eS[i][j][k] += (eS[i - 1][j][k] * 10 + 4 * eN[i - 1][j][k]) % MOD;
                        eN[i][j][k] += eN[i - 1][j][k] % MOD;
                    }
                    if (j > 0) {
                        eS[i][j][k] += (eS[i][j - 1][k] * 10 + 5 * eN[i][j - 1][k]) % MOD;
                        eN[i][j][k] += eN[i][j - 1][k] % MOD;
                    }
                    if (k > 0) {
                        eS[i][j][k] += (eS[i][j][k - 1] * 10 + 6 * eN[i][j][k - 1]) % MOD;
                        eN[i][j][k] += eN[i][j][k - 1] % MOD;
                    }
                    
                    result = (result + eS[i][j][k]) % MOD;
                }
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends