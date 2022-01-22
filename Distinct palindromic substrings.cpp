// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        unordered_set<string> palins;
        int l, r;
        
        for (int i = 0; i < s.length(); ++i) {
            string temp(1, s[i]);
            
            palins.insert(temp);
            
            l = i - 1;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                temp = s[l] + temp + s[r];
                palins.insert(temp);
                --l;
                ++r;
            }
            
            temp = "";
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                temp = s[l] + temp + s[r];
                palins.insert(temp);
                --l;
                ++r;
            }
        }
        
        return palins.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends