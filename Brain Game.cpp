// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    bool brainGame(vector<int>nums) {
        vector<int> factors(1001, 0);
        
        for (int i = 2; i < 1001; ++i) {
            for (int j = 2 * i; j < 1001; j += i) {
                factors[j] = max(factors[j], 1 + factors[i]);
            }
        }
        
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result = result ^ factors[nums[i]];
        }
        
        return result != 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends