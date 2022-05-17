// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

    vector<string> permutation(string S){
        vector<string> result;
        findPermutations(S, result, 0, "");
        
        return result;
    }
    
    void findPermutations(string S, vector<string> &result, int index, string curr) {
        if (index == 0) {
            findPermutations(S, result, index + 1, curr + S[index]);
            return;
        } else if (index == S.length()) {
            result.push_back(curr);
            return;
        }
        
        if (curr[curr.length() - 1] != ' ') {
            findPermutations(S, result, index, curr + " ");
        }
        findPermutations(S, result, index + 1, curr + S[index]);
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends