// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum) {
        unordered_map<int, bool> memo;
        return helper(arr, sum, 0, N - 1, memo);
    }
    
    bool helper(int arr[], int sum, int i, int j, unordered_map<int, bool> &memo) {
        if (sum == 0) {
            return true;
        } else if (i > j) {
            return false;
        } else if (memo.find(sum) != memo.end()) {
            return memo[sum];
        }
        
        while (i <= j) {
            if (arr[i] <= sum) {
                if (helper(arr, sum - arr[i], i + 1, j, memo)) {
                    memo[sum] = true;
                    return true;
                }
            }
            ++i;
        }
        
        memo[sum] = false;
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends