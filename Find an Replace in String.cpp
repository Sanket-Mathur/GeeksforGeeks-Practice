// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        for (int q = Q - 1; q > -1; --q) {
            int ind = index[q];
            string src = sources[q], tar = targets[q];
            
            string orig = S.substr(ind, min(S.length() - ind, src.length()));
            if (orig == src) {
                string prefix = S.substr(0, ind);
                string suffix = S.substr(ind + src.length());
                
                S = prefix + tar + suffix;
            }
        }
        
        return S;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends