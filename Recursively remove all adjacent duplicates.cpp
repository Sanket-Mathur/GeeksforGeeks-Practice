// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string s){
        string result;
        
        if (s[0] != s[1]) {
            result += s[0];
        }
        
        bool changed = false;
        for (int i = 1; i < s.length(); ++i) {
            while (i < s.length() - 1 && s[i] == s[i + 1]) {
                changed = true;
                ++i;
            }
            
            if (s[i - 1] != s[i]) {
                result += s[i];
            }
        }
        
        if (!changed) {
            return result;
        }
        return remove(result);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends