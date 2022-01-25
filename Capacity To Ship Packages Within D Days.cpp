// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        int beg = INT_MIN, end = 0;
        for (int i = 0; i < N; ++i) {
            beg = max(beg, arr[i]);
            end += arr[i];
        }
        
        int result = end;
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            
            if (check(arr, mid, N, D)) {
                result = mid;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        
        return result;
    }
    
    bool check(int arr[], int mid, int N, int K) {
        int sum = 0, count = 1;
        for (int i = 0; i < N; ++i) {
            sum += arr[i];
            
            if (arr[i] > mid) {
                return false;
            }
            
            if (sum > mid) {
                count++;
                sum = arr[i];
            }
        }
        
        return count <= K;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends