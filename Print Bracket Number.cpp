//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> barcketNumbers(string S)
	{
	    vector<int> result;
	    stack<int> stk;
	    int cnt = 0;
	    for (auto i : S) {
	        if (i == '(') {
	            cnt++;
	            stk.push(cnt);
	            result.push_back(stk.top());
	        } else if (i == ')') {
	            result.push_back(stk.top());
	            stk.pop();
	        }
	    }
	    
	    return result;
	}
};

//{ Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.barcketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends