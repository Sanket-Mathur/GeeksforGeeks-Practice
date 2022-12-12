//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n);
        for (int i = 0; i < k; ++i) {
            if (a[i] < 0) {
                a[i] = -a[i];
            } else {
                if ((k - i) % 2 != 0) {
                    if (i == 0 || a[i] < a[i - 1]) {
                        a[i] = -a[i];
                    } else {
                        a[i - 1] = -a[i - 1];
                    }
                }
                break;
            }
        }
        
        long long int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends