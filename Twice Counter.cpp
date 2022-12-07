//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int countWords(string list[], int n)
        {
            unordered_map<string, int> cnts;
            for (int i = 0; i < n; ++i) {
                cnts[list[i]]++;
            }
            
            int result = 0;
            for (auto i : cnts) {
                if (i.second == 2) {
                    result++;
                }
            }
            
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
        int n;
        cin>>n;
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;    
        cout <<ob.countWords(list, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends