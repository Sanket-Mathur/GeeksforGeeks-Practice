// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Node {
public:
    int count;
    Node* children[26];
    
    Node() {
        count = 1;
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        Node* head = new Node();
        
        for (int i = 0; i < n; ++i) {
            Node* node = head;
            
            for (int j = 0; j < arr[i].length(); ++j) {
                int index = arr[i][j] - 'a';
                if (node->children[index] == NULL) {
                    node->children[index] = new Node();
                } else {
                    node->children[index]->count += 1;
                }
                
                node = node->children[index];
            }
        }
        
        vector<string> result;
        
        for (int i = 0; i < n; ++i) {
            Node* node = head;
            string res = "";
            
            for (int j = 0; j < arr[i].length(); ++j) {
                res += arr[i][j];
                int index = arr[i][j] - 'a';
                node = node->children[index];
                
                if (node->count == 1) {
                    break;
                }
            }
            
            result.push_back(res);
        }
        
        return result;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends