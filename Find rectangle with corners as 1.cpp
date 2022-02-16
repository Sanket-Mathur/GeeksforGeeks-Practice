// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool ValidCorner(const vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix[0].size(); ++i) {
            for (int j = i + 1; j < matrix[0].size(); ++j) {
                bool prev = false;
                for (int k = 0; k < matrix.size(); ++k) {
                    if (matrix[k][i] == 1 && matrix[k][j] == 1) {
                        if (prev) {
                            return true;
                        } else {
                            prev = true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 


  // } Driver Code Ends