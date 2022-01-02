// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    int MOD = 1000000007;
    
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        int size = s.length();
        vector<long long> comb(size, 0);
        
        comb[0] = s[0] - '0';
        
        long long sum = comb[0];
        
        for (int i = 1; i < size; ++i) {
            comb[i] = ((i + 1) * (s[i] - '0') + 10 * comb[i - 1]) % MOD;
            sum = (sum + comb[i]) % MOD;
        }
        
        return sum % MOD;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends