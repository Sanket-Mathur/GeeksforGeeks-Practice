// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        vector<pair<int, int>> plates(N);
        for (int i = 0; i < N; ++i) {
            plates[i] = make_pair(A[i], B[i]);
        }
        
        sort(plates.begin(), plates.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            return a.second > b.second;
        });
        
        int index = 0, coins = 0;
        while (T > 0 && index < N) {
            if (plates[index].first <= T) {
                coins += plates[index].first * plates[index].second;
                T -= plates[index].first;
            } else {
                coins += T * plates[index].second;
                T = 0;
            }
            ++index;
        }
        
        return coins;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends