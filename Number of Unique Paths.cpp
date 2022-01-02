// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> table(a + 1, vector<int>(b + 1, 0));
        table[1][1] = 1;
        
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                table[i][j] += table[i - 1][j] + table[i][j - 1];
            }
        }
        
        return table[a][b];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends