// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        vector<int> counts(128, 0);
        int start = 0, end = 0;
        

        for (int i = 0; i < str.length(); ++i) {
            counts[(int)str[i]] = 1;
        }
        
        int res = INT_MAX;
        
        while (end < str.length()) {
            counts[(int)str[end++]]--;
            
            bool flag = true;
            for (int i = 0; i < 128; ++i) {
                if (counts[i] > 0) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                while (counts[(int)str[start]] < 0) {
                    counts[(int)str[start++]]++;
                }
                
                res = min(res, end - start);
            }
        }        
        
        return res;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends