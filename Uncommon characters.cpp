//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            unordered_set<char> uniqueA, uniqueB;
            for (char c : A) {
                uniqueA.insert(c);
            }
            for (char c : B) {
                uniqueB.insert(c);
            }
            
            string result;
            for (char c : uniqueA) {
                if (uniqueB.find(c) == uniqueB.end()) {
                    result.push_back(c);
                } else {
                    uniqueB.erase(c);
                }
            }
            for (char c : uniqueB) {
                result.push_back(c);
            }
            
            if (result.length() == 0) {
                return "-1";
            }
            sort(result.begin(), result.end());
            return result;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends