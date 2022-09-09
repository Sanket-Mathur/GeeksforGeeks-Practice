//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	string digitsNum(int N)
	{
	    string num;
	    
	    int tmp = N;
	    while (tmp > 0) {
	        if (tmp > 9) {
	            num += "9";
	            tmp -= 9;
	        } else {
	            num += to_string(tmp);
	            tmp = 0;
	        }
	    }
	    reverse(num.begin(), num.end());
	    
	    for (int i = 0; i < N; ++i) {
	        num.push_back('0');
	    }
	    
	    return num;
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
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends