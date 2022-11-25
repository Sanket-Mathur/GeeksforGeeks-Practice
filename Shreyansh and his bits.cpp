//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<vector>

class Solution{
    vector<vector<long long>> dp;
public:
    Solution() {
        dp =  vector<vector<long long>> (64, vector<long long> (64, -1));
    }
    
    long long count(long long x) {
        long long total = 0, ones = 0, result = 0;
        while (x > 0) {
            if (x & 1) {
                ones++;
                result += nCr(total, ones);
            }
            total++;
            x >>= 1;
        }
        
        return result;
    }
    
    long long nCr(int n, int r) {
        if (r > n) {
            return 0;
        } else if (r == 0 || r == n) {
            return 1;
        } else if (dp[n][r] != -1) {
            return dp[n][r];
        }
        
        dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
        return dp[n][r];
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends