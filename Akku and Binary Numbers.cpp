//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    vector<long long> threeBitNums;
    
public:
    void precompute() {
        if (!threeBitNums.empty()) {
            return;
        }
        
        for (int i = 0; i < 63; ++i) {
            for (int j = i + 1; j < 63; ++j) {
                for (int k = j + 1; k < 63; ++k) {
                    threeBitNums.push_back((long long)pow(2, i) + pow(2, j) + pow(2, k));
                }
            }
        }
        sort(threeBitNums.begin(), threeBitNums.end());
    }
    
    long long solve(long long l, long long r) {
        long long lind = lower_bound(threeBitNums.begin(), threeBitNums.end(), l) - threeBitNums.begin();
        long long rind = upper_bound(threeBitNums.begin(), threeBitNums.end(), r) - threeBitNums.begin();
        
        return rind - lind;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends