// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        set<vector<int>> subsets;
        
        sort(arr.begin(), arr.end());
        
        vector<int> st;
        powerSet(arr, st, subsets);
        
        vector<vector<int>> result;
        for (auto i : subsets) {
            result.push_back(i);
        }
        
        sort(result.begin(), result.end());
        return result;
    }
    
    void powerSet(vector<int> &arr, vector<int> st, set<vector<int>> &result, int i = -1) {
        if (i >= 0) {
            st.push_back(arr[i]);
        }
        result.insert(st);
    
        for (int j = i + 1; j < arr.size(); ++j) {
            powerSet(arr, st, result, j);
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends