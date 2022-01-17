// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int MOD = pow(10, 9) + 7;
    
    int subsequenceCount(string S, string T)
    {
        vector<vector<int>> table(T.size() + 1, vector<int> (S.size() + 1, 0));
        
        for (int j = 0; j <= S.size(); ++j) {
            table[0][j] = 1;
        }
        
        for (int i = 1; i <= T.size(); ++i) {
            for (int j = 1; j <= S.size(); ++j) {
                if (T[i - 1] == S[j - 1])
                    table[i][j] = (table[i][j - 1] + table[i - 1][j - 1]) % MOD;
                else
                    table[i][j] = table[i][j - 1] % MOD;
            }
        }
        
        return table[T.size()][S.size()];
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends