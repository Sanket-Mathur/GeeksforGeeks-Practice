// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k) {
        map<int, int> counter;
        for (int i = 0; i < array.size(); ++i) {
            counter[array[i]]++;
        }
        
        vector<pair<int, int>> cvec;
        for (auto i : counter) {
            cvec.push_back(i);
        }
        
        sort(cvec.begin(), cvec.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });
        
        vector<int> result;
        int count = 1;
        for (auto i : cvec) {
            if (count > k)
                break;
            
            result.push_back(i.first);
            count++;
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends