// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long posIntSol(string s)
    {
        int varCount = 0;
        string resString;
        bool resStarted = false;
        
        for (auto i : s) {
            if (i == '=') {
                resStarted = true;
            } else if (i != '+') {
                if (!resStarted) {
                    varCount++;
                } else {
                    resString += i;
                }
            }
        }
        
        int result = stoi(resString);
        
        return nCr(result - 1, varCount - 1);
    }
    
    long nCr(int n, int r) {
        long divisor = 1, dividend = 1;
        for (int i = 0; i < r; ++i) {
            divisor *= n--;
        }
        for (int i = r; i > 0; --i) {
            dividend *= i;
        }
        
        return divisor / dividend;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends