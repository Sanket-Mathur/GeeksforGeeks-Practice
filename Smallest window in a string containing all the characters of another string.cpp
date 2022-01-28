// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char, int> table;
        for (int i = 0; i < p.size(); ++i) {
            table[p[i]]++;
        }
        
        int i = 0, j = 0, x, y, minres = INT_MAX;
        while (j <= s.size()) {
            if (check(table)) {
                if (j - i < minres) {
                    minres = j - i;
                    x = i;
                    y = j;
                }
                
                if (table.find(s[i]) != table.end())
                    table[s[i]]++;
                i++;
            } else {
                if (table.find(s[j]) != table.end())
                    table[s[j]]--;
                j++;
            }
        }
        
        return minres == INT_MAX ? "-1" : s.substr(x, y - x);
    }
    
    bool check(unordered_map<char, int> &table) {
        for (auto i : table) {
            if (i.second > 0)
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends