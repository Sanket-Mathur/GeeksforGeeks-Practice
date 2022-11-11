//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr[i]]++;
        }
        
        int m1 = 0, m2 = 0;
        for (auto i : mp) {
            if (i.second > m1) {
                m2 = m1;
                m1 = i.second;
            } else if (i.second > m2) {
                m2 = i.second;
            }
        }
        for (auto i : mp) {
            if (i.second == m2) {
                return i.first;
            }
        }
        return "";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends