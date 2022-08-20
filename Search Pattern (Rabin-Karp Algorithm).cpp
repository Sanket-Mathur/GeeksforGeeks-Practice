//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> res;
            
            for (int i = 0; i < txt.length() - pat.length() + 1; ++i) {
                if (txt[i] == pat[0]) {
                    bool flag = true;
                    for (int j = 0, k = i; j < pat.length(); ++j, ++k) {
                        if (txt[k] != pat[j]) {
                            flag = false;
                            break;
                        }
                    }
                    
                    if (flag) {
                        res.push_back(i + 1);
                    }
                }
            }
            
            if (res.size() == 0) {
                res.push_back(-1);
            }
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends