// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        unordered_map<int, int> cntX, cntY;
        unordered_map<string, int> cntXY;
        int result = 0;
        
        for (int i = 0; i < N; ++i) {
            string s = to_string(X[i]) + ',' + to_string(Y[i]);
            result += cntX[X[i]] + cntY[Y[i]] - (2 * cntXY[s]);
            
            cntX[X[i]]++;
            cntY[Y[i]]++;
            cntXY[s]++;
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends