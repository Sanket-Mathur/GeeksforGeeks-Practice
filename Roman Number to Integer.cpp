// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    unordered_map<char, int> mapping;
    
    Solution() {
        mapping = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    }
    int romanToDecimal(string &str) {
        int res = mapping[str[0]];
        for (int i = 1; i < str.length(); ++i) {
            if (mapping[str[i - 1]] < mapping[str[i]]) {
                res += mapping[str[i]] - 2 * mapping[str[i - 1]];
            } else {
                res += mapping[str[i]];
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends