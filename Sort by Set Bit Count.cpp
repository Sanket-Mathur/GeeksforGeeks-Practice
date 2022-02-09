// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        unordered_map<int, vector<int>> mapping;
        int maxBitCount = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int cnt = countBits(arr[i]);
            maxBitCount = max(maxBitCount, cnt);
            mapping[cnt].push_back(arr[i]);
        }
        
        int index = 0;
        while (index < n) {
            if (mapping.find(maxBitCount) != mapping.end()) {
                for (auto i : mapping[maxBitCount]) {
                    arr[index++] = i;
                }
            }
            --maxBitCount;
        }
    }
    
    static int countBits(int num) {
        int count = 0;
        while (num) {
            if (num & 1) {
                ++count;
            }
            num >>= 1;
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends