//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    vector<int> PosNegPair(int a[], int n) {
        sort(a, a + n);
        
        int i = 0;
        for (; i < n && a[i] <= 0; ++i);
        
        int j = i - 1;
        vector<int> result;
        
        while (j >= 0 && i < n) {
            if (a[i] == -a[j]) {
                result.push_back(a[j--]);
                result.push_back(a[i++]);
            } else if (a[i] < -a[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> v = obj.PosNegPair(a, n);

        if (v.size() == 0) cout << "0";

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends