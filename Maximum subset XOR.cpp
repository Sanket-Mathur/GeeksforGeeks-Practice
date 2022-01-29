// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubarrayXOR(int arr[], int n)
    {
        sort(arr, arr + n, [](const int &a, const int &b) -> bool {
            return a > b;
        });
        
        for (int i = 0; i < n && arr[i] != 0; ++i) {
            int maxbit = 1 << (int)log2(arr[i]);
            
            int nextmax = 0, ind;
            for (int j = 0; j < n; ++j) {
                if (j != i && (arr[j] & maxbit) != 0) {
                    arr[j] = arr[j] ^ arr[i];
                }
                
                if (j > i && arr[j] > nextmax) {
                    nextmax = arr[j];
                    ind = j;
                }
            }
            
            
            if (i < n - 1 && nextmax) {
                swap(arr[i + 1], arr[ind]);
            }
        }
        
        int res = 0;
        for (int i = 0; i < n && arr[i] != 0; ++i) {
            res ^= arr[i];
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}  // } Driver Code Ends