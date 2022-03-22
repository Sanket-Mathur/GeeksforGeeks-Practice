// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        string res;
        
        int n = X.size() - 1, m = Y.size() - 1;
        int rem = 0;
        
        while (n >= 0 && m >= 0) {
            int result = ((int)X[n] - '0') + ((int)Y[m] - '0') + rem;
            res += (char)(result % 10 + '0');
            rem = result / 10;
            
            --n;
            --m;
        }
        while (n >= 0) {
            int result = ((int)X[n] - '0') + rem;
            res += (char)(result % 10 + '0');
            rem = result / 10;
            
            --n;
        }
        while (m >= 0) {
            int result = ((int)Y[m] - '0') + rem;
            res += (char)(result % 10 + '0');
            rem = result / 10;
            
            --m;
        }
        
        while (rem > 0) {
            res += (char)(rem % 10 + '0');
            rem /= 10;
        }
        
        int size = res.length() - 1;
        for (; size > 0 && res[size] == '0'; size--);
        res = res.substr(0, size + 1);
        
        string resrev(res.rbegin(), res.rend());
        
        return resrev;
    }
};

// { Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}  // } Driver Code Ends