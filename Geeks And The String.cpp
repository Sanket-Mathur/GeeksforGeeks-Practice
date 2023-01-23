//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (!stk.empty() && stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        
        string result;
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        
        reverse(result.begin(), result.end());
        
        if (result.empty()) {
            result = "-1";
        }
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends