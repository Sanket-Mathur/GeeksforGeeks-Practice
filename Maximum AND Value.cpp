// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int temp = res | (1 << i);
            int count = check(temp, arr, N);
            
            if (count >= 2)
                res = temp;
        }
        
        return res;
    }
    
    int check(int bit, int arr[], int N) {
        int count = 0;
        
        for (int i = 0; i < N; ++i) {
            if ((bit & arr[i]) == bit)
                ++count;
        }
        
        return count;
    }
};

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends