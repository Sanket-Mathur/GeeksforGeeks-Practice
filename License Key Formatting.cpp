//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int K){
    	string result;
    	int cnt = 0;
    	for (int i = S.length() - 1; i > -1; --i) {
    	    if (S[i] == '-') {
    	        continue;
    	    }
    	    
    	    if (cnt == K) {
    	        cnt = 0;
    	        result.push_back('-');
    	    }
    	    result.push_back(toupper(S[i]));
    	    cnt++;
    	}
    	reverse(result.begin(), result.end());
    	
    	return result;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends