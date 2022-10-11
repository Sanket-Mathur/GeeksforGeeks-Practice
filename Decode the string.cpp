//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<string> stk;
        
        for (auto i : s) {
            if (i == ']') {
                string tmp;
                while (stk.top() != "[") {
                    tmp = stk.top() + tmp;
                    stk.pop();
                }
                
                stk.pop();
                
                string num;
                while (!stk.empty() && stk.top()[0] >= '0' && stk.top()[0] <= '9') {
                    num = stk.top() + num;
                    stk.pop();
                }
                
                string res;
                for (int i = 0; i < stoi(num); ++i) {
                    res += tmp;
                }
                stk.push(res);
            } else {
                stk.push(string(1, i));
            }
        }
        
        string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
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
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends