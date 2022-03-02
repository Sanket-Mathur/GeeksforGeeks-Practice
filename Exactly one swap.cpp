// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        long long res = 0;
        bool repeated = false;
        vector<int> counter(26, 0);
        
        for (int i = 0; i < S.length(); ++i) {
            counter[S[i] - 'a']++;
            if (counter[S[i] - 'a'] > 1) {
                repeated = true;
            }
        }
        
        for (int i = 0; i < S.length(); ++i) {
            for (int j = 0; j < 26; ++j) {
                if (j != (S[i] - 'a')) {
                    res += counter[j];
                }
            }
            
            counter[S[i] - 'a']--;
        }
        
        return repeated ? res + 1 : res;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends