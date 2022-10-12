//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string maxSum(string w,char x[], int b[],int n){
        int beg = 0, mbeg = 0, mend = 0, maxSum = (int)w[0], currSum = 0;
          
        unordered_map<char, int> map;
        for (int i = 0; i < n; ++i) {
            map[x[i]] = b[i];
        }
        
        for (int i = 0; i < w.length(); ++i) {
            if (map.find(w[i]) != map.end()) {
                currSum += map[w[i]];
            } else {
                currSum += (int)w[i];
            }
            if (currSum < 0) {
                beg = i + 1;
                currSum = 0;
            }
            
            if (currSum > maxSum) {
                mbeg = beg;
                mend = i;
                
                maxSum = currSum;
            }
        }
        
        return w.substr(mbeg, mend - mbeg + 1);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends