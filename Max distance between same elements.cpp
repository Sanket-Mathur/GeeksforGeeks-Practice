// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        unordered_map<int, pair<int, int>> table;
        
        for (int i = 0; i < n; ++i) {
            if (table.find(arr[i]) == table.end()) {
                table[arr[i]] = {i, -1};
            }
            table[arr[i]].second = i;
        }
        
        int maxDist = -1;
        for (auto i : table) {
            maxDist = max(maxDist, i.second.second - i.second.first);
        }
        
        return maxDist;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends