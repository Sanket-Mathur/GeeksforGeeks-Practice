//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        string alphabets = "abcdefghijklmnopqrstuvwxyz", result;
        int sum = 0, tmp = N;
        
        while (tmp != 0) {
            sum += tmp % 10;
            tmp = tmp / 10;
        }
        
        if (N > 26) {
            while (N > 26) {
                result += alphabets;
                N = N - 26;
            }
        }
        
        if (N % 2 == 0) {
            result += alphabets.substr(0, N / 2);
            result += alphabets.substr(26 - N / 2, N / 2);
        } else {
            if (sum % 2 == 0) {
                result += alphabets.substr(0, (N + 1) / 2);
                result += alphabets.substr(26 - (N - 1) / 2, (N - 1) / 2);
            } else {
                result += alphabets.substr(0, (N - 1) / 2);
                result += alphabets.substr(26 - (N + 1) / 2, (N + 1) / 2);
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
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends