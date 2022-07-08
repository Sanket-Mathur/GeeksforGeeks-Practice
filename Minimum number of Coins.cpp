// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
public:
    vector<int> minPartition(int N)
    {
        vector<int> result;
        int index = 0;
        
        while (N > 0) {
            if (coins[index] <= N) {
                result.push_back(coins[index]);
                N -= coins[index];
            } else {
                index++;
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends