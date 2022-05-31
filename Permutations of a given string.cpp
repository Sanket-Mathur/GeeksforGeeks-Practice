// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    set<string> resultSet;
		    vector<bool> visited(S.length(), false);
		    
		    helper(S, resultSet, visited);
		    
		    vector<string> result;
		    for (auto i : resultSet) {
		        result.push_back(i);
		    }
		    
		    return result;
		}
		
		void helper(string &S, set<string> &result, vector<bool> visited, string curr = "") {
		    if (curr.length() == S.length()) {
		        result.insert(curr);
		        return;
		    }
		    
		    for (int i = 0; i < S.length(); ++i) {
		        if (!visited[i]) {
		            visited[i] = true;
		            helper(S, result, visited, curr + S[i]);
		            visited[i] = false;
		        }
		    }
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends