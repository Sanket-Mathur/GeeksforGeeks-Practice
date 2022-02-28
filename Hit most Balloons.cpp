// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        int res = 0;
        for (int i = 0; i < N; ++i) {
            unordered_map<double, int> slopes;
            int coliniear = 0, vertical = 0;
            
            for (int j = 0; j < N; ++j) {
                if (arr[i].first == arr[j].first) {
                    if (arr[i].second == arr[j].second) {
                        ++coliniear;
                    }
                    ++vertical;
                    continue;
                }
                
                slopes[(double)(arr[i].second - arr[j].second) / (arr[i].first - arr[j].first)]++;
            }

            for (auto i : slopes) {
                res = max(res, coliniear + i.second);
            }
            res = max(res, vertical);
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
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends