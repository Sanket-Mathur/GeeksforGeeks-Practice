//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        vector<int> seq;
        seq.push_back(H[0]);
        
        int len = 1;
        for (int i = 1; i < N; ++i) {
            if (H[i] > seq[seq.size() - 1]) {
                seq.push_back(H[i]);
                len++;
            } else {
                auto ptr = lower_bound(seq.begin(), seq.end(), H[i]);
                *ptr = H[i];
            }
        }
        
        return N - len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends