// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        int nCurr = 10000, dCurr = 10000;
        int nBest = 10000, dBest = 10000;
        
        double diff = 10000;
        
        double ratio = (double)n / d;
        
        while (nCurr >= 1 && dCurr >= 1) {
            while ((double)nCurr / dCurr >= ratio) {
                --nCurr;
            }
            while ((double)nCurr / dCurr < ratio) {
                --dCurr;
            }
            
            if (ratio - (double)nCurr / (dCurr + 1) < diff) {
                nBest = nCurr;
                dBest = dCurr + 1;
                diff = ratio - (double)nBest / dBest;
            }
        }
        
        return {nBest, dBest};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends