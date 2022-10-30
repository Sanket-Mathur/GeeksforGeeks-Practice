//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    vector<long long int> births(n + 1);
	    births[0] = 1;
	    
	    long long int result = 1;
	    for (int i = 1; i < n; ++i) {
	        if (i >= 6) {
	            result -= births[i - 6];
	        }
	        
	        births[i] = result * 2;
	        result += births[i];
	    }
	    
	    return result;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends