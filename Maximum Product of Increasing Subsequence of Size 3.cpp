// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    {
        vector<int> greatestLarger(n, -1);
        for (int i = n - 2; i >= 0; --i) {
            greatestLarger[i] = max(greatestLarger[i + 1], arr[i + 1]);
        }
        
        vector<int> result;
        set<int> st;
        st.insert(arr[0]);
        
        long long maxItem = 1;
        for (int i = 1; i < n - 1; ++i) {
            long long s = arr[i];
            auto it = st.lower_bound(s);
            --it;
            
            st.insert(s);
            long long f = *it, t = greatestLarger[i], mx = f * s * t;
            if (mx > maxItem) {
                if (f >= s || s >= t || f >= t) {
                    continue;
                }
                result = {(int)f, (int)s, (int)t};
                maxItem = mx;
            }
        }
        
        if (result.size() == 0) {
            result.push_back(-1);
        }
        
        return result;
    } 

};

// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends