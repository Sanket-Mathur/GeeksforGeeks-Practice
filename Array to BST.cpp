// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> result;
        createPreorder(nums, result, 0, nums.size() - 1);
        
        return result;
    }
    
    void createPreorder(vector<int> &nums, vector<int> &result, int low, int high) {
        if (low > high) {
            return;
        }
        
        int mid = low + (high - low) / 2;
        result.push_back(nums[mid]);
        
        createPreorder(nums, result, low, mid - 1);
        createPreorder(nums, result, mid + 1, high);
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
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends