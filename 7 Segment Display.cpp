// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string S, int N) {
        int mapping[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
        
        int count = 0;
        for (int i = 0; i < N; ++i) {
            count += mapping[S[i] - '0'];
        }
        
        string res;
        for (int i = N - 1; i >= 0; --i) {
            for (int j = 0; j < 10; ++j) {
                if (count - mapping[j] >= 2 * i && count - mapping[j] <= 7 * i) {
                    res += to_string(j);
                    count -= mapping[j];
                    break;
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends