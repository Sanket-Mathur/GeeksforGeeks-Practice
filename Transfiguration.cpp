// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
        if (!checkPermutation(A, B)) {
            return -1;
        }
        
        int i = A.length() - 1, j = B.length() - 1, result = 0;
        while (i >= 0) {
            if (A[i] == B[j]) {
                --i;
                --j;
            } else {
                ++result;
                --i;
            }
        }
        
        return result;
    }
    
    bool checkPermutation(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        
        vector<int> counts(256, 0);
        for (char i : A) {
            counts[i] += 1;
        }
        
        for (char i : B) {
            counts[i] -= 1;
            if (counts[i] < 0) {
                return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends