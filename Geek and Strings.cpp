//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Trie {
public:
    int count;
    Trie* children[26];
    
    Trie() {
        count = 0;
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        Trie* node = new Trie;
        for (int i = 0; i < N; ++i) {
            buildTrie(node, li[i], 0);
        }
        
        vector<int> result(Q);
        for (int i = 0; i < Q; ++i) {
            result[i] = traverse(node->children[query[i][0] - 'a'], query[i], 0);
        }
        
        return result;
    }
    
    void buildTrie(Trie* node, string s, int i) {
        if (i == s.length()) {
            return;
        }
        
        if (!node->children[s[i] - 'a']) {
            node->children[s[i] - 'a'] = new Trie;
        }
        node->children[s[i] - 'a']->count++;
        
        buildTrie(node->children[s[i] - 'a'], s, i + 1);
    }
    
    int traverse(Trie* node, string s, int i) {
        if (!node) {
            return 0;
        } else if (i >= s.length() - 1) {
            return node->count;
        }
        
        return traverse(node->children[s[i + 1] - 'a'], s, i + 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends