//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N){
        vector<bool> prime(N + 1, true);
        prime[0] = false;
        prime[1] = false;
        
        unordered_set<int> prms;
        
        for (int i = 2; i <= N; ++i) {
            if (prime[i]) {
                prms.insert(i);
                for (int j = 2 * i; j <= N; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        for (auto i : prms) {
            if (prms.find(N - i) != prms.end()) {
                return "Yes";
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends