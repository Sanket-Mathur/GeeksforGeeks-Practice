//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        vector<int> result;
        stack<int> st;
        
        for (int i = 1; i < N; ++i) {
            if (arr[i - 1] > arr[i]) {
                st.push(arr[i - 1]);
            } else {
                bool isValid = false;
                while (!st.empty()) {
                    if (arr[i] > st.top()) {
                        st.pop();
                        isValid = true;
                    } else {
                        break;
                    }
                }
                
                if (isValid) {
                    result.push_back(arr[i - 1]);
                }
            }
        }
        
        result.push_back(arr[N - 1]);
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends