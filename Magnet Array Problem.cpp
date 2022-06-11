// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void nullPoints(int n, double magnets[], double getAnswer[])
    {
        int index = 0;
        
        for (int i = 1; i < n; ++i) {
            double low = magnets[i - 1], high = magnets[i], mid;
            
            while (low <= high) {
                mid = low + (high - low) / 2;
                
                double lForce = 0, rForce = 0;
                for (int j = 0; j < i; ++j) {
                    lForce += 1 / (mid - magnets[j]);
                }
                for (int j = i; j < n; ++j) {
                    rForce += 1 / (magnets[j] - mid);
                }
                
                if (abs(lForce - rForce) < 0.000001) {
                    break;
                } else if (lForce < rForce) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            
            getAnswer[index++] = mid;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends