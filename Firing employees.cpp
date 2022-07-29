//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        } else if (n == 2 || n == 3) {
            return true;
        } else if(n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        
        for (int i = 5; i * i <= n; i = i + 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    int firingEmployees(vector<int> &arr, int n) {
        queue<pair<int,int>> q;
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++) {
            adj[arr[i]].push_back(i + 1);
            
            if (arr[i] == 0) {
                q.push({i + 1, 0});
            }
        }
        
        int count = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int rank = cur.first;
            int parent = cur.second;
            
            if (parent != 0 && isPrime(rank + parent)) {
                count++;
            }
            
            for (int v: adj[rank]) {
                q.push({v, parent + 1});
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends