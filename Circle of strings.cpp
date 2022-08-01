//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    int isCircle(int N, vector<string> A)
    {
        vector<int> first(26, 0), last(26, 0);
        vector<int> repeating(26, 0);
        
        for (int i = 0; i < N; ++i) {
            int len = A[i].length();
            
            if (A[i][0] == A[i][len - 1]) {
                repeating[(int)A[i][0] - 'a']++;
            } else {
                first[(int)A[i][0] - 'a']++;
                last[(int)A[i][len - 1] - 'a']++;
            }
        }
        
        bool flag = false;
        int h = 0;
        for (int i = 0; i < 26; ++i) {
            if (first[i] != last[i]) {
                return 0;
            } else if (first[i]) {
                flag = true;
            } else if (repeating[i] && !first[i]) {
                ++h;
            }
        }
        
        if (!flag) {
            return h == 1;
        }
        
        return flag && !h;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends