//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        unordered_map<char, int> cnts;
        for (int i = 0; i < n; ++i) {
            cnts[a[i]]++;
        }
        
        if (max(cnts['R'], max(cnts['B'], cnts['G'])) == n) {
            return n;
        } else if (cnts['R'] % 2 == cnts['B'] % 2 && cnts['B'] % 2 == cnts['G'] % 2) {
            return 2;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends