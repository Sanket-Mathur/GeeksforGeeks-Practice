//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        int i = 0, j = 0;
        int res = 0, mini = 0, maxi = 0;
        
        while (j < N) {
            if (arr[j] > arr[maxi]) {
                maxi = j;
            }
            if (arr[j] <= arr[mini]) {
                mini = j;
            }
            
            if (arr[maxi] - arr[mini] <= 1) {
                res = max(res, j - i + 1);
            } else {
                i = min(maxi, mini) + 1;
                mini = i;
                maxi = i;
                if (arr[maxi] < arr[j]) {
                    maxi = j;
                }
            }
            ++j;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends