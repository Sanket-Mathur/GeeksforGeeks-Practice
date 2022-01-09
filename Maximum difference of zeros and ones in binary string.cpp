// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    vector<int> table(S.length(), 0);
	    
	    for (int i = 0; i < S.length(); ++i) {
	        if (S[i] == '0') {
	            table[i] = i > 0 ? 1 + table[i - 1] : 1;
	        } else if (i > 0) {
	            table[i] = table[i - 1] > 0 ? table[i - 1] - 1 : 0;
	        }
	    }
	    
	    int maxElem = *max_element(table.begin(), table.end());
	    return maxElem ? maxElem : -1;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends