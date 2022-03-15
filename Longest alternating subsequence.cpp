// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums) {
		    if (nums.size() == 1) {
		        return 1;
		    }
		    
		    int i = 0, len = 2;
		    for (int j = 2; j < nums.size(); ++j) {
		        if ((nums[i] < nums[j - 1] && nums[j - 1] > nums[j]) || 
                (nums[i] > nums[j - 1] && nums[j - 1] < nums[j])) {
		            i = j - 1;
		            len++;
		        }
		    }
		    
		    return len;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends