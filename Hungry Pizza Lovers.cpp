// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends


vector<int> permute(vector<vector<int>> &arr, int n){
    vector<pair<int, int>> transformed(n);
    for (int i = 0; i < n; ++i) {
        transformed[i] = make_pair(arr[i][0] + arr[i][1], i + 1);
    }
    
    sort(transformed.begin(), transformed.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = transformed[i].second;
    }
    
    return result;
}