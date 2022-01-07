// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	unordered_map<string, int> memo;	

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int x = longestCommonSubsequence(str1, str2, str1.length() - 1, str2.length() - 1);
	    int m = str1.length() - x, n = str2.length() - x;
	    return m + n;
	} 
	
	int longestCommonSubsequence(string s1, string s2, int m, int n) {
	    if (m == -1 || n == -1)
	        return 0;
	    else if (memo.find(to_string(m) + "-" + to_string(n)) != memo.end())
	        return memo[to_string(m) + "-" + to_string(n)];
	    
	    int res;
	    if (s1[m] == s2[n])
	        res = 1 + longestCommonSubsequence(s1, s2, m - 1, n - 1);
	    else
	        res = max(longestCommonSubsequence(s1, s2, m, n - 1), longestCommonSubsequence(s1, s2, m - 1, n));
	    
	    memo[to_string(m) + "-" + to_string(n)] = res;
	    return res;
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends