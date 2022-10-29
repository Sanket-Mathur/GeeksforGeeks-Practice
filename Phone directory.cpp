//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class trie {
public:
    trie* ptr[256];
    vector<int> indeces;
    
    trie() {
        for (int i = 0; i < 256; ++i) {
            ptr[i] = NULL;
        }
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        sort(contact, contact + n);
        unordered_set<string> unique;
        
        trie* head = new trie();
        for (int i = 0; i < n; ++i) {
            if (unique.find(contact[i]) != unique.end()) {
                continue;
            }
            unique.insert(contact[i]);
            
            trie *tmp = head;
            for (auto c : contact[i]) {
                if (!tmp->ptr[(int)c]) {
                    tmp->ptr[(int)c] = new trie();
                }
                tmp->ptr[(int)c]->indeces.push_back(i);
                tmp = tmp->ptr[(int)c];
            }
        }
        
        vector<vector<string>> result(s.length(), vector<string> ());
        bool stuck = false;
        for (int i = 0; i < s.length(); ++i) {
            if (!stuck && head->ptr[(int)s[i]]) {
                head = head->ptr[(int)s[i]];
                for (auto j : head->indeces) {
                    result[i].push_back(contact[j]);
                }
            } else {
                stuck = true;
                result[i].push_back("0");
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends