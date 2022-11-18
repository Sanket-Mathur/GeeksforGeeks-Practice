//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr[i]]++;
        }
        
        string winner;
        int maxVotes = 0;
        for (auto i : mp) {
            if (i.second > maxVotes || (i.second == maxVotes && i.first < winner)) {
                winner = i.first;
                maxVotes = i.second;
            }
        }
        
        vector<string> result;
        result.push_back(winner);
        result.push_back(to_string(maxVotes));
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends