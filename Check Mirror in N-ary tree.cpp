// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int, vector<int>> tree1; 
        unordered_map<int, vector<int>> tree2; 
        for (int i = 0; i < 2 * e; i += 2) {
            tree1[A[i]].push_back(A[i + 1]);
            tree2[B[i]].push_back(B[i + 1]);
        }
        
        return checkMirrorHelper(tree1, tree2, A[0]);
    }
    
    int checkMirrorHelper(unordered_map<int, vector<int>> &tree1, unordered_map<int, vector<int>> &tree2, int p) {
        if (tree1[p].empty() && tree2[p].empty()) {
            return 1;
        } else if (tree1[p].empty() || tree2[p].empty()) {
            return 0;
        } else if (tree1[p].size() != tree2[p].size()) {
            return 0;
        }
        
        int i = 0, j = tree2[p].size() - 1;
        while (i < tree1[p].size()) {
            if (tree1[p][i] == tree2[p][j]) {
                if (!checkMirrorHelper(tree1, tree2, tree1[p][i])) {
                    return 0;
                }
                ++i;
                --j;
            } else {
                return 0;
            }
        }
        
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends