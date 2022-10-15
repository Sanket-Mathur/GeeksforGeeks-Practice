//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        int sum = 0;
        multiset<int> mset(a, a + n);
        while (!mset.empty()) {
            int last = *mset.rbegin();
            sum += last;
            
            mset.erase(prev(mset.end()));
            if (mset.find(last - 1) != mset.end()) {
                mset.erase(mset.find(last - 1));
            }
        }
        
        return sum;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends