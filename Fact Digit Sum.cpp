//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    vector<int> factorial(10, 1);
	    for (int i = 2; i < 10; ++i) {
	        factorial[i] = i * factorial[i - 1];
	    }
	    
	    vector<int> result;
	    for (int i = 9; i >= 1; --i) {
	        while (N >= factorial[i]) {
	            N -= factorial[i];
	            result.push_back(i);
	        }
	    }
	    
	    reverse(result.begin(), result.end());
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
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends