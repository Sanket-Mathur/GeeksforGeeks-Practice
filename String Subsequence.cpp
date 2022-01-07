// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(string S1, string S2){
        int count = 0;
        findingSubsequence(S1, S2, 0, 0, count);
        return count;
    }
    void findingSubsequence(string S1, string S2, int i, int j, int &count) {
        if (j == S2.length()) {
            ++count;
            return;
        } else if (i == S1.length()) {
            return;
        } 
        
        if (S1[i] == S2[j])
            findingSubsequence(S1, S2, i + 1, j + 1, count);
        findingSubsequence(S1, S2, i + 1, j, count);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends