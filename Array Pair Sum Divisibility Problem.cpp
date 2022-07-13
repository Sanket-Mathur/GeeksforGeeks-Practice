// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if (nums.size() % 2 != 0) {
            return false;
        }
        
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i] % k]++;
        }
        
        
        for (pair<int, int> item : map) {
            int num = item.first, freq = item.second;
            
            if (num == 0) {
                if (freq % 2 != 0) {
                    return false;
                }
                continue;
            }
            
            for (int i = 0; i < freq; ++i) {
                if (num == k - num) {
                    if (map[num] < 2) {
                        return false;
                    }
                    freq -= 2;
                    map[num] -= 2;
                } else {
                    if (map[k - num] <= 0) {
                        return false;
                    }
                    map[k - num]--;
                    map[num]--;
                }
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends