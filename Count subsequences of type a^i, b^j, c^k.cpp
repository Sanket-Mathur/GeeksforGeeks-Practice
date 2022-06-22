// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        int MOD = 1000000007;
        
        int a = 0, b = 0, c = 0;
        for (auto ch : s) {
            if (ch == 'a') {
                a = ((2 * a) % MOD + 1) % MOD;
            } else if (ch == 'b') {
                b = ((2 * b) % MOD + a) % MOD;
            } else if (ch == 'c') {
                c = ((2 * c) % MOD + b) % MOD;
            }
        }
        
        return c;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends