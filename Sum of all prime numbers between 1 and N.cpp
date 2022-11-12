//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
   	long long int prime_Sum(int n){
   	    vector<bool> prime(n + 2, true);
   	    prime[0] = false;
   	    prime[1] = false;
   	    
   	    for (int i = 2; i <= n; ++i) {
   	        if (prime[i]) {
   	            for (int j = i * 2; j <= n; j += i) {
   	                prime[j] = false;
   	            }
   	        }
   	    }
   	    
   	    long long sum = 0;
   	    for (int i = 2; i <= n; ++i) {
   	        if (prime[i]) {
   	            sum += i;
   	        }
   	    }
   	    return sum;
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		long long int ans = ob.prime_Sum(n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends