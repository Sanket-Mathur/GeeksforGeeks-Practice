// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        string res = "";
        while (N > 0) {
            int cnt = N % 26 == 0 ? 26 : N % 26;
            
            res = (char)('A' + cnt - 1) + res;
            
            N -= cnt;
            N /= 26;
        }
        
        return res;
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
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends