//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
        int MOD = 1e9 + 7;
	public:
		int NthTerm(int n){
		    long long int result = 2;
		    for (int i = 2; i < n + 1; ++i) {
		        result = ((result * i) + 1) % MOD;
		    }
		    
		    return result;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends