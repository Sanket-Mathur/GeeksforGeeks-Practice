//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    unordered_map<string, bool> mp;
    
    public:
    bool isScramble(string S1, string S2){
        if (S1 == S2) {
            return true;
        }
        
        string key = S1 + "-" + S2;
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }
        
        for (int i = 1; i < S1.length(); ++i) {
            if ((isScramble(S1.substr(0, i), S2.substr(0, i)) && isScramble(S1.substr(i, S1.length() - i), S2.substr(i, S2.length() - i))) || 
            (isScramble(S1.substr(0, i), S2.substr(S2.length() - i, i)) && isScramble(S1.substr(i, S1.length() - i), S2.substr(0, S2.length() - i)))) {
                mp[key] = true;
                return true;
            }
        }
        
        mp[key] = false;
        return false;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends