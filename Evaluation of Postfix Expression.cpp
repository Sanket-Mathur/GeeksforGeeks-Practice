//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> S;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                S.push(stoi(string (1, c)));
            } else {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                if (c == '+') {
                    S.push(a + b);
                } else if (c == '-') {
                    S.push(b - a);
                } else if (c == '*') {
                    S.push(a * b);
                } else if (c == '/') {
                    S.push(b / a);
                }
            }
        }
        
        return S.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends