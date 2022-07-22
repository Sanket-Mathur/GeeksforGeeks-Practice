//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int maxLevel(int h,int m)
        {
            int levels = 0;
            while (h > 0 && m > 0) {
                levels++;
                
                h += 3;
                m += 2;
                
                if (h > 5 && m > 10) {
                    h -= 5;
                    m -= 10;
                } else if (h > 20) {
                    h -= 20;
                    m += 5;
                } else {
                    break;
                }
                
                levels++;
            }
            
            return levels;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends