//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int NthTerm(int N){
		    if (N < 4) {
		        return N == 1 ? 1 : 0;
		    } else if (isPrime(N)) {
		        return 0;
		    }
		    
		    int lower = N - 1, higher = N + 1, cnt = 1;
		    while (true) {
		        if (isPrime(lower) || isPrime(higher)) {
		            return cnt;
		        }
		        
		        lower--;
		        higher++;
		        cnt++;
		    }
		}
		
		bool isPrime(int N) {
		    for (int i = 2; i < N; ++i) {
		        if (N % i == 0) {
		            return false;
		        }
		    }
		    return true;
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
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends