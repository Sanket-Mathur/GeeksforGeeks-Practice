//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
        vector<int> chars(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            chars[(int)s[i] - 'a']++;
        }
        
        for (int i = 0; i < s.length(); ++i) {
            if (chars[(int)s[i] - 'a'] > 1) {
                return s[i];
            }
        }
        return '#';
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends