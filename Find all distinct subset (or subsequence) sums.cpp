//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    unordered_set<int> sums;
	    sums.insert(0);
	    
	    for (auto i : nums) {
	        vector<int> temp(sums.begin(), sums.end());
	        for (auto j : temp) {
	            sums.insert(i + j);
	        }
	    }
	    
	    vector<int> result(sums.begin(), sums.end());
	    sort(result.begin(), result.end());
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends