//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int Count(int L, int R){
		    vector<bool> isPrime(R + 1, true);
		    findPrimes(isPrime, R);
		    
		    int numPrime = 0;
		    for (int i = L; i < R + 1; ++i) {
		        if (isPrime[i]) {
		            numPrime++;
		        }
		    }
		    
		    int res = R - L + 1 - (2 * numPrime);
		    return L == 1 ? res - 1 : res;
		}
		
		void findPrimes(vector<bool> &isPrime, int R) {
		    isPrime[0] = false;
		    isPrime[1] = false;
		    
		    for (int i = 2; i < R + 1; ++i) {
		        if (isPrime[i]) {
		            for (int j = i + i; j < R + 1; j += i) {
		                isPrime[j] = false;
		            }
		        }
		    }
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends