//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr) {
        int i = 0, j = 0, maxlen = 0, cnt = 0;
        while (j < n) {
            if (arr[j] == 'O') {
                cnt++;
            }
            while (i < n && cnt > m) {
                if (arr[i] == 'O') {
                    cnt--;
                }
                i++;
            }
            
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        
        return maxlen;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends